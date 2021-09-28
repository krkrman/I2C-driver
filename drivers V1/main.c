/*
 * drivers V1.c
 *
 * Created: 9/20/2021 1:33:51 PM
 * Author : Karim Essam
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/I2C/I2C_interface.h"

int main(void)
{
	I2C_voidInitMaster(I2C_PRESCALAR_1 , 200000);
	LCD_voidInit();
	I2C_voidSendStartCondition();
	I2C_voidSendWriteCommand(0x02);
	I2C_voidSendData(5);
	I2C_voidSendStopCondition();
	while(1);
}
