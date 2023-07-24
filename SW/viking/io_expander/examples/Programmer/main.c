#include "hardware/i2c.h"
#include <stdlib.h>
#include <string.h>
#include <pico/stdlib.h>
#include <stdio.h>

#define NVM_CONFIG 0x02

uint8_t data_array[16][16] = {};
volatile uint8_t pageCnt = 0;

#define I2C_PORT i2c0
#define I2C_SDA_PIN 24
#define I2C_SCL_PIN 25
#define I2C_SLAVE_ADDRESS 0x00

const char nvmString00[] = "00000000000000000000000000000000";
const char nvmString01[] = "00000000000000000000000000000000";
const char nvmString02[] = "0000000000000000000000F003000000";
const char nvmString03[] = "00000000F00100000000000000000000";
const char nvmString04[] = "00000000000000000000000000000000";
const char nvmString05[] = "00000000000000000000000000000000";
const char nvmString06[] = "00303000803030300000303030003030";
const char nvmString07[] = "30303030000000000000000000000000";
const char nvmString08[] = "0000FA02001422300C00000000000000";
const char nvmString09[] = "00000000000000000000000000000000";
const char nvmString10[] = "00000020000100000002010000020001";
const char nvmString11[] = "00000201000002000100000201000002";
const char nvmString12[] = "00010000020001000000010100000000";
const char nvmString13[] = "00000000000000000000000000000000";
const char nvmString14[] = "00000000000000000000000000000000";
const char nvmString15[] = "000000000000000000000000000000A5";

const char *const nvmString[16] = {
    nvmString00,
    nvmString01,
    nvmString02,
    nvmString03,
    nvmString04,
    nvmString05,
    nvmString06,
    nvmString07,
    nvmString08,
    nvmString09,
    nvmString10,
    nvmString11,
    nvmString12,
    nvmString13,
    nvmString14,
    nvmString15};

void hexToInteger(const char *hexString, uint8_t *dataArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        sscanf(hexString + (2 * i), "%2hhx", (unsigned char *)&dataArray[i]);
    }
}

int eraseChip()
{
    uint8_t adress = I2C_SLAVE_ADDRESS << 3;
    uint8_t eraseCode = 0xE3;
    for (pageCnt = 0; pageCnt < 16; pageCnt++)
    {
        uint8_t erasePage = (0x80 | pageCnt);

        uint8_t data[2];
        data[0] = eraseCode;
        data[1] = erasePage;

        uint8_t read[2];
        i2c_write_blocking(I2C_PORT, adress, data, count_of(data), false);
        int num_bytes_read = i2c_read_blocking(I2C_PORT, adress, read, count_of(read), false);
        printf("%d", num_bytes_read);
        sleep_ms(100);
    }
    return 0;
}

int writeChip()
{
    uint8_t control_code = I2C_SLAVE_ADDRESS;
    control_code |= NVM_CONFIG;

    for (int i = 0; i < 16; i++)
    {
        hexToInteger(nvmString[i], data_array[i], 16);
    }

    data_array[0xC][0xA] = I2C_SLAVE_ADDRESS;

    // Erase NVM
    eraseChip();

    for (int i = 0; i < 16; i++)
    {
        uint8_t val = (i << 4);
        uint8_t data[17] = {};
        data[0] = val;
        for (int k = 0; k < 16; k++)
        {
            data[k + 1] = data_array[i][k];
        }

        uint8_t read[17];
        i2c_write_blocking(I2C_PORT, control_code, data, count_of(data), false);
        int num_bytes_read = i2c_read_blocking(I2C_PORT, control_code, read, count_of(read), false);
        printf("%d", num_bytes_read);

        sleep_ms(100);
    }

    return 0;
}

void setup()
{
    stdio_init_all();

    i2c_init(I2C_PORT, 100000);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);
    sleep_ms(1000);
}

int main()
{
    setup();
    writeChip();
    // eraseChip(); You can comment out writeChip and use eraseChip() in order to erase the NVM.
    sleep_ms(10);
}
