/*
 * driver_rotation_sensor.c
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */

#include "driver_rotation_sensor.h"
#include "stdlib.h"

#define ADC_MAX_VALUE 4095
#define MAX_ANGLE 300.0

extern ADC_HandleTypeDef hadc1;

#define ROTATION_ADC &hadc1


float angle;
volatile uint32_t adc_value = 0;
volatile uint8_t adc_flag = 0;
static uint16_t last_stable_value = 0;
const uint16_t ADC_THRESHOLD = 20;  // Adjust this value as needed




void rotation_sensor_test()
{
    HAL_ADC_Start_IT(ROTATION_ADC);

	while (1)
	{
		__NOP();

		if (adc_flag)
		{
			adc_flag = 0;
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);

		}

		// Restart the ADC conversion

		HAL_ADC_Start_IT(ROTATION_ADC);

	}
}



void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	__NOP();

    // Stop the ADC conversion to prevent new data while processing
    HAL_ADC_Stop_IT(hadc);

	if (hadc->Instance == ADC1)
	{
        uint16_t new_value = HAL_ADC_GetValue(hadc);



        // Only update if the change is significant
        if (abs((int)new_value - (int)last_stable_value) > ADC_THRESHOLD)
        {
            adc_value = new_value;
            last_stable_value = new_value;
            adc_flag = 1;

    		// Calculate the rotation angle
    		angle = ((float) adc_value / ADC_MAX_VALUE) * MAX_ANGLE;
        }



	}
}
