/*
 * bsp_adc.c
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */


#include "bsp_adc.h"

extern ADC_HandleTypeDef hadc1;

#define ROTATION_ADC &hadc1

uint8_t adc_flag =0;


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

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	__NOP();
  if (hadc->Instance == ADC1)
  {
	  adc_flag = 1;

	  HAL_ADC_Start_IT(ROTATION_ADC);

  }

}
