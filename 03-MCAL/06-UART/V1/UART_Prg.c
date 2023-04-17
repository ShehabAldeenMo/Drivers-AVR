/*
 * UART_Prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "DIO_interface.h"
#include "avr/delay.h"

void UART_VidInit () {
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	CLR_BIT(UCSRB,UCSZ2);

	u8 UCSRC_help = 0b10000000 ;
	CLR_BIT(UCSRC_help,UMSEL);
	CLR_BIT(UCSRC_help,UPM1);
	CLR_BIT(UCSRC_help,UPM0);
	CLR_BIT(UCSRC_help,USBS);
	SET_BIT(UCSRC_help,UCSZ1);
	SET_BIT(UCSRC_help,UCSZ0);
	CLR_BIT(UCSRC_help,UCPOL);
	UCSRC = UCSRC_help ;

	UBRRH = 0 ;
	UBRRL = 51 ;
}
void UART_VidSendData(u8 Copy_U8Data){
	while ( !GET_BIT(UCSRA,UDRE) );
	UDR = Copy_U8Data ;
}
u8 UART_VidRecieveData(){
	while ( !GET_BIT(UCSRA,RXC) );
	return UDR ;
}
void UART_VidSendString (u8 Copy_U8String[]){
	u8 i = 0 ;
	while (Copy_U8String[i] != '\0'){
		UART_VidSendData(Copy_U8String[i]);
		i++ ;
	}
}
