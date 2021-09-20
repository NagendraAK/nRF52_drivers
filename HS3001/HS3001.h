///*
//      FILE:         HS3001.h
//      AUTHOR:       Nagendra A Karmarkar
//      PURPOSE:      Nrf52 Library for external I2C HT-sensor HS3001     
//*/

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "nrf_drv_twi.h"
#include "nrf_delay.h"

#define TWI_SCL_M          	 6         //I2C SCL Pin
#define TWI_SDA_M         	 9         //I2C SDA Pin
#define TWI_ADDRESSES     	 127
#define HT_ADDRESS      	 0x44

#define HUMIDITY			 0x06
#define TEMPERATURE			 0x11


void ht_read_byte(uint16_t ht_address, unsigned char val);
void ht_write_byte(uint16_t ht_address, unsigned char* val);
void twi_master_init(void);