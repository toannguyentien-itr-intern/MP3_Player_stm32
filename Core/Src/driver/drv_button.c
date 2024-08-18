/**
 * @file       drv_button.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-08-12
 * @author     Tuan Nguyen
 *
 * @brief      Source file for button driver
 *
 * @note       This file contains the implementation of functions for handling button inputs.
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "drv_button.h"

#include "bsp_gpio.h"
#include "draw_ui_icons.h"

/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */
drv_button_t buttons[NUM_BUTTONS] = {
{BUTTON_LEFT_Pin, BUTTON_LEFT_GPIO_Port, UNPRESSED_STATE, UNPRESSED_STATE, UNPRESSED_STATE, 0, 0, 0, 0, 0},
{BUTTON_SELECT_Pin, BUTTON_SELECT_GPIO_Port, UNPRESSED_STATE, UNPRESSED_STATE, UNPRESSED_STATE, 0, 0, 0, 0,
 0},
{BUTTON_RIGHT_Pin, BUTTON_RIGHT_GPIO_Port, UNPRESSED_STATE, UNPRESSED_STATE, UNPRESSED_STATE, 0, 0, 0, 0, 0},
{BUTTON_TEST_Pin, BUTTON_TEST_GPIO_Port, UNPRESSED_STATE, UNPRESSED_STATE, UNPRESSED_STATE, 0, 0, 0, 0, 0}};

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */

/**
 * @brief  Update the state of a button
 *
 * @param[in]  button  Pointer to the button structure
 */
void update_button_state(drv_button_t *button)
{
  int current_state = bsp_gpio_read_pin(button->port, button->pin);

  // Debouncing
  if (current_state != button->last_state)
  {
    button->debounce_counter = DEBOUNCE_TIME / TICK;
  }
  else if (button->debounce_counter > 0)
  {
    button->debounce_counter--;
  }

  if (button->debounce_counter == 0)
  {
    // Stable state achieved
    if (current_state != button->last_stable_state)
    {
      button->last_stable_state = current_state;

      // last_stable_state == UNPRESSED_STATE and current_state == PRESSED_STATE
      if (current_state == PRESSED_STATE)
      {
        button->hold_counter = 0;  // Reset hold counter when the button is pressed
      }

      // last_stable_state == PRESSED_STATE and current_state == UNPRESSED_STATE
      else if (current_state == UNPRESSED_STATE)
      {
        // Set hold flag if hold threshold was met, otherwise set single click flag
        if (button->hold_counter >= (HOLD_THRESHOLD / TICK))
        {
          button->hold_flag = 1;
        }
        else
        {
          button->single_click_flag = 1;
        }
        button->hold_counter = 0;  // Reset hold counter after release
      }
    }

    // Increment hold counter while button is pressed
    if (button->last_stable_state == PRESSED_STATE)
    {
      button->hold_counter++;
    }
  }

  button->last_state = current_state;
}

/**
 * @brief  Get the key input from all buttons
 */
void get_key_input()
{
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    update_button_state(&buttons[i]);
  }
}

/**
 * @brief  Check if a button is pressed
 *
 * @param[in]  index  Index of the button
 * @return     1 if the button is pressed, 0 otherwise
 */
int is_button_pressed(int index)
{
  if (buttons[index].single_click_flag == 1)
  {
    buttons[index].single_click_flag = 0;
    return 1;
  }
  return 0;
}

/**
 * @brief  Check if a button is held
 *
 * @param[in]  index  Index of the button
 * @return     1 if the button is held, 0 otherwise
 */
int is_button_held(int index)
{
  if (buttons[index].hold_flag == 1)
  {
    buttons[index].hold_flag = 0;
    return 1;
  }
  return 0;
}

/**
 * @brief  GPIO EXTI callback function
 *
 * @param[in]  GPIO_Pin  GPIO pin that triggered the interrupt
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == BUTTON_LEFT_Pin)
  {
    if (ssd1306_get_scroll_flag())
    {
      ssd1306_set_scroll_flag(false);
    }
  }

  if (GPIO_Pin == BUTTON_SELECT_Pin)
  {
    if (ssd1306_get_scroll_flag())
    {
      ssd1306_set_scroll_flag(false);
    }
  }

  if (GPIO_Pin == BUTTON_RIGHT_Pin)
  {
    if (ssd1306_get_scroll_flag())
    {
      ssd1306_set_scroll_flag(false);
    }
  }

  if (GPIO_Pin == BUTTON_TEST_Pin)
  {
    // Add any specific action for BUTTON_TEST_Pin if needed
  }
}
/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
