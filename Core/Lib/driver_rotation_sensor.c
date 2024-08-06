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
volatile uint8_t driver_volumn_value;





#define ROTATION_ADC &hadc1


void rotation_sensor_init()
{
	bsp_adc_start();
}

uint8_t rotaion_sensor_detect_volumn_change ()
{
	return bsp_check_adc_flag();
}

uint8_t rotation_sensor_get_volumn()
{
	driver_volumn_value = (bsp_get_adc_value() * MAX_VOLUMN) / ADC_MAX_VALUE;

	return driver_volumn_value;
}





