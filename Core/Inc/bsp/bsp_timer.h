/**
 * @file       bsp_timer.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Header file for bsp_timer
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H

/* Includes ----------------------------------------------------------- */
#include "stm32f4xx_hal.h"

/* Public defines ----------------------------------------------------- */
#define USE_TIMER_2
#define BSP_TIMER_2 htim2

#if defined(USE_TIMER_2)
extern TIM_HandleTypeDef BSP_TIMER_2;
#endif
/* Public enumerate/structure ----------------------------------------- */

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

void bsp_timer_init();
uint32_t bsp_get_tick();
void bsp_delay(uint32_t delay);
#endif /* __BSP_TIMER_H */

/* End of file -------------------------------------------------------- */
