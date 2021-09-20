/*
      FILE:         M24C16_R.h
      AUTHOR:       Nagendra A Karmarkar
      PURPOSE:      Nrf52 Library for external I2C EEPROM M24C16-R       
*/

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "nrf_drv_twi.h"
#include "nrf_delay.h"

#define TWI_SCL_M           6         //I2C SCL Pin
#define TWI_SDA_M           9         //I2C SDA Pin
#define TWI_ADDRESSES      127
#define EEPROM_ADDRESS (0xA0 >> 1)


void eep_write_string(uint16_t eep_address, unsigned char *val);
void eep_write_byte(uint16_t eep_address, unsigned char val);
void eep_read_string(uint16_t eep_address, unsigned char* val);
void eep_read_byte(uint16_t eep_address, unsigned char* val);
void twi_master_init(void);