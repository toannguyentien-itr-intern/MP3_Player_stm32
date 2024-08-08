/**
 * @file       drv_button.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Header file for drv_button
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __DRV_BUTTON_H
#define __DRV_BUTTON_H

/* Includes ----------------------------------------------------------- */
#include "bsp_button.h"

/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */

/**
 * @brief Enum to all button events
 */
typedef enum
{
  CLICK_LEFT_BUTTON = 1,
  CLICK_SELECT_BUTTON,
  CLICK_RIGHT_BUTTON,
  CLICK_TEST_BUTTON,

  HOLD_LEFT_BUTTON,
  HOLD_SELECT_BUTTON,
  HOLD_RIGHT_BUTTON,
  HOLD_TEST_BUTTON,

  NO_EVENT
} button_name_t;

/**
 * @brief All variables use for check button events
 */
typedef struct
{
  button_event_t button_event_button_left;
  button_event_t button_event_button_select;
  button_event_t button_event_button_right;
  button_event_t button_event_button_test;

  volatile bool button_left_interrupt;
  bool         *button_left_interrupt_p;
  volatile bool button_select_interrupt;
  bool         *button_select_interrupt_p;
  volatile bool button_right_interrupt;
  bool         *button_right_interrupt_p;
  volatile bool button_test_interrupt;
  bool         *button_test_interrupt_p;
} drv_button_t;
/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */
/**
 * @brief Initialize button
 *
 * @return
 * - true   Success
 * - false  Error
 */
bool drv_button_init(void);

void drv_button_check_event(button_name_t *button_state);

#endif /* __DRV_BUTTON_H */

/* End of file -------------------------------------------------------- */
