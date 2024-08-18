/**
 * @file       bsp_timer.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Source file for bsp_timer
 *
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_timer.h"

#include <drv_button.h>
#include <stdint.h>

/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
void bsp_timer_init() { HAL_TIM_Base_Start_IT(&htim2); }
uint32_t bsp_get_tick() {return HAL_GetTick();}
void bsp_delay(uint32_t delay) { HAL_Delay(delay); }
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
  if (htim->Instance == htim2.Instance)
  {
    get_key_input();
  }
}
  /* Private definitions ----------------------------------------------- */

  /* End of file -------------------------------------------------------- */
