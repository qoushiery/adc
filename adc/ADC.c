/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Qoushiry
 */
#include "types.h"
#include "registers.h"
#include "DIO.h"
#include "macros.h"
void ADC_vidinit(void)
{
	ADMUX=0b01100000;// first 2 bits Vref from internal 5v, Left Adjustment =1, last 5 bits ADC channel
	ADCSRA=0b10000000;// ADC enable, auto trigger is OFF , No interrupts , last 2 bits prescaler
}
u8 ADC_u8ReadOp(void)
{
	SetBit(ADCSRA,6);//start conversion
	while((ReadPin(ADCSRA,4)==0));// polling on conversion end flag
	SetBit(ADCSRA,4);// reset flag
	return ADCH;//returm the converted value(digital)
}
