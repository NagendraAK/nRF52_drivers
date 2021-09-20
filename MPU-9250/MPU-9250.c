/*
      FILE:         MPU-9250.c
      AUTHOR:       Nagendra A Karmarkar
      PURPOSE:      Nrf52 Library for external I2C ACCELEROMETER MPU-9250         
*/

#include "MPU-9250.h"

unsigned char byte_data=0;

#define TWI_INSTANCE_ID     0                                              	//Initializing TWI0 instance
static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);  	// Create a Handle for the twi communication

void twi_master_init(void)                                    				//Initialize the TWI as Master device
{
    ret_code_t err_code;
                                                         
    const nrf_drv_twi_config_t twi_config = {                 				// Configure the settings for twi communication
       .scl                = TWI_SCL_M,                       				//SCL Pin
       .sda                = TWI_SDA_M,                       				//SDA Pin
       .frequency          = NRF_DRV_TWI_FREQ_100K,           				//Communication Speed
       .interrupt_priority = APP_IRQ_PRIORITY_LOWEST,          				//sd_nvic_SetPriority(I2S_CONFIG_IRQ_PRIORITY ,5)        //Interrupt Priority(Note: if using Bluetooth then select priority carefully)
       .clear_bus_init     = false                            				//automatically clear bus
    };

    err_code = nrf_drv_twi_init(&m_twi, &twi_config, NULL, NULL);  			//A function to initialize the twi communication
    APP_ERROR_CHECK(err_code);
  
    nrf_drv_twi_enable(&m_twi);   											//Enable the TWI Communication
}


void acc_read_byte(uint16_t acc_address, unsigned char* val)
{
    unsigned char acc_by_address[2];
    acc_by_address[0]	= acc_address;
    
    nrf_drv_twi_tx(&m_twi, ACCL, acc_by_address, 1, true);
    nrf_drv_twi_rx(&m_twi, ACCL, val,1);  									// read a byte
    nrf_delay_ms(5);  														//need to wait till completion of operation
}

void acc_write_byte(uint16_t acc_address, unsigned char val)
{
    unsigned char acc_by_address[3];
    acc_by_address[1] = val;
    acc_by_address[0] = acc_address;
    
    nrf_drv_twi_tx(&m_twi,  ACCL, acc_by_address, 2, false);
    nrf_delay_ms(5); 														//need to wait till completion of operation
}

