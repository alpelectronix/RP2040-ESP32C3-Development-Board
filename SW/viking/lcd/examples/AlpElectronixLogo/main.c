#include <stdlib.h>
#include "pico/stdlib.h"
#include <stdio.h>

#include "../../core/vikingLcdDriver.h"
#include "AlpElectronixLogo.h"

void customBacklightCallbackFunction()
{
    static int backLightPower = 0;
    static bool going_up = true;
    // Clear the interrupt flag that brought us here
    pwm_clear_irq(pwm_gpio_to_slice_num(BACKLIGHT));

    if (going_up)
    {
        ++backLightPower;
        if (backLightPower > 100)
        {
            backLightPower = 100;
            going_up = false;
        }
    }
    else
    {
        --backLightPower;
        if (backLightPower < 0)
        {
            backLightPower = 0;
            going_up = true;
        }
    }

    setBackLightPower(backLightPower);
}

int main()
{
    lcdInit();
    backLightInit(customBacklightCallbackFunction);
    setBackLightPower(100);

    bool isRandomColor = false;
    while (1)
    {
        // Set Cursor to (0,0) pixel
        lcdSetCursor(0, 0);

        // RAMWR (2Ch): Memory Write
        sendLcdCommand(0x2c, NULL, 0);

        setLcdMode(DATA_MODE);

        int num_pixels = WIDTH * HEIGHT;
        uint16_t randomColor = rand() % 0xffff;

        for (int i = 0; i < num_pixels; i++)
        {
            if (isRandomColor)
            {
                sendLcdData(randomColor >> 8);
                sendLcdData(randomColor);
            }
            else
            {
                sendLcdData(AlpElectronixLogo[i] >> 8);
                sendLcdData(AlpElectronixLogo[i]);
            }

            sleep_us(5);
        }
        isRandomColor = !isRandomColor;
    }
}
