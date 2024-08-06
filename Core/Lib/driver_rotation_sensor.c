/*
 * driver_rotation_sensor.c
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */

#include "driver_rotation_sensor.h"
#include "stdlib.h"

#define ADC_MAX_VALUE 4095
#define MAX_VOLUMN 	30

extern ADC_HandleTypeDef hadc1;

volatile float temp;
volatile float temp_adc;
volatile uint8_t flag;

volatile uint8_t driver_volumn_value;




#define ROTATION_ADC &hadc1


void driver_get_volumn ()
{

}


void rotation_sensor_test()
{
	bsp_adc_start();

	while (1)
	{
		__NOP();

		flag = bsp_check_adc_flag();

		if (flag)
		{
			temp = bsp_get_adc_value();

			temp = (temp / ADC_MAX_VALUE) * MAX_VOLUMN;

			driver_volumn_value = temp;

			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
		}


		// Restart the ADC conversion

		bsp_adc_start();

	}
}




