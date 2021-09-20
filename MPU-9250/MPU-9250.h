/*
      FILE:         MPU-9250.h
      AUTHOR:       Nagendra A Karmarkar
      PURPOSE:      Nrf52 Library for external I2C ACCELEROMETER MPU-9250   
*/

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "nrf_drv_twi.h"
#include "nrf_delay.h"

#define TWI_SCL_M           6         //I2C SCL Pin
#define TWI_SDA_M           9         //I2C SDA Pin
#define TWI_ADDRESSES       127
#define ACCL                0x68


#define	ACCEL_XOUT_H		0x3B
#define	ACCEL_XOUT_L		0x3C
#define	ACCEL_YOUT_H		0x3D
#define	ACCEL_YOUT_L		0x3E
#define	ACCEL_ZOUT_H		0x3F
#define	ACCEL_ZOUT_L		0x40


void twi_master_init(void);
void acc_read_byte(uint16_t acc_address, unsigned char* val);
void acc_write_byte(uint16_t acc_address, unsigned char val);





