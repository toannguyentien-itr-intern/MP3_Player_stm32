/*
 * bsp_dfplayer.h
 *
 *  Created on: Aug 3, 2024
 *      Author: MTC-TTM
 */

#ifndef LIB_BSP_DFPLAYER_H_
#define LIB_BSP_DFPLAYER_H_

#include "stm32f4xx_hal.h"

void bsp_transmit_data (uint8_t* data, uint8_t size);
void bsp_receive_data (uint8_t* data, uint8_t size);
uint8_t bsp_check_transmit_status (void);
uint8_t bsp_check_receive_status (void);



#endif /* LIB_BSP_DFPLAYER_H_ */
