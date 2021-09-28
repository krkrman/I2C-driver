/*
 * EEPROM_program.c
 *
 * Created: 9/26/2021 10:42:36 AM
 *  Author: Karim Essam
 */ 
void EEPROM_voidInit(void)
{
	I2C_voidInitMaster(I2C_PRESCALAR_1 , 200000);
}

void EEPROM_voidWriteByte(u8 address , u8 data)
{
	u8 byteNumber = (address&0XE0)>>5; // get most significant 3 bits
	u8 pageNumber = address&0X1F;		// get least significant 5 bits
	I2C_voidSendStartCondition();
	I2C_voidSendWriteCommand(0xA0 | byteNumber);
	I2C_voidSendData(pageNumber);
	I2C_voidSendData(data);
	I2C_voidSendStopCondition();
}

u8 EEPROM_u8ReadByte(u8 address)
{
	
}