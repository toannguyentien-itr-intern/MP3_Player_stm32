/**
 * @file       drv_rotation_sensor.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-08-01
 * @author     Toan Nguyen
 *
 * @brief      Source file for drv_rotation_sensor
 *
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "drv_rotation_sensor.h"

#include "stdlib.h"

/* Private defines ---------------------------------------------------- */
#define ADC_MAX_VALUE 4095
#define MAX_VOLUME    31

extern ADC_HandleTypeDef hadc1;

volatile float   temp;
volatile uint8_t driver_volume_value;

#define ROTATION_ADC &hadc1
/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
void rotation_sensor_init() { bsp_adc_start(); }

uint8_t rotation_sensor_detect_volume_change() { return bsp_check_adc_flag(); }

uint8_t rotation_sensor_get_volume()
{
  driver_volume_value = (bsp_get_adc_value() * MAX_VOLUME) / ADC_MAX_VALUE;

  return driver_volume_value;
}
/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
