/*
 * UART_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "../LIB/STD_TYPES.h"

void UART_VidInit () ;
void UART_VidSendData(u8 Copy_U8Data);
u8 UART_VidRecieveData();
void UART_VidSendString (u8 Copy_U8String[]);

#endif /* UART_INTERFACE_H_ */
