#include "HAL_SLG46826.h"


void SLD46826_gpioInit (void){

    // I2C Initialisation. Using it at 400Khz.
    i2c_init(I2C_INSTANCE, 400*1000);
    
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
}

uint8_t SLG_I2Csend(uint8_t data){

    return i2c_write_blocking_until(I2C_INSTANCE, DEVICE_ADDRESS, &data,1 , false, I2C_TIMEOUT);
}

/*
    Reads one byte 
*/
uint8_t SLG_I2Cread(void){

    uint8_t data;
    return i2c_read_blocking_until(I2C_INSTANCE, DEVICE_ADDRESS, &data,1, false, I2C_TIMEOUT);
}


uint8_t SLG_I2CreadEx(uint8_t * data, uint8_t size){

    return i2c_read_blocking_until(I2C_INSTANCE, DEVICE_ADDRESS, &data,1, false, I2C_TIMEOUT);
}
