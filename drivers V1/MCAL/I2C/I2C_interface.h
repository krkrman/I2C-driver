/*
 * I2C_interface.h
 *
 * Created: 9/23/2021 8:55:53 AM
 *  Author: Karim Essam
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum
{
	I2C_PRESCALAR_1,
	I2C_PRESCALAR_4,
	I2C_PRESCALAR_16,
	I2C_PRESCALAR_64,
}I2C_Prescalar_t;

// frequency = CPU_CLOCK/(16+2*TWBR*prescalar)
// max frequency 400k
void I2C_voidInitMaster(I2C_Prescalar_t prescalar , u32 frequency);
void I2C_voidInitSlave(u8 slaveAddress);
void I2C_voidSendStartCondition();
void I2C_voidSendRepeatedStart();
void I2C_voidSendWriteCommand(u8 slaveAddress);
void I2C_voidSendReadCommand(u8 slaveAddress);
void I2C_voidSendData(u8 data);
u8 I2C_u8RecieveData(void);
void I2C_voidSendStopCondition();

#endif /* I2C_INTERFACE_H_ */