/*
      FILE:         M24C16_R.c
      AUTHOR:       Nagendra A Karmarkar
      PURPOSE:      Nrf52 Library for external I2C EEPROM M24C16-R         
*/

#include "M24C16_R.h"

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


void eep_read_byte(uint16_t eep_address, unsigned char* val)
{
    unsigned char eep_by_address[2];
    eep_by_address[0]	= eep_address;
    
    nrf_drv_twi_tx(&m_twi, EEPROM_ADDRESS, eep_by_address, 1, true);
    nrf_drv_twi_rx(&m_twi, EEPROM_ADDRESS, val,1);  // read a byte
    nrf_delay_ms(5);  //need to wait till completion of operation
}

void eep_read_string(uint16_t eep_address, unsigned char* val)
{
    int i=1;   
    while(val[i-1] != '\0')
    {
        eep_read_byte(eep_address, &byte_data);
        val[i]=byte_data;
        i++;
        eep_address++;
    }
}


void eep_write_byte(uint16_t eep_address, unsigned char val)
{
    unsigned char eep_by_address[3];
    eep_by_address[1] = val;
    eep_by_address[0] = eep_address;
    
    nrf_drv_twi_tx(&m_twi,  EEPROM_ADDRESS, eep_by_address, 2, false);
    nrf_delay_ms(5); //need to wait till completion of operation
}

void eep_write_string(uint16_t eep_address, unsigned char *val)
{
    while(*val != '\0')
    {
        eep_write_byte(eep_address,*val);
        eep_address++;
        val++;
    } 
}
