#include <stdio.h>

#define I2C_INSTANCE            I2C0
#define DEVICE_ADDRESS          0x08 // Check this
#define I2C_TIMEOUT             250 // Check this

// I2C defines
// This example will use I2C0 on GPIO24 (SDA) and GPIO25 (SCL) running at 400KHz.
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define I2C_SDA 24
#define I2C_SCL 25

extern void SLD46826_gpioInit(void);
extern uint8_t SLG_I2Csend(uint8_t data);
extern uint8_t SLG_I2Cread(void);
extern uint8_t SLG_I2CreadEx(uint8_t * data, uint8_t size);