/*
 ============================================================================
 Name        : ldr.h
 Author      : Menna Tullah Medhat
 Description : This driver is responsible for reading the light intensity using
               an LDR (Light Dependent Resistor).
 Date        : 10/6/2024
 ============================================================================
 */
#include "std_types.h"

#define INTENSITYSENSOR_CHANNEL_ID         0
#define INTENSITYSENSOR_MAX_VOLT_VALUE     2.56
#define SENSOR_MAX_INTENSITY      100

#ifndef LDR_H_
#define LDR_H_

/* Reads the LDR sensor value and returns the light intensity.*/
uint16 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
