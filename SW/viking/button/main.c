#include "pico/stdlib.h"
#include <stdio.h>

#define VIKING_LED_PIN 22
#define BUTTON_UP_PIN 20
#define BUTTON_DOWN_PIN 19

int main()
{
    stdio_init_all();

    gpio_init(BUTTON_UP_PIN);
    gpio_set_dir(BUTTON_UP_PIN, GPIO_IN);
    gpio_init(BUTTON_DOWN_PIN);
    gpio_set_dir(BUTTON_DOWN_PIN, GPIO_IN);

    gpio_init(VIKING_LED_PIN);
    gpio_set_dir(VIKING_LED_PIN, GPIO_OUT);
    gpio_put(VIKING_LED_PIN, 1);

    while (true)
    {
        if (gpio_get(BUTTON_UP_PIN) == false)
        {
            gpio_put(VIKING_LED_PIN, 1);
        }
        else if (gpio_get(BUTTON_DOWN_PIN) == false)
        {
            gpio_put(VIKING_LED_PIN, 0);
        }
    }
}
