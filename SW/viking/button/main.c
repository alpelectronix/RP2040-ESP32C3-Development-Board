#include "pico/stdlib.h"
#include <stdio.h>

#define VIKING_LED_PIN 22
#define BUTTON_UP_PIN 20
#define BUTTON_DOWN_PIN 19

// Interrupt Callback function
void gpio_callback(uint gpio, uint32_t events) {


    // if(gpio_get(VIKING_LED_PIN) == 1)
    // gpio_put(VIKING_LED_PIN, 0);
    // else 
    // gpio_put(VIKING_LED_PIN, 1);

    // if(gpio == BUTTON_UP_PIN){
    //     gpio_put(VIKING_LED_PIN, 0);}
    // if(gpio == BUTTON_DOWN_PIN){
    //     gpio_put(VIKING_LED_PIN, 1);}

    // toggle the LED Pin
    gpio_xor_mask((1ul << VIKING_LED_PIN));
}

int main()
{
    stdio_init_all();

    gpio_init(BUTTON_UP_PIN);
    gpio_set_dir(BUTTON_UP_PIN, GPIO_IN);
    gpio_init(BUTTON_DOWN_PIN);
    gpio_set_dir(BUTTON_DOWN_PIN, GPIO_IN);

    gpio_init(VIKING_LED_PIN);
    gpio_set_dir(VIKING_LED_PIN, GPIO_OUT);
    gpio_put(VIKING_LED_PIN, 0);

    // Set the Interrupt for each pin one by one, doesnt support multi pin at once.
    gpio_set_irq_enabled_with_callback(BUTTON_UP_PIN ,GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    gpio_set_irq_enabled_with_callback(BUTTON_DOWN_PIN,GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true)
    {
/*         if (gpio_get(BUTTON_UP_PIN) == false)
        {
            gpio_put(VIKING_LED_PIN, 1);
        }
        else if (gpio_get(BUTTON_DOWN_PIN) == false)
        {
            gpio_put(VIKING_LED_PIN, 0);
        } */
    }
}

