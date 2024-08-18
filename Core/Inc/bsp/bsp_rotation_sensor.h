/**
 * @file       bsp_rotation_sensor.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-08-05
 * @author     Toan Nguyen
 *
 * @brief      Header file for bsp_rotation_sensor
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_ROTATION_SENSOR_H
#define __BSP_ROTATION_SENSOR_H

/* Includes ----------------------------------------------------------- */
#include "stm32f4xx_hal.h"

/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Start the ADC conversion with interrupt.
 *
 * @attention  This function starts the ADC conversion in interrupt mode.
 *
 * @return      void
 */
void bsp_adc_start(void);

/**
 * @brief  Stop the ADC conversion with interrupt.
 *
 * @attention  This function stops the ADC conversion in interrupt mode.
 *
 * @return      void
 */
void bsp_adc_stop(void);

/**
 * @brief  Get the ADC value.
 *
 * @attention  This function retrieves the current ADC value.
 *
 * @return      The current ADC value.
 */
uint32_t bsp_get_adc_value(void);

/**
 * @brief  Check the ADC flag status.
 *
 * @attention  This function checks the ADC flag and resets it.
 *
 * @return      The ADC flag status.
 */
uint8_t bsp_check_adc_flag(void);

#endif /* __BSP_ROTATION_SENSOR_H */

/* End of file -------------------------------------------------------- */
