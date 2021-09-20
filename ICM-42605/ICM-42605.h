/*
      FILE:         ICM-42605.h
      AUTHOR:       Nagendra A Karmarkar
      PURPOSE:      Nrf52 Library for external I2C ACCELEROMETER ICM-42605        
*/


#include "nrf_delay.h"
//I2C Pins Settings, you change them to any other pins
#define TWI_SCL_M           17         //I2C SCL Pin
#define TWI_SDA_M           16         //I2C SDA Pin

#define ags_ADDRESS_LEN  1           	//ags
//#define ags_ADDRESS     (0xD0>>1)  		//ags Device Address
#define ags_ADDRESS      0x69   		// Address of ags accel/gyro when ADO = HIGH

#define ags_WHO_AM_I     0x68U     		//ags ID

#define ags_GYRO_OUT        0x1F
#define ags_ACC_OUT         0x25

#define ADDRESS_WHO_AM_I          (0x75U) //  WHO_AM_I register identifies the device. Expected value is 0x68.
#define ADDRESS_SIGNAL_PATH_RESET (0x68U) // 

//ags Registers addresses, see datasheet for more info and each register's function
#define ags_DEVICE_CONFIG             0x11
#define ags_DRIVE_CONFIG              0x13
#define ags_INT_CONFIG                0x14
#define ags_FIFO_CONFIG               0x16
#define ags_TEMP_DATA1                0x1D
#define ags_TEMP_DATA0                0x1E
#define ags_ACCEL_DATA_X1             0x1F
#define ags_ACCEL_DATA_X0             0x20
#define ags_ACCEL_DATA_Y1             0x21
#define ags_ACCEL_DATA_Y0             0x22
#define ags_ACCEL_DATA_Z1             0x23
#define ags_ACCEL_DATA_Z0             0x24
#define ags_GYRO_DATA_X1              0x25
#define ags_GYRO_DATA_X0              0x26
#define ags_GYRO_DATA_Y1              0x27
#define ags_GYRO_DATA_Y0              0x28
#define ags_GYRO_DATA_Z1              0x29
#define ags_GYRO_DATA_Z0              0x2A
#define ags_TMST_FSYNCH               0x2B
#define ags_TMST_FSYNCL               0x2C
#define ags_INT_STATUS                0x2D
#define ags_FIFO_COUNTH               0x2E
#define ags_FIFO_COUNTL               0x2F
#define ags_FIFO_DATA                 0x30
#define ags_APEX_DATA0                0x31
#define ags_APEX_DATA1                0x32
#define ags_APEX_DATA2                0x33
#define ags_APEX_DATA3                0x34
#define ags_APEX_DATA4                0x35
#define ags_APEX_DATA5                0x36
#define ags_INT_STATUS2               0x37
#define ags_INT_STATUS3               0x38
#define ags_SIGNAL_PATH_RESET         0x4B
#define ags_INTF_CONFIG0              0x4C
#define ags_INTF_CONFIG1              0x4D
#define ags_PWR_MGMT0                 0x4E
#define ags_GYRO_CONFIG0              0x4F
#define ags_ACCEL_CONFIG0             0x50
#define ags_GYRO_CONFIG1              0x51
#define ags_GYRO_ACCEL_CONFIG0        0x52
#define ags_ACCEL_CONFIG1             0x53
#define ags_TMST_CONFIG               0x54
#define ags_APEX_CONFIG0              0x56
#define ags_SMD_CONFIG                0x57
#define ags_FIFO_CONFIG1              0x5F
#define ags_FIFO_CONFIG2              0x60
#define ags_FIFO_CONFIG3              0x61
#define ags_FSYNC_CONFIG              0x62
#define ags_INT_CONFIG0               0x63
#define ags_INT_CONFIG1               0x64
#define ags_INT_SOURCE0               0x65
#define ags_INT_SOURCE1               0x66
#define ags_INT_SOURCE3               0x68
#define ags_INT_SOURCE4               0x69
#define ags_FIFO_LOST_PKT0            0x6C
#define ags_FIFO_LOST_PKT1            0x6D
#define ags_SELF_TEST_CONFIG          0x70
#define ags_WHO_AM_I                  0x75
#define ags_REG_BANK_SEL              0x76

// Bank 1
#define ags_SENSOR_CONFIG0            0x03
#define ags_GYRO_CONFIG_STATIC2       0x0B
#define ags_GYRO_CONFIG_STATIC3       0x0C
#define ags_GYRO_CONFIG_STATIC4       0x0D
#define ags_GYRO_CONFIG_STATIC5       0x0E
#define ags_GYRO_CONFIG_STATIC6       0x0F
#define ags_GYRO_CONFIG_STATIC7       0x10
#define ags_GYRO_CONFIG_STATIC8       0x11
#define ags_GYRO_CONFIG_STATIC9       0x12
#define ags_GYRO_CONFIG_STATIC10      0x13
#define ags_XG_ST_DATA                0x5F
#define ags_YG_ST_DATA                0x60
#define ags_ZG_ST_DATA                0x61
#define ags_TMSTVAL0                  0x62
#define ags_TMSTVAL1                  0x63
#define ags_TMSTVAL2                  0x64
#define ags_INTF_CONFIG4              0x7A
#define ags_INTF_CONFIG5              0x7B
#define ags_INTF_CONFIG6              0x7C

// Bank 2
#define ags_ACCEL_CONFIG_STATIC2      0x03
#define ags_ACCEL_CONFIG_STATIC3      0x04
#define ags_ACCEL_CONFIG_STATIC4      0x05
#define ags_XA_ST_DATA                0x3B
#define ags_YA_ST_DATA                0x3C
#define ags_ZA_ST_DATA                0x3D

// Bank 4
#define ags_GYRO_ON_OFF_CONFIG        0x0E
#define ags_APEX_CONFIG1              0x40
#define ags_APEX_CONFIG2              0x41
#define ags_APEX_CONFIG3              0x42
#define ags_APEX_CONFIG4              0x43
#define ags_APEX_CONFIG5              0x44
#define ags_APEX_CONFIG6              0x45
#define ags_APEX_CONFIG7              0x46
#define ags_APEX_CONFIG8              0x47
#define ags_APEX_CONFIG9              0x48
#define ags_ACCEL_WOM_X_THR           0x4A
#define ags_ACCEL_WOM_Y_THR           0x4B
#define ags_ACCEL_WOM_Z_THR           0x4C
#define ags_INT_SOURCE6               0x4D
#define ags_INT_SOURCE7               0x4E
#define ags_INT_SOURCE8               0x4F
#define ags_INT_SOURCE9               0x50
#define ags_INT_SOURCE10              0x51
#define ags_OFFSET_USER0              0x77
#define ags_OFFSET_USER1              0x78
#define ags_OFFSET_USER2              0x79
#define ags_OFFSET_USER3              0x7A
#define ags_OFFSET_USER4              0x7B
#define ags_OFFSET_USER5              0x7C
#define ags_OFFSET_USER6              0x7D
#define ags_OFFSET_USER7              0x7E
#define ags_OFFSET_USER8              0x7F


#define AFS_2G  0x03
#define AFS_4G  0x02
#define AFS_8G  0x01
#define AFS_16G 0x00  // default

#define GFS_2000DPS   0x00 // default
#define GFS_1000DPS   0x01
#define GFS_500DPS    0x02
#define GFS_250DPS    0x03
#define GFS_125DPS    0x04
#define GFS_62_5DPS   0x05
#define GFS_31_25DPS  0x06
#define GFS_15_125DPS 0x07

#define AODR_8000Hz   0x03
#define AODR_4000Hz   0x04
#define AODR_2000Hz   0x05
#define AODR_1000Hz   0x06 // default
#define AODR_200Hz    0x07
#define AODR_100Hz    0x08
#define AODR_50Hz     0x09
#define AODR_25Hz     0x0A
#define AODR_12_5Hz   0x0B
#define AODR_6_25Hz   0x0C
#define AODR_3_125Hz  0x0D
#define AODR_1_5625Hz 0x0E
#define AODR_500Hz    0x0F

#define GODR_8000Hz  0x03
#define GODR_4000Hz  0x04
#define GODR_2000Hz  0x05
#define GODR_1000Hz  0x06 // default
#define GODR_200Hz   0x07
#define GODR_100Hz   0x08
#define GODR_50Hz    0x09
#define GODR_25Hz    0x0A
#define GODR_12_5Hz  0x0B
#define GODR_500Hz   0x0F


void twi_master_init(void); // initialize the twi communication
bool ags_init(void);    	// initialize the ags

bool ags_register_write(uint8_t register_address, const uint8_t value);
bool ags_register_read(uint8_t register_address, uint8_t *destination, uint8_t number_of_bytes);
bool ags_verify_product_id(void);
bool ags_ReadGyro(int16_t *pGYRO_X , int16_t *pGYRO_Y , int16_t *pGYRO_Z );
bool ags_ReadAcc( int16_t *pACC_X , int16_t *pACC_Y , int16_t *pACC_Z );


