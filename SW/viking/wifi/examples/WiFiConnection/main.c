#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "lvgl.h"
#include "pico/binary_info.h"
#include "vikingLcdDriver.h"

#include "hardware/uart.h"
#include "hardware/irq.h"
#include <string.h>

#define LCD_BUFFER_SIZE (WIDTH * HEIGHT)
lv_obj_t *label;

#define ESP32_UART_ID uart0
#define BAUD_RATE 115200
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY UART_PARITY_NONE
#define ESP32_UART_TX_PIN 16
#define ESP32_UART_RX_PIN 17
#define UART_BUFFER_SIZE 1000
static int chars_rxed = 0;
bool isRxCompleted = false;
char receivedChars[UART_BUFFER_SIZE] = {0};
int bytes_read = 0;
#define TOTALCOMMANDS 5
int commandCnt = 0;

typedef enum _STATE
{
    IDLE,
    TX_AVALIABLE,
    RX_PENDING,
    RX_AVALIABLE,
} STATE;
volatile STATE state = IDLE;
char commands[TOTALCOMMANDS][100] = {
    "AT\r\n", //"AT+GMR\r\n",
    "AT+RESTORE\r\n",
    "AT+CWMODE=1\r\n",                                         // Classic Bluetooth initialization. / Response -> OK
    "AT+CWJAP=\"AlpElectronix\",\"12345678\"\r\n", // Classic Bluetooth SPP profile initialization, and the role is set to slave. / Response -> OK
    "AT\r\n"};

#define MAX_LOG_LENGTH 1000
char myLog[MAX_LOG_LENGTH] = {0};

void replaceCRLFWithSpace(char *str)
{
    int readIndex = 0;
    int writeIndex = 0;
    int length = strlen(str);

    while (readIndex < length)
    {
        // Check for "\r\n"
        if (str[readIndex] == '\r' && str[readIndex + 1] == '\n')
        {
            str[writeIndex] = ' '; // Replace CRLF with a space
            readIndex += 2;        // Skip both characters
            writeIndex++;
        }
        else
        {
            // Copy the character to the new position
            str[writeIndex] = str[readIndex];
            readIndex++;
            writeIndex++;
        }
    }

    // Null-terminate the new string after removing "\r\n" and replacing with spaces
    str[writeIndex] = '\0';
}

void autoScrollLabel(void)
{
    lv_coord_t y = lv_obj_get_self_height(label);

    // If the object content is big enough to scroll
    if (y > lv_obj_get_height(label))
    {
        // Calculate the "out of view" y size
        lv_coord_t outOfView = y - lv_obj_get_height(label);

        lv_coord_t currScrollPos = lv_obj_get_scroll_y(label);

        if (outOfView > currScrollPos)
        {
            // Calculate the difference between the required scroll pos and the current scroll pos
            lv_coord_t differenceToScroll = -(outOfView - currScrollPos);

            // this will bring the bottom of the table into view
            lv_obj_scroll_by(label, 0, differenceToScroll, LV_ANIM_OFF);
        }
    }

    return;
}

void add_log_message(char *message)
{
    char *tempStr = (char *)malloc(sizeof(message) * sizeof(char));
    strcpy(tempStr, message);
    replaceCRLFWithSpace(tempStr);
    if (!(strcmp(message, LV_SYMBOL_RIGHT) == 0 || strcmp(message, LV_SYMBOL_LEFT) == 0))
        strcat(tempStr, "\n");
    strncat(myLog, tempStr, MAX_LOG_LENGTH - 1);
    lv_label_set_text(label, myLog);
    autoScrollLabel();
    free(tempStr);
}

void clearRXParameters()
{
    memset(receivedChars, 0, sizeof(receivedChars));
    chars_rxed = 0;
}
void processReceivedData()
{
    add_log_message(LV_SYMBOL_LEFT);
    add_log_message(receivedChars);

    if (strstr(receivedChars, "OK") || strstr(receivedChars, "OK\n"))
    {
        isRxCompleted = true;
    }
    else if (strstr(receivedChars, "ERROR"))
    {
        if (commandCnt > 0)
        {
            commandCnt--;
            isRxCompleted = true;
        }
    }

    clearRXParameters();
}

void on_uart_rx()
{
    while (uart_is_readable(ESP32_UART_ID))
    {
        receivedChars[chars_rxed++] = uart_getc(ESP32_UART_ID);
    }
}

