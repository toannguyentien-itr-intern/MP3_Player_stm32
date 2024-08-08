/**
 * @file       bsp_gpio.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Header file for bsp_gpio
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

/* Includes ----------------------------------------------------------- */
#include <stdbool.h>
#include <stdint.h>

#include "stm32f4xx_hal.h"

/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief This function set the state of GPIO pin
 *
 * @param[in] gpio_port     GPIO port
 * @param[in] gpio_pin      GPIO pin
 * @param[in] state             GPIO state
 *
 * @attention None
 *
 * @return    void
 */
void bsp_gpio_write_pin(GPIO_TypeDef *gpio_port, uint16_t gpio_pin, uint8_t state);

/**
 * @brief This function read the state of GPIO pin
 *
 * @param[in] gpio_port     gpio port
 * @param[in] gpio_pin      gpio pin
 * @attention None
 *
 * @return
 * - true
 * - false
 */
bool bsp_gpio_read_pin(GPIO_TypeDef *gpio_port, uint16_t gpio_pin);

#endif /* __BSP_GPIO_H */

/* End of file -------------------------------------------------------- */
