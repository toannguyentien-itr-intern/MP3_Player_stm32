/*
 * driver_rotation_sensor.c
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */

#include "driver_rotation_sensor.h"


#define ADC_MAX_VALUE 4095
#define MAX_ANGLE 300.0
uint32_t adc_value;
float angle;
