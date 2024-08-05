/*
 * driver_rotation_sensor.c
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */

#include "driver_rotation_sensor.h"


#define ADC_MAX_VALUE 4095
#define MAX_ANGLE 300.0
uint32_t value;
float angle;


void rotation_sensor_test()
{
	bsp_adc_start();

	while (1)
	{
		__NOP();

		if (bsp_check_adc_flag())
		{
			value = bsp_get_adc_value();

			// Calculate the rotation angle
			angle = ((float) value / ADC_MAX_VALUE) * MAX_ANGLE;

			bsp_delay(100);
		}
	}
}
