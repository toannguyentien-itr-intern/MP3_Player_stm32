/*
 * bsp_adc.c
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */


#include <bsp_adc.h>
#include "stdlib.h"

extern ADC_HandleTypeDef hadc1;

#define ROTATION_ADC &hadc1

//volatile uint16_t adc_value = 0;
volatile uint8_t adc_flag = 0;
//static uint16_t last_stable_value = 0;
//const uint16_t ADC_THRESHOLD = 10;  // Adjust based on your need


void bsp_adc_start (void)
{
	HAL_ADC_Start_IT(ROTATION_ADC);
}

void bsp_adc_stop (void)
{
    HAL_ADC_Stop_IT(ROTATION_ADC);
}

uint32_t bsp_get_adc_value (void)
{
	uint32_t temp_adc_value = HAL_ADC_GetValue(ROTATION_ADC);
	return temp_adc_value;
}

uint8_t bsp_check_adc_flag (void)
{
	uint8_t temp_adc_flag = adc_flag;

	adc_flag = 0;

	return temp_adc_flag;
}

//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
//{
//	__NOP();
//    if (hadc->Instance == ADC1)
//    {
//        uint16_t new_value = HAL_ADC_GetValue(ROTATION_ADC);
//
//        // Only update if the change is significant
//        if (abs((int)new_value - (int)last_stable_value) > ADC_THRESHOLD)
//        {
//            adc_value = new_value;
//            last_stable_value = new_value;
//            adc_flag = 1;  // Set flag to indicate significant change
//        }
//
//        // Restart the ADC conversion
//        HAL_ADC_Start_IT(hadc);
//    }
//}
