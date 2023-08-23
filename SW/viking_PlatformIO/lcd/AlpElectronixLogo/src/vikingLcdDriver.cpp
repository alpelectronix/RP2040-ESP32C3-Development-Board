#include "vikingLcdDriver.h"
#include <Arduino.h>

void setBackLightPower(uint8_t percentage)
{
    uint8_t value;
    if (percentage < 0)
    {
        value = 0;
    }
    else if (percentage > 100)
    {
        value = 100;
    }
    else
    {
        value = percentage;
    }

    pwm_set_gpio_level(BACKLIGHT, (value * 2) * (value * 2));
}

void backLightInit(void (*callBackFunction)())
{
    gpio_set_function(BACKLIGHT, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BACKLIGHT);

    pwm_clear_irq(slice_num);
    pwm_set_irq_enabled(slice_num, true);
    irq_set_exclusive_handler(PWM_IRQ_WRAP, callBackFunction);
    irq_set_enabled(PWM_IRQ_WRAP, true);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 32.f);
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(BACKLIGHT, 100 * 100);
}

void setLcdMode(LCD_MODE mode)
{
    sleep_us(1);
    gpio_put(DC, mode);
    sleep_us(1);
}


void sendLcdData(uint8_t data)
{
    //volatile LCD_DATA tempData;
    //tempData.data = data;

    sleep_us(1);
    gpio_put(WRITE, 1);

//TODO    Change to Paralel write at once!     
//        gpio_set_mask(mask);
//        gpio_clr_mask(~mask);
// Test it

    gpio_set_mask(data & 0x000000FF);
    gpio_clr_mask((~data) & 0x000000FF); 

 /*   gpio_put(DATA0, tempData.d0);
    gpio_put(DATA1, tempData.d1);
    gpio_put(DATA2, tempData.d2);
    gpio_put(DATA3, tempData.d3);
    gpio_put(DATA4, tempData.d4);
    gpio_put(DATA5, tempData.d5);
    gpio_put(DATA6, tempData.d6);
    gpio_put(DATA7, tempData.d7);
*/
    sleep_us(1);
    gpio_put(WRITE, 0);
    sleep_us(1);
    gpio_put(WRITE, 1);
    sleep_us(1);
}
void sendLcdCommand(uint8_t cmd, uint8_t *data, size_t len)
{
    setLcdMode(COMMAND_MODE);
    sendLcdData(cmd);

    if (len)
    {
        setLcdMode(DATA_MODE);

        for (size_t i = 0; i < len; i++)
        {
            uint8_t tempData = data[i];
            sendLcdData(tempData);
        }
    }

    setLcdMode(DATA_MODE);
}

void st7789_caset_parallel(uint16_t xs, uint16_t xe)
{
    uint8_t data[] = {
        xs >> 8,
        xs & 0xff,
        xe >> 8,
        xe & 0xff,
    };

    // CASET (2Ah): Column Address Set
    sendLcdCommand(0x2a, data, sizeof(data));
}

void st7789_raset_parallel(uint16_t ys, uint16_t ye)
{
    uint8_t data[] = {
        ys >> 8,
        ys & 0xff,
        ye >> 8,
        ye & 0xff,
    };

    // RASET (2Bh): Row Address Set
    sendLcdCommand(0x2b, data, sizeof(data));
}

void lcdInit()
{

    pinMode(RESET, OUTPUT);
    pinMode(DATA0, OUTPUT);
    pinMode(DATA1, OUTPUT);
    pinMode(DATA2, OUTPUT);
    pinMode(DATA3, OUTPUT);
    pinMode(DATA4, OUTPUT);
    pinMode(DATA5, OUTPUT);
    pinMode(DATA6, OUTPUT);
    pinMode(DATA7, OUTPUT);
    pinMode(WRITE, OUTPUT);
    pinMode(READ, OUTPUT);
    pinMode(DC, OUTPUT);

    digitalWrite(RESET, HIGH);
    digitalWrite(WRITE, HIGH);
    digitalWrite(READ, HIGH);
    digitalWrite(DC, HIGH);

    sleep_ms(100);

    // SWRESET (01h): Software Reset
    sendLcdCommand(0x01, NULL, 0);
    sleep_ms(150);

    // SLPOUT (11h): Sleep Out
    sendLcdCommand(0x11, NULL, 0);
    sleep_ms(50);

    // COLMOD (3Ah): Interface Pixel Format
    // - RGB interface color format     =65K of RGB interface
    // - Control interface color format = 16bit/pixel
    uint8_t data_COLMOD[] = {0x05};
    sendLcdCommand(0x3a, data_COLMOD, sizeof(data_COLMOD) / sizeof(data_COLMOD[0]));
    sleep_ms(10);

    // MADCTL (36h): Memory Data Access Control
    // - Page Address Order            = Top to Bottom
    // - Column Address Order          = Right to Left
    // - Page/Column Order             = Reverse Mode
    // - Line Address Order            = LCD Refresh Top to Bottom
    // - RGB/BGR Order                 = RGB
    // - Display Data Latch Data Order = LCD Refresh Left to Right
    uint8_t data_MADCTL[] = {0x60};
    sendLcdCommand(0x36, data_MADCTL, sizeof(data_MADCTL) / sizeof(data_MADCTL[0]));

    st7789_caset_parallel(0, WIDTH - 1);
    st7789_raset_parallel(YSHIFT, HEIGHT + YSHIFT - 1);

    // INVON (21h): Display Inversion On
    sendLcdCommand(0x21, NULL, 0);
    sleep_ms(10);

    // NORON (13h): Normal Display Mode On
    sendLcdCommand(0x13, NULL, 0);
    sleep_ms(10);

    // DISPON (29h): Display On
    sendLcdCommand(0x29, NULL, 0);
    sleep_ms(10);
}

void lcdSetCursor(uint16_t x, uint16_t y)
{
    st7789_caset_parallel(x, WIDTH - 1);
    st7789_raset_parallel(y + YSHIFT, HEIGHT + YSHIFT - 1);
}