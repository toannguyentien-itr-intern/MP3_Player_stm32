/**
 * @file       bsp_button.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Source file for bsp_button
 *
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_button.h"

/* Private defines ---------------------------------------------------- */
static bool bsp_button_init_one(button_t *button, button_id_t button_id, GPIO_TypeDef *button_port,
                                uint16_t button_pin);
/* Private enumerate/structure ---------------------------------------- */
typedef GPIO_PinState (*button_value_t)(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
bool bsp_button_init(button_t *button)
{
  if (bsp_button_init_one(&button[BUTTON_LEFT - 1], BUTTON_LEFT, BUTTON_LEFT_GPIO_Port, BUTTON_LEFT_Pin) &&
      bsp_button_init_one(&button[BUTTON_SELECT - 1], BUTTON_SELECT, BUTTON_SELECT_GPIO_Port,
                          BUTTON_SELECT_Pin) &&
      bsp_button_init_one(&button[BUTTON_RIGHT - 1], BUTTON_RIGHT, BUTTON_RIGHT_GPIO_Port,
                          BUTTON_RIGHT_Pin) &&
      bsp_button_init_one(&button[BUTTON_TEST - 1], BUTTON_TEST, BUTTON_TEST_GPIO_Port, BUTTON_TEST_Pin) ==
      true)
    return true;
  return false;
}
/* Private definitions ----------------------------------------------- */
static bool bsp_button_init_one(button_t *button, button_id_t button_id, GPIO_TypeDef *button_port,
                                uint16_t button_pin)
{
  button->gpio_port = button_port;
  button->gpio_pin  = button_pin;
  button->state     = IDLE;

  return true;
}

button_event_t bsp_button_check_state(button_id_t button_id, bool *interrupt_trigger, button_t *button)
{
  button_event_t event = INVALID_EVENT;

  // Helper function to read the button state
  bool is_button_pressed() { return HAL_GPIO_ReadPin(button->gpio_port, button->gpio_pin) == GPIO_PIN_RESET; }

  // Helper function to check if timeout has occurred
  bool is_timeout_exceeded(uint32_t timeout) { return HAL_GetTick() > timeout; }

  switch (button->state)
  {
    case IDLE:
      if (*interrupt_trigger && is_button_pressed())
      {
        button->state   = WAIT_PRESS_TIMEOUT;
        button->timeout = HAL_GetTick() + 20;  // Set max press time to 20ms to detect press event
      }
      break;

    case WAIT_PRESS_TIMEOUT:
      if (is_button_pressed() && is_timeout_exceeded(button->timeout))
      {
        button->state   = WAIT_CLICK_TIMEOUT;
        button->timeout = HAL_GetTick() + 180;  // Set max press time to 200ms to detect click event
      }
      else if (!is_button_pressed() && !is_timeout_exceeded(button->timeout))
      {
        button->state = IDLE;
      }
      break;

    case WAIT_CLICK_TIMEOUT:
      if (!is_button_pressed() && !is_timeout_exceeded(button->timeout))
      {
        button->state = IDLE;
        event         = CLICK_EVENT;  // Click handle
      }
      else if (is_button_pressed() && is_timeout_exceeded(button->timeout))
      {
        button->state   = WAIT_HOLD_TIMEOUT;
        button->timeout = HAL_GetTick() + 500;  // Set max press time to 500ms to detect hold event
      }
      break;

    case WAIT_HOLD_TIMEOUT:
      if (is_button_pressed() && is_timeout_exceeded(button->timeout))
      {
        event = HOLD_EVENT;  // Holding timeout handle
      }
      else if (!is_button_pressed())
      {
        button->state = IDLE;
      }
      break;

    default:
      button->state = IDLE;
      break;
  }

  // Reset interrupt variable
  *interrupt_trigger = false;
  return event;
}

/* End of file -------------------------------------------------------- */
