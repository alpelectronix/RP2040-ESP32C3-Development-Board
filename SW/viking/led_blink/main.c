#include "pico/stdlib.h"
#include <stdio.h>

#define VIKING_LED_PIN 22
int main()
{
    const uint LED_PIN = VIKING_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true)
    {
        gpio_put(LED_PIN, 1);
        sleep_ms(50);
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    }
}
