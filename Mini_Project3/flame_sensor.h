/*
 ============================================================================
 Name        : flame_sensor.h
 Author      : Menna Tullah Medhat
 Description : The flame sensor will detect fire incidents. Implement the
               following functions using a polling technique
 Date        : 10/6/2024
 ============================================================================
 */
#define FLAME_SENSOR_PORT  PORTD_ID
#define FLAME_SENSOR_PIN   PIN2_ID

#include "std_types.h"

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

/*Initializes the flame sensor pin direction.*/
void FlameSensor_init(void);

/*Reads the value from the flame sensor and returns it*/
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
