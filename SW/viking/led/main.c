#include "pico/stdlib.h"
#include <stdio.h>

#define VIKING_LED_PIN 22
int main()
{
    gpio_init(VIKING_LED_PIN);
    gpio_set_dir(VIKING_LED_PIN, GPIO_OUT);
    while (true)
    {
        gpio_put(VIKING_LED_PIN, 1);
        sleep_ms(50);
        gpio_put(VIKING_LED_PIN, 0);
        sleep_ms(1000);
    }
}
