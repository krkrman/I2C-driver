/*
 * EEPROM_interface.h
 *
 * Created: 9/26/2021 10:40:36 AM
 *  Author: Karim Essam
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPROM_voidWriteByte(u8 address , u8 data);
u8 EEPROM_u8ReadByte(u8 address);

#endif /* EEPROM_INTERFACE_H_ */