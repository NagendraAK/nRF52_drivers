/*
      FILE:         accel5_nrf.c
      AUTHOR:       Nagendra A Karmarkar
      PURPOSE:      Nrf52 Library for external I2C ACCELEROMETER BMA400     
	  DEV kit used - Accel click 5	  
*/

#include "accel5_nrf.h"
#include <stdio.h>
#include "boards.h"
#include "app_util_platform.h"
#include "nrf_drv_twi.h"


extern nrf_drv_twi_t m_twi;
static uint8_t _slaveAdd                 = 0x15;
uint16_t count=0;



ret_code_t accel5_generic_write (uint8_t reg, uint8_t *data_buf, uint8_t len )
{
    uint8_t tx_buf[ 256 ];
    uint16_t cnt;

    tx_buf[ 0 ] = reg;

    for ( cnt = 1; cnt <= len; cnt++ )
    {
        tx_buf[ cnt ] = data_buf[ cnt - 1 ];
    }

    return nrf_drv_twi_tx(&m_twi, _slaveAdd, tx_buf, len + 1, false);
}

uint8_t accel5_generic_read_1 (uint8_t reg)
{
    uint8_t hr_storage[1];
    uint32_t returnValue=0;
    hr_storage[0]=reg;

    nrf_drv_twi_tx(&m_twi, _slaveAdd, hr_storage, 1, false);
    nrf_drv_twi_rx(&m_twi, _slaveAdd, hr_storage, 1);
    returnValue=hr_storage[0];
    return returnValue;
}  
  
uint16_t accel5_generic_read_2 (uint8_t reg)
{
    uint8_t read_reg[ 2 ];
    uint16_t read_data;
    uint8_t hr_storage[1];
    hr_storage[0]=reg;

    nrf_drv_twi_tx(&m_twi, _slaveAdd, hr_storage, 1, false);
    nrf_drv_twi_rx(&m_twi, _slaveAdd, read_reg, 2);

    read_data = read_reg[ 1 ];
    read_data = read_data << 8;
    read_data = read_data | read_reg[ 0 ];

    //returnValue = hr_storage[0];
    //returnValue = returnValue<<8;
    //returnValue |= hr_storage[1];
    return read_data;
}  


void accel5_default_cfg ( uint8_t mode, uint8_t range )
{
    accel5_write_byte( ACCEL5_REG_ACC_CONGIG_0, mode );
    accel5_write_byte( ACCEL5_REG_ACC_CONGIG_1, range );
    accel5_write_byte( ACCEL5_REG_ACC_CONGIG_2, ACCEL5_CFG_2_DATA_SCR_ACC_FILT_2 );
    
    accel5_write_byte( ACCEL5_REG_INT_CONFIG_0, ACCEL5_INT_CFG_0_DATA_RDY | 
                                               ACCEL5_INT_CFG_0_GEN1_INT_STATUS |
                                               ACCEL5_INT_CFG_0_GEN1_INT_STATUS |
                                               ACCEL5_INT_CFG_0_ORIENTCH_INT );
                                               
    accel5_write_byte( ACCEL5_REG_INT_CONFIG_1, ACCEL5_INT_CFG_1_STEP_INT_ENABLE |
                                               ACCEL5_INT_CFG_1_SINGLE_TAP_ENABLE |
                                               ACCEL5_INT_CFG_1_DOUBLE_TAP_ENABLE |
                                               ACCEL5_INT_CFG_1_ACTCH_INT_ENABLE );
    
    accel5_write_byte( ACCEL5_REG_INT12_MAP, ACCEL5_INT12_MAP_TAP_INT1 );
                                            
    accel5_write_byte( ACCEL5_REG_ORIENTCH_CONFIG_0, ACCEL5_ORIENT_X_AXIS_ENABLE |
                                                    ACCEL5_ORIENT_Y_AXIS_ENABLE |
                                                    ACCEL5_ORIENT_Z_AXIS_ENABLE |
                                                    ACCEL5_ORIENT_DATA_SRC_ENABLE |
                                                    ACCEL5_ORIENT_STABILITY_ENABLED_1 );

    accel5_write_byte( ACCEL5_REG_GEN1_INT_CONFIG_0, ACCEL5_GEN1_CFG0_ACT_X_ENABLE |
                                                    ACCEL5_GEN1_CFG0_ACT_Y_ENABLE |
                                                    ACCEL5_GEN1_CFG0_ACT_Z_ENABLE |
                                                    ACCEL5_GEN1_CFG0_DATA_ENABLE |
                                                    ACCEL5_GEN1_CFG0_HYST_24mg |
                                                    ACCEL5_GEN1_CFG0_REFU_EVERYTIME );
                                                   
    accel5_write_byte( ACCEL5_REG_GEN2_INT_CONFIG_0, ACCEL5_GEN2_CFG0_ACT_X_ENABLE |
                                                    ACCEL5_GEN2_CFG0_ACT_Y_ENABLE |
                                                    ACCEL5_GEN2_CFG0_ACT_Z_ENABLE |
                                                    ACCEL5_GEN2_CFG0_DATA_ENABLE |
                                                    ACCEL5_GEN2_CFG0_HYST_24mg |
                                                    ACCEL5_GEN2_CFG0_REFU_EVERYTIME );

    accel5_write_byte( ACCEL5_REG_ACTCH_CONFIG_1, ACCEL5_ACTCH_CFG0_X_AXIS_ENABLE |
                                                 ACCEL5_ACTCH_CFG0_Y_AXIS_ENABLE |
                                                 ACCEL5_ACTCH_CFG0_Z_AXIS_ENABLE |
                                                 ACCEL5_ACTCH_CFG0_DATA_ENABLE |
                                                 ACCEL5_ACTCH_CFG0_NPTS_POINT_32 );

    accel5_write_byte( ACCEL5_REG_TAP_CONFIG_0, ACCEL5_TAP_CFG0_USE_X_AXIS |
                                               ACCEL5_TAP_CFG0_USE_Y_AXIS |
                                               ACCEL5_TAP_CFG0_USE_Z_AXIS );
                                               
    accel5_write_byte( ACCEL5_REG_TAP_CONFIG_1, ACCEL5_TAP_CFG1_QUIET_DT_SAMPLE_4 |
                                               ACCEL5_TAP_CFG1_QUIET_SAMPLE_60 |
                                               ACCEL5_TAP_CFG1_TICS_TH_SAMPLE_6 );

}