// State Ops
void idleOps()
{
    if (commandCnt < TOTALCOMMANDS)
    {
        state = TX_AVALIABLE;
    }
}
void txAvailableOps()
{
    add_log_message("--------------------");
    add_log_message(LV_SYMBOL_RIGHT);
    add_log_message(commands[commandCnt]);
    uart_puts(ESP32_UART_ID, commands[commandCnt]);
    commandCnt++;
    state = RX_PENDING;
}
void rxPendingOps()
{
    // Waited for timer interrupt and collected all received characters.
    state = RX_AVALIABLE;
}
void rxAvailableOps()
{
    processReceivedData();
    if (isRxCompleted)
    {
        isRxCompleted = false;
    }
    state = IDLE;
}
void _3sOps()
{
    switch (state)
    {
    case IDLE:
        idleOps();
        break;
    case TX_AVALIABLE:
        txAvailableOps();
        break;
    case RX_PENDING:
        rxPendingOps();
        break;
    case RX_AVALIABLE:
        rxAvailableOps();
        break;

    default:
        break;
    }
}

volatile bool _3sElapsed = true;
struct repeating_timer _3sTimer;
bool _3sTimerCallBack(struct repeating_timer *t)
{
    _3sElapsed = true;
    return true;
}

//---------------------------------------------------------------

void customBacklightCallbackFunction()
{
    pwm_clear_irq(pwm_gpio_to_slice_num(BACKLIGHT));
    // Optional Callback Function
}

void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    int32_t x, y;
    lcdSetCursor(0, 0);            // Set Cursor to (0,0) pixel
    sendLcdCommand(0x2c, NULL, 0); // RAMWR (2Ch): Memory Write
    setLcdMode(DATA_MODE);

    for (y = area->y1; y <= area->y2; y++)
    {
        for (x = area->x1; x <= area->x2; x++)
        {
            lv_color16_t c16;
            c16.full = lv_color_to16(*color_p);
            sendLcdData(c16.full >> 8);
            sendLcdData(c16.full);
            color_p++;
        }
    }

    lv_disp_flush_ready(disp_drv);
}

bool repeating_timer_callback(struct repeating_timer *t)
{
    lv_tick_inc(1);
    return true;
}

void uartInit()
{
    uart_init(ESP32_UART_ID, 2400);
    gpio_set_function(ESP32_UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(ESP32_UART_RX_PIN, GPIO_FUNC_UART);
    int __unused actual2 = uart_set_baudrate(ESP32_UART_ID, BAUD_RATE);
    uart_set_hw_flow(ESP32_UART_ID, false, false);
    uart_set_format(ESP32_UART_ID, DATA_BITS, STOP_BITS, PARITY);
    int UART_IRQ = (ESP32_UART_ID == uart1 ? UART1_IRQ : UART0_IRQ);
    irq_set_exclusive_handler(UART_IRQ, on_uart_rx);
    irq_set_enabled(UART_IRQ, true);
    uart_set_irq_enables(ESP32_UART_ID, true, false);
    add_repeating_timer_ms(-3000, _3sTimerCallBack, NULL, &_3sTimer);
}

int main()
{
    stdio_init_all();
    sleep_ms(1000);
    uartInit();
    lcdInit();
    backLightInit(customBacklightCallbackFunction);
    setBackLightPower(80);

    lv_init();

    static lv_disp_draw_buf_t disp_buf;
    static lv_color_t buf_1[LCD_BUFFER_SIZE];
    lv_disp_draw_buf_init(&disp_buf, buf_1, NULL, LCD_BUFFER_SIZE);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.hor_res = WIDTH;
    disp_drv.ver_res = HEIGHT;

    lv_disp_drv_register(&disp_drv);

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_opa(&style, LV_OPA_100);
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_text_color(&style, lv_color_black());

    label = lv_label_create(lv_scr_act());
    lv_obj_remove_style_all(label);
    lv_obj_add_style(label, &style, 0);
    lv_obj_set_pos(label, 0, 0);
    lv_obj_set_size(label, WIDTH, HEIGHT);
    lv_label_set_text(label, myLog);

    repeating_timer_t myTimer;
    add_repeating_timer_ms(1, repeating_timer_callback, NULL, &myTimer);

    while (true)
    {
        lv_task_handler();
        if (_3sElapsed)
        {
            _3sElapsed = false;
            _3sOps();
        }
    }

    return 0;
}
