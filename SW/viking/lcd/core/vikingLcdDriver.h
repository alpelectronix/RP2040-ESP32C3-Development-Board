#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "pico/time.h"
#include "hardware/gpio.h"

#ifndef _VIKING_LCD_H_
#define _VIKING_LCD_H_

// Product: LCD 1.90″ 170 * 320 IPS ST7789V2 16.7M 16 Bit 39 Pin
// Link: https://alpelectronix.com/product/tft-displays/lcd-19170320-st7789v2/

typedef enum _LCD_CONFIG
{
    RESET = 23,     // GPIO23
    DATA0 = 0,      // GPIO0
    DATA1 = 1,      // GPIO1
    DATA2 = 2,      // GPIO2
    DATA3 = 3,      // GPIO3
    DATA4 = 4,      // GPIO4
    DATA5 = 5,      // GPIO5
    DATA6 = 6,      // GPIO6
    DATA7 = 7,      // GPIO7
    WRITE = 10,     // GPIO10
    READ = 9,       // GPIO9
    DC = 8,         // GPIO8
    BACKLIGHT = 28, // GPIO28
    XSHIFT = 35,
    WIDTH = 170,
    HEIGHT = 320
} LCD_CONFIG;

typedef enum _LCD_MODE
{
    COMMAND_MODE = 0,
    DATA_MODE = 1,
} LCD_MODE;

typedef union
{
    struct
    {
        unsigned int d0 : 1;
        unsigned int d1 : 1;
        unsigned int d2 : 1;
        unsigned int d3 : 1;
        unsigned int d4 : 1;
        unsigned int d5 : 1;
        unsigned int d6 : 1;
        unsigned int d7 : 1;
    };
    uint8_t data;
} LCD_DATA;

void backLightInit();
void lcdInit();
void setLcdMode(LCD_MODE mode);
void lcdSetCursor(uint16_t x, uint16_t y);
void sendLcdData(uint8_t data);
void sendLcdCommand(uint8_t cmd, uint8_t *data, size_t len);
void setBackLightPower(uint8_t percentage);

#endif
