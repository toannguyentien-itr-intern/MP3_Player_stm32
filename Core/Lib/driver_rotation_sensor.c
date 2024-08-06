/*
 * driver_rotation_sensor.c
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */

#include "driver_rotation_sensor.h"
#include "stdlib.h"

#define ADC_MAX_VALUE 4095
#define MAX_VOLUMN 	31

extern ADC_HandleTypeDef hadc1;

volatile float temp;
volatile float temp_adc;
volatile uint8_t flag;

volatile uint8_t driver_volumn_value;

volatile uint8_t detect_flag = 0;




#define ROTATION_ADC &hadc1


uint8_t rotaion_sensor_detect_volumn_change ()
{
	uint8_t temp_flag = detect_flag;
	detect_flag = 0;
	return temp_flag;
}

void rotation_sensor_init()
{
	bsp_adc_start();
}


uint8_t rotation_sensor_get_volumn()
{
	while (1)
	{
		__NOP();

		flag = bsp_check_adc_flag();

		if (flag)
		{
			temp = bsp_get_adc_value();

			temp = (temp / ADC_MAX_VALUE) * MAX_VOLUMN;

			driver_volumn_value = temp;

		}
		// Restart the ADC conversion

		rotation_sensor_init();

		return driver_volumn_value;

	}
}




