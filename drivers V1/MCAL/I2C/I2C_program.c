/*
 * I2C.c
 *
 * Created: 9/23/2021 9:05:13 AM
 *  Author: Karim Essam
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../CLOCK/CLOCK_interface.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "I2C_private.h"
#include "I2C_interface.h"

static void commonOperantion(void)
{
	// clear flag to send
	SET_BIT(TWCR_REG , 7);
	// enable
	SET_BIT(TWCR_REG , 2);
	// wait for the flag to be low
	while (!GET_BIT(TWCR_REG , 7));
}

void I2C_voidInitMaster(I2C_Prescalar_t prescalar , u32 frequency)
{
	TWBR_REG = (CLOCK_u32GetSystemClock()/(2*prescalars[prescalar]))-16;
	TWSR_REG = prescalar;
	//enable acknowledge
	SET_BIT(TWCR_REG , 6);
	// enable
	SET_BIT(TWCR_REG , 2);
}
  
void I2C_voidInitSlave(u8 slaveAddress)
{
	TWAR_REG = (slaveAddress<<1);
	// enable
	SET_BIT(TWCR_REG , 2);
}

void I2C_voidSendStartCondition()
{
	// send start condition
	SET_BIT(TWCR_REG , 5);
	commonOperantion();
	u8 status = (TWSR_REG & 0b11111000);
	while (status != START_CONDITION);
}

void I2C_voidSendRepeatedStart()
{
	// send start condition
	SET_BIT(TWCR_REG , 5);
	commonOperantion();

	u8 status = (TWSR_REG & 0b11111000);
	while (status != REPEATED_START_CONDITION);
}

void I2C_voidSendWriteCommand(u8 slaveAddress)
{
	TWDR_REG = (slaveAddress << 1);
	commonOperantion();
	u8 status = (TWSR_REG & 0b11111000);
	while (status != NOT_ACK_SLAVE_ADDRESS_AND_WRITE && status != SLAVE_ADDRESS_AND_WRITE);
}

void I2C_voidSendReadCommand(u8 slaveAddress)
{
	TWDR_REG = (slaveAddress<<1) ;
	//to read
	TWDR_REG |= 1;
	commonOperantion();

	u8 status = (TWSR_REG & 0b11111000);
	while(status != NOT_ACK_SLAVE_ADDRESS_AND_READ && status != SLAVE_ADDRESS_AND_READ);
}
 
 void I2C_voidSendData(u8 data){
	TWDR_REG = data;
	commonOperantion();		
	u8 status = (TWSR_REG & 0b11111000);
	while (status != DATA_TRANSMITTED && status != NOT_ACK_DATA_TRANSMITTED);
 }
 
 u8 I2C_u8RecieveData(void)
 {
	 commonOperantion();
	 u8 status = (TWSR_REG & 0b11111000);
	 while (status!= DATA_RECIEVED && status != NOT_ACK_DATA_RECIEVED);
	 return TWDR_REG;
 }
 
void I2C_voidSendStopCondition()
{
	// stop condition
	SET_BIT(TWCR_REG , 4);
	
	commonOperantion();
	u8 status = (TWSR_REG & 0b11111000);
	while (status != STOP_CONDITION);
}

/*void I2C_voidSlaveTransmitData(u8 data)
{
	TWDR_REG = data;
	// clear flag to send
	SET_BIT(TWCR_REG , 7);
	// send start condition
	SET_BIT(TWCR_REG , 2);
	
	while (!GET_BIT(TWCR_REG , 7));
	while ((TWSR_REG & 0b11111000) != DATA_TRANSMITTED);
}*/

