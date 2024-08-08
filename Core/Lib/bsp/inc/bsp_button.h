/**
 * @file       bsp_button.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Header file for bsp_button
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_BUTTON_H
#define __BSP_BUTTON_H

/* Includes ----------------------------------------------------------- */
#include <stdbool.h>
#include <stdint.h>

#include "stm32f4xx_hal.h"

/* Public defines ----------------------------------------------------- */
#define BUTTON_LEFT_Pin         GPIO_PIN_4
#define BUTTON_LEFT_GPIO_Port   GPIOA
#define BUTTON_LEFT_EXTI_IRQn   EXTI4_IRQn
#define BUTTON_SELECT_Pin       GPIO_PIN_5
#define BUTTON_SELECT_GPIO_Port GPIOA
#define BUTTON_SELECT_EXTI_IRQn EXTI9_5_IRQn
#define BUTTON_RIGHT_Pin        GPIO_PIN_12
#define BUTTON_RIGHT_GPIO_Port  GPIOB
#define BUTTON_RIGHT_EXTI_IRQn  EXTI15_10_IRQn
#define BUTTON_TEST_Pin         GPIO_PIN_0
#define BUTTON_TEST_GPIO_Port   GPIOA
#define BUTTON_TEST_EXTI_IRQn   EXTI0_IRQn

#define MAX_BUTTONS             (4)
/* Public enumerate/structure ----------------------------------------- */
typedef enum
{
  CLICK_EVENT,
  HOLD_EVENT,
  INVALID_EVENT
} button_event_t;

typedef enum
{
  IDLE,
  WAIT_PRESS_TIMEOUT,
  WAIT_CLICK_TIMEOUT,
  WAIT_HOLD_TIMEOUT
} button_state_t;

typedef enum
{
  BUTTON_LEFT = 1,
  BUTTON_SELECT,
  BUTTON_RIGHT,
  BUTTON_TEST
} button_id_t;

typedef struct
{
  button_state_t state;
  GPIO_TypeDef  *gpio_port;
  uint16_t       gpio_pin;
  uint32_t       timeout;
} button_t;
/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief           Initialize button
 *
 * @return
 * - true     Success
 * - false    Error
 */
bool bsp_button_init(button_t *button);

/**
 * @brief                   Check state of button
 *
 * @param[in] button_id         ID of button want to check
 * @param[in] interrupt_trigger Pointer to interrupt button variable
 * @param[in] button            Button object
 *
 * @return button_event_t   Event of current button
 */
button_event_t bsp_button_check_state(button_id_t button_id, bool *interrupt_trigger, button_t *button);

#endif /* __BSP_BUTTON_H */

/* End of file -------------------------------------------------------- */