void accel5_write_byte (uint8_t reg, uint8_t reg_data )
{
    uint8_t tmp_data = reg_data;

    accel5_generic_write(reg, &tmp_data, 1 );
}

uint8_t accel5_read_byte (uint8_t reg )
{
    uint8_t read_reg;

    read_reg=accel5_generic_read_1(reg);

    return read_reg;
}

uint16_t accel5_read_data (uint8_t reg )
{
    uint8_t read_reg[ 2 ];
    uint16_t read_val_data;

    read_val_data=accel5_generic_read_2(reg );

    return read_val_data;

}

int16_t accel5_get_axis ( uint8_t axis )
{
    int16_t axis_data;

    axis_data = accel5_read_data( axis );
    axis_data = axis_data & 0x0FFF;

    if ( axis_data > 2047 )
    {
        axis_data = (int16_t)( axis_data - 4096 );
    }

    return axis_data;
}

uint32_t accel5_sensor_time ( void )
{
    uint32_t s_time;
    uint8_t read_time0;
    uint8_t read_time1;
    uint8_t read_time2;

    read_time0 = accel5_read_byte( ACCEL5_REG_SENSOR_TIME_0 );
    read_time1 = accel5_read_byte( ACCEL5_REG_SENSOR_TIME_1 );
    read_time2 = accel5_read_byte( ACCEL5_REG_SENSOR_TIME_2 );

    s_time = read_time2;
    s_time = s_time << 8;
    s_time = s_time | read_time1;
    s_time = s_time << 8;
    s_time = s_time | read_time0;
    s_time = (uint32_t)s_time * 312.5;

    return s_time;
}

float accel5_get_temperature ( void )
{
    int8_t read_data;
    float temp;

    read_data = accel5_read_byte( ACCEL5_REG_TEMPERATURE );
    if ( read_data > 0x80 )
    {
        read_data = read_data - 256;
    }
   // temp = ( read_data * 0.5 ) + 33.0;
   // printf (" TEMPERATURE : %d \r\n", read_data );

      read_data = read_data+16;
      printf (" TEMPERATURE : %d \r\n", read_data );
       
   // temp = (int16_t)(((int8_t)read_data) * 5) + 230;
   // printf (" TEMPERATURE : %d \r\n", temp );
    return read_data;
}

void accel5_soft_reset ( void )
{
    accel5_write_byte( ACCEL5_REG_CMD, ACCEL5_CMD_SOFTWARE_RESET );
}


uint8_t bma400_get_steps_counted(uint32_t *step_count, uint8_t *activity_data)
{
    int8_t rslt=1;
    uint8_t data_array[4];

    uint32_t step_count_0 = 0;
    uint32_t step_count_1 = 0;
    uint32_t step_count_2 = 0;

    nrf_drv_twi_tx(&m_twi, _slaveAdd, ACCEL5_REG_STEP_CNT_0, 1, false);
    nrf_drv_twi_rx(&m_twi, _slaveAdd, data_array, 4);

        step_count_0 = (uint32_t)data_array[0];
        step_count_1 = (uint32_t)data_array[1] << 8;
        step_count_2 = (uint32_t)data_array[2] << 16;
        *step_count = step_count_0 | step_count_1 | step_count_2;

        *activity_data = data_array[3];

        printf (" STEPS : %d\r\n", step_count );
        printf (" activity : %d\r\n", activity_data );
    
    return rslt;
}


void accel5_step_int ( void )
{
    int8_t read_data;
    accel5_write_byte( ACCEL5_REG_INT_CONFIG_1, 0x01 );
    nrf_drv_twi_rx(&m_twi, _slaveAdd, read_data, 1);
    if(read_data == 1){
    count++;
    read_data=0;
    }
    printf (" STEPS : %d\r\n", count );
    printf (" accel5_step_int : %d \r\n", read_data );
}
