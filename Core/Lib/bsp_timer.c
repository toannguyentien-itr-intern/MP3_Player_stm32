/*
 * bsp_timer.c
 *
 *  Created on: Aug 4, 2024
 *      Author: MTC-TTM
 */

#include "bsp_timer.h"

void bsp_delay (uint32_t time_delay)
{
	HAL_Delay(time_delay);
}

