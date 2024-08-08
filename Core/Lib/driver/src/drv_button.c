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
#include "drv_button.h"

#include "draw_ui_icons.h"
#include "drv_ssd1306.h"

/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */
static button_t     button[MAX_BUTTONS];
static bool         button_initialized[MAX_BUTTONS];
static drv_button_t drv_button;
/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
bool drv_button_init(void)
{
  bsp_button_init(button);

  for (uint8_t i = 0; i < MAX_BUTTONS; i++)
  {
    button_initialized[i] = false;
  }

  drv_button.button_event_button_left   = INVALID_EVENT;
  drv_button.button_event_button_select = INVALID_EVENT;
  drv_button.button_event_button_right  = INVALID_EVENT;
  drv_button.button_event_button_test   = INVALID_EVENT;

  drv_button.button_event_button_left   = false;
  drv_button.button_event_button_select = false;
  drv_button.button_event_button_right  = false;
  drv_button.button_event_button_test   = false;

  drv_button.button_left_interrupt_p   = &drv_button.button_left_interrupt;
  drv_button.button_select_interrupt_p = &drv_button.button_select_interrupt;
  drv_button.button_right_interrupt_p  = &drv_button.button_right_interrupt;
  drv_button.button_test_interrupt_p   = &drv_button.button_test_interrupt;

  return true;
}

void drv_button_check_event(button_name_t *button_state)
{
  /*
  drv_button.button_event_button_left =
  bsp_button_check_state(BUTTON_LEFT, drv_button.button_left_interrupt_p, &button[BUTTON_LEFT - 1]);
  drv_button.button_event_button_select =
  bsp_button_check_state(BUTTON_SELECT, drv_button.button_select_interrupt_p, &button[BUTTON_SELECT - 1]);
  drv_button.button_event_button_right =
  bsp_button_check_state(BUTTON_RIGHT, drv_button.button_right_interrupt_p, &button[BUTTON_RIGHT - 1]);
  drv_button.button_event_button_test =
  bsp_button_check_state(BUTTON_TEST, drv_button.button_test_interrupt_p, &button[BUTTON_TEST - 1]);

  if (drv_button.button_event_button_left == CLICK_EVENT)  // LEFT
  {
    *button_state = CLICK_LEFT_BUTTON;
  }
  else if (drv_button.button_event_button_left == HOLD_EVENT)
  {
    *button_state = HOLD_LEFT_BUTTON;
  }

  if (drv_button.button_event_button_select == CLICK_EVENT)  // SELECT
  {
    *button_state = CLICK_SELECT_BUTTON;
  }
  else if (drv_button.button_event_button_select == HOLD_EVENT)
  {
    *button_state = HOLD_SELECT_BUTTON;
  }

  if (drv_button.button_event_button_right == CLICK_EVENT)  // Right
  {
    *button_state = CLICK_RIGHT_BUTTON;
  }

  else if (drv_button.button_event_button_right == HOLD_EVENT)
  {
    *button_state = HOLD_RIGHT_BUTTON;
  }

  if (drv_button.button_event_button_test == CLICK_EVENT)  // TEST
  {
    *button_state = CLICK_TEST_BUTTON;
  }
  else if (drv_button.button_event_button_test == HOLD_EVENT)
  {
    *button_state = HOLD_TEST_BUTTON;
  }

  if (drv_button.button_event_button_left == INVALID_EVENT &&
      drv_button.button_event_button_select == INVALID_EVENT &&
      drv_button.button_event_button_right == INVALID_EVENT &&
      drv_button.button_event_button_test == INVALID_EVENT)
  {
    *button_state = NO_EVENT;
  }
  */
  // Define arrays for button IDs, events, and interrupt pointers
  button_id_t     button_ids[MAX_BUTTONS]    = {BUTTON_LEFT, BUTTON_SELECT, BUTTON_RIGHT, BUTTON_TEST};
  button_event_t *button_events[MAX_BUTTONS] = {
  &drv_button.button_event_button_left, &drv_button.button_event_button_select,
  &drv_button.button_event_button_right, &drv_button.button_event_button_test};
  bool *interrupt_pointers[MAX_BUTTONS] = {
  drv_button.button_left_interrupt_p, drv_button.button_select_interrupt_p,
  drv_button.button_right_interrupt_p, drv_button.button_test_interrupt_p};
  button_name_t click_events[MAX_BUTTONS] = {CLICK_LEFT_BUTTON, CLICK_SELECT_BUTTON, CLICK_RIGHT_BUTTON,
                                             CLICK_TEST_BUTTON};
  button_name_t hold_events[MAX_BUTTONS]  = {HOLD_LEFT_BUTTON, HOLD_SELECT_BUTTON, HOLD_RIGHT_BUTTON,
                                             HOLD_TEST_BUTTON};

  // Initialize button state to NO_EVENT
  *button_state = NO_EVENT;

  // Check the state of each button
  for (int i = 0; i < MAX_BUTTONS; i++)
  {
    *button_events[i] =
    bsp_button_check_state(button_ids[i], interrupt_pointers[i], &button[button_ids[i] - 1]);

    if (*button_events[i] == CLICK_EVENT)
    {
      *button_state = click_events[i];
    }
    else if (*button_events[i] == HOLD_EVENT)
    {
      *button_state = hold_events[i];
    }
  }

  // Check if all button events are INVALID_EVENT
  bool all_invalid = true;
  for (int i = 0; i < MAX_BUTTONS; i++)
  {
    if (*button_events[i] != INVALID_EVENT)
    {
      all_invalid = false;
      break;
    }
  }

  if (all_invalid)
  {
    *button_state = NO_EVENT;
  }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == BUTTON_LEFT_Pin)
    drv_button.button_left_interrupt = true;

  if (GPIO_Pin == BUTTON_SELECT_Pin)
    drv_button.button_select_interrupt = true;

  if (GPIO_Pin == BUTTON_RIGHT_Pin)
    drv_button.button_right_interrupt = true;

  if (GPIO_Pin == BUTTON_TEST_Pin)
    drv_button.button_test_interrupt = true;
}

/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
