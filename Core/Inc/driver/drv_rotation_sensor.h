/**
 * @file       drv_rotation_sensor.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Toan Nguyen
 *
 * @brief      Header file for drv_rotation_sensor
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __DRV_ROTATION_SENSOR_H
#define __DRV_ROTATION_SENSOR_H

/* Includes ----------------------------------------------------------- */
#include <bsp_rotation_sensor.h>
#include <bsp_timer.h>

/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Initialize the rotation sensor.
 *
 * @attention  This function starts the ADC for the rotation sensor.
 *
 * @return      void
 */
void rotation_sensor_init();

/**
 * @brief  Detect volume change using the rotation sensor.
 *
 * @attention  This function checks if there has been a change in the ADC value indicating a volume change.
 *
 * @return      The ADC flag status indicating volume change.
 */
uint8_t rotation_sensor_detect_volume_change();

/**
 * @brief  Get the current volume from the rotation sensor.
 *
 * @attention  This function calculates the volume based on the ADC value.
 *
 * @return      The current volume.
 */
uint8_t rotation_sensor_get_volume();

#endif /* __DRIVER_ROTATION_SENSOR_H */

/* End of file -------------------------------------------------------- */
