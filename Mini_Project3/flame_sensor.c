/*
 ============================================================================
 Name        : flame_sensor.c
 Author      : Menna Tullah Medhat
 Description : The flame sensor will detect fire incidents. Implement the
               following functions using a polling technique
 Date        : 10/6/2024
 ============================================================================
 */
#include "flame_sensor.h"
#include "gpio.h"

/*Initializes the flame sensor pin direction.*/
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN, PIN_INPUT);
}

/*Reads the value from the flame sensor and returns it*/
uint8 FlameSensor_getValue(void)
{
	return GPIO_readPin(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN);
}


