/*
 * bsp_adc.c
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */


#include "bsp_adc.h"

extern ADC_HandleTypeDef hadc1;

#define ROTATION_ADC &hadc1


void bsp_adc_start (void)
{
    HAL_ADC_Start(ROTATION_ADC);
}

void bsp_adc_stop (void)
{
    HAL_ADC_Stop(ROTATION_ADC);
}
