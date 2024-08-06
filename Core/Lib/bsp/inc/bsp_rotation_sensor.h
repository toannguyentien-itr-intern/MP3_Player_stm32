/*
 * bsp_adc.h
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */

#ifndef LIB_BSP_ROTATION_SENSOR_H_
#define LIB_BSP_ROTATION_SENSOR_H_

#include "stm32f4xx_hal.h"



void bsp_adc_start (void);

void bsp_adc_stop (void);

uint32_t bsp_get_adc_value (void);

uint8_t bsp_check_adc_flag (void);



#endif /* LIB_BSP_ROTATION_SENSOR_H_ */
