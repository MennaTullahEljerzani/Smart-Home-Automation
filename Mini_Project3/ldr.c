/*
 ============================================================================
 Name        : ldr.h
 Author      : Menna Tullah Medhat
 Description : This driver is responsible for reading the light intensity using
               an LDR (Light Dependent Resistor).
 Date        : 10/6/2024
 ============================================================================
 */

#include "ldr.h"
#include "adc.h"
#include <util/delay.h>

/* Reads the LDR sensor value and returns the light intensity.*/
uint16 LDR_getLightIntensity(void){
	uint16 intensity_value = 0;

		uint32 adc_value = 0;

		/* Read ADC channel where the temperature sensor is connected */
		adc_value = ADC_readChannel(INTENSITYSENSOR_CHANNEL_ID);

		/* Calculate the temperature from the ADC value*/
		intensity_value = (uint16)(((uint32)adc_value*SENSOR_MAX_INTENSITY*2.56)/(1023*INTENSITYSENSOR_MAX_VOLT_VALUE));

		return intensity_value;

}

