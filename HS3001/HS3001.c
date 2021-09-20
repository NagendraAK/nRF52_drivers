///*
//      FILE:         HS3001.c
//      AUTHOR:       Nagendra A Karmarkar
//      PURPOSE:      Nrf52 Library for external I2C HT-sensor HS3001      
//*/

#include "HS3001.h"

unsigned char byte_data=0;


#define TWI_INSTANCE_ID     0                                              //Initializing TWI0 instance
static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);  // Create a Handle for the twi communication

void twi_master_init(void)                                    //Initialize the TWI as Master device
{
    ret_code_t err_code;
                                                         
    const nrf_drv_twi_config_t twi_config = {                 // Configure the settings for twi communication
       .scl                = TWI_SCL_M,                       //SCL Pin
       .sda                = TWI_SDA_M,                       //SDA Pin
       .frequency          = NRF_DRV_TWI_FREQ_100K,           //Communication Speed
       .interrupt_priority = APP_IRQ_PRIORITY_HIGH,           //Interrupt Priority(Note: if using Bluetooth then select priority carefully)
       .clear_bus_init     = false                            //automatically clear bus
    };

    err_code = nrf_drv_twi_init(&m_twi, &twi_config, NULL, NULL);  //A function to initialize the twi communication
    APP_ERROR_CHECK(err_code);
  
    nrf_drv_twi_enable(&m_twi);   //Enable the TWI Communication
}

//----------------------------------------------------------------------------

void ht_read_byte(uint16_t ht_address, unsigned char* val)
{
    unsigned char ht_by_address[2];
    ht_by_address[0]	= ht_address;
    
    nrf_drv_twi_tx(&m_twi, HT_ADDRESS, ht_by_address, 1, true);
    nrf_drv_twi_rx(&m_twi, HT_ADDRESS, val,1);  // read a byte
    nrf_delay_ms(5);  //need to wait till completion of operation
}

void ht_write_byte(uint16_t ht_address, unsigned char val)
{
    unsigned char ht_by_address[4];
    ht_by_address[1] = val;
    ht_by_address[0] = ht_address;
    
    nrf_drv_twi_tx(&m_twi,  HT_ADDRESS, ht_by_address, 2, false);
    nrf_delay_ms(5); //need to wait till completion of operation
}

