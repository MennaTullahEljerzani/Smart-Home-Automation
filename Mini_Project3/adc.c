/*
 ============================================================================
 Name        : adc.c
 Author      : Menna Tullah Medhat
 Description : ADC will be used to read analog data from sensors such as the
 LM35 temperature sensor and the LDR in the SMART HOME PROJECT.
 Date        : 10/6/2024
 ============================================================================
 */
#include <avr/io.h>
#include "adc.h"
#include "std_types.h"
#include "gpio.h"
#include "common_macros.h"

/*The function is going to initialize the ADC by setting the reference
 * voltage to 2.56 and prescaler to F_CPU/128.*/
/*These bits select the voltage reference for the ADC*/
void ADC_init(void)
{
	/*These bits(REFS1 and REFS0) select the voltage reference for the ADC*/
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);

	 /* Use Right Adjust */
	 CLEAR_BIT(ADMUX,ADLAR);
	 SET_BIT(ADCSRA,ADEN);

	/*These bits(ADPS0, ADPS1 and ADPS2) in ADCSRA register
	 * determine the division factor between
	 *  the XTAL frequency and the input clock to the ADC.*/
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}

/*Reads analog data from a specific ADC channel and converts it to digital.*/
uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}

