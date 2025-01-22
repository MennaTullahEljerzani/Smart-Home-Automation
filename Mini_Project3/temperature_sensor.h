/*
 ============================================================================
 Name        : temperature_sensor.h
 Author      : Menna Tullah Medhat
 Description : Use the course-provided LM35 temperature sensor driver to measure the room's temperature. The
sensor should be connected to ADC channel 1.
 Date        : 10/6/2024
 ============================================================================
 */

#ifndef TEMPERATURE_SENSOR_H_
#define TEMPERATURE_SENSOR_H_
#include "std_types.h"

#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150


/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);



#endif /* TEMPERATURE_SENSOR_H_ */
