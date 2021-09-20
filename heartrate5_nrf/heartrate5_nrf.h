/*
      FILE:         accel5_nrf.h
      AUTHOR:       Nagendra A Karmarkar
      PURPOSE:      Nrf52 Library for external I2C heartrate sensor     
	  DEV kit used - Accel click 5	afe4404  
*/

#include "stdint.h"


extern const uint8_t HR5_REG0H  ;
extern const uint8_t HR5_REG1H  ;
extern const uint8_t HR5_REG2H  ;
extern const uint8_t HR5_REG3H  ;
extern const uint8_t HR5_REG4H  ;
extern const uint8_t HR5_REG5H  ;
extern const uint8_t HR5_REG6H  ;
extern const uint8_t HR5_REG7H  ;
extern const uint8_t HR5_REG8H  ;
extern const uint8_t HR5_REG9H  ;
extern const uint8_t HR5_REGAH  ;
extern const uint8_t HR5_REGBH  ;
extern const uint8_t HR5_REGCH  ;
extern const uint8_t HR5_REGDH  ;
extern const uint8_t HR5_REGEH  ;
extern const uint8_t HR5_REGFH  ;
extern const uint8_t HR5_REG10H ;
extern const uint8_t HR5_REG11H ;
extern const uint8_t HR5_REG12H ;
extern const uint8_t HR5_REG13H ;
extern const uint8_t HR5_REG14H ;
extern const uint8_t HR5_REG15H ;
extern const uint8_t HR5_REG16H ;
extern const uint8_t HR5_REG17H ;
extern const uint8_t HR5_REG18H ;
extern const uint8_t HR5_REG19H ;
extern const uint8_t HR5_REG1AH ;
extern const uint8_t HR5_REG1BH ;
extern const uint8_t HR5_REG1CH ;
extern const uint8_t HR5_REG1DH ;
extern const uint8_t HR5_REG1EH ;
extern const uint8_t HR5_REG20H ;
extern const uint8_t HR5_REG21H ;
extern const uint8_t HR5_REG22H ;
extern const uint8_t HR5_REG23H ;
extern const uint8_t HR5_REG29H ;
extern const uint8_t HR5_REG2AH ;
extern const uint8_t HR5_REG2BH ;
extern const uint8_t HR5_REG2CH ;
extern const uint8_t HR5_REG2DH ;
extern const uint8_t HR5_REG2EH ;
extern const uint8_t HR5_REG2FH ;
extern const uint8_t HR5_REG31H ;
extern const uint8_t HR5_REG32H ;
extern const uint8_t HR5_REG33H ;
extern const uint8_t HR5_REG34H ;
extern const uint8_t HR5_REG35H ;
extern const uint8_t HR5_REG36H ;
extern const uint8_t HR5_REG37H ;
extern const uint8_t HR5_REG39H ;
extern const uint8_t HR5_REG3AH ;
extern const uint8_t HR5_REG3DH ;
extern const uint8_t HR5_ADDR;


void heartrate5_writeReg(uint8_t regAddr,uint32_t wData); /** Function for writing a 24bit value to a register. */
uint32_t heartrate5_readReg(uint8_t regAddr); /** Function for reading a 24bit value from a register. */
void heartrate5_init(); /** Default initialization routine */
void heartrate5_hwReset();/** Hardware reset function */
void heartrate5_swReset();/** Software reset function */
void twi_init (void);
uint32_t heartrate5_getLed2val( void );  /** Returns the value of the conversion resoult from LED2VAL.*/
uint32_t heartrate5_getAled2val_led3val( void ); //Returns the value of the conversion resoult from ALED2VAL.*/
uint32_t heartrate5_getLed1val( void );  /**Returns the value of the conversion resoult from LED1VAL.*/
uint32_t heartrate5_getAled1val( void ); /**Returns the value of the conversion resoult from ALED1VAL.*/
uint32_t heartrate5_getLed2_aled2val( void ); /**Returns the value of the conversion resoult from LED2_ALED2VAL.*/
uint32_t heartrate5_getLed1_aled1val( void ); /**Returns the value of the conversion resoult from LED1_ALED1VAL.*/

