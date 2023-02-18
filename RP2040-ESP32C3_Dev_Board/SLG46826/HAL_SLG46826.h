#include <stdio.h>

#define deviceAddress 0x08 // Check this

uint8_t SLG_I2Csend(uint8_t data);
uint8_t SLG_I2Cread(void);
uint8_t SLG_I2CreadEx(uint8_t &data, uint8_t size);