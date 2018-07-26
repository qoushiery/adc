/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Qoushiry
 */
#include "types.h"
#include "DIO.h"
#include "LCD.h"
#include "ADC.h"
#define F_CPU 12000000UL
#include <util/delay.h>
//LDR
int main (void)
{
	ADC_vidinit();
	LCD_vidinit();
	u8 digital;
	u8 step;
	u8 ldr[]="LDR : ";
	while(1)
	{
		digital=ADC_u8ReadOp();
		step=(digital*5)/256;
		LCD_vidWriteString(ldr);
		LCD_vidSetPosition(1,6);
		LCD_vidWriteNumber(step);
		_delay_ms(100);
		LCD_vidWriteCommand(0b00000001);

	}
	return 0;
}
