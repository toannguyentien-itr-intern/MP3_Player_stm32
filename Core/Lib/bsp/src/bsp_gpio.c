/**
 * @file       bsp_gpio.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Source file for bsp_gpio
 *
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_gpio.h"
/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
void bsp_gpio_write_pin(GPIO_TypeDef *gpio_port, uint16_t gpio_pin, uint8_t state)
{
  if (state)
    HAL_GPIO_WritePin(gpio_port, gpio_pin, GPIO_PIN_SET);
  else
    HAL_GPIO_WritePin(gpio_port, gpio_pin, GPIO_PIN_RESET);
}
bool bsp_gpio_read_pin(GPIO_TypeDef *gpio_port, uint16_t gpio_pin)
{
  return HAL_GPIO_ReadPin(gpio_port, gpio_pin) == GPIO_PIN_SET ? true : false;
}
/* Private definitions ----------------------------------------------- */
/* End of file -------------------------------------------------------- */
