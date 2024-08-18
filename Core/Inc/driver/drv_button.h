/**
 * @file       drv_button.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-08-8
 * @author     Tuan Nguyen
 *
 * @brief      Header file for button driver
 *
 * @note       This file contains the definitions and function prototypes for handling button inputs.
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __DRV_BUTTON_H
#define __DRV_BUTTON_H

/* Includes ----------------------------------------------------------- */
#include <stdint.h>

#include "stm32f4xx_hal.h"

/* Public defines ----------------------------------------------------- */
#define NUM_BUTTONS             4    /*!< Number of buttons */
#define TICK                    10   /*!< Tick interval in milliseconds */
#define DEBOUNCE_TIME           20   /*!< Debounce time in milliseconds */
#define HOLD_THRESHOLD          500 /*!< Threshold for hold detection in milliseconds */
#define DOUBLE_CLICK_TIME       100  /*!< Time window for detecting double-clicks */

/* Button states ------------------------------------------------------ */
#define UNPRESSED_STATE         0 /*!< Unpressed state of the button */
#define PRESSED_STATE           1 /*!< Pressed state of the button */

/* Button pin definitions --------------------------------------------- */
#define BUTTON_LEFT_Pin         GPIO_PIN_4
#define BUTTON_LEFT_GPIO_Port   GPIOA
#define BUTTON_SELECT_Pin       GPIO_PIN_5
#define BUTTON_SELECT_GPIO_Port GPIOA
#define BUTTON_RIGHT_Pin        GPIO_PIN_12
#define BUTTON_RIGHT_GPIO_Port  GPIOB
#define BUTTON_TEST_Pin         GPIO_PIN_0
#define BUTTON_TEST_GPIO_Port   GPIOA

/* Public enumerate/structure ----------------------------------------- */

/**
 * @brief Button structure definition
 */
typedef struct
{
  uint16_t      pin;                /*!< GPIO pin number */
  GPIO_TypeDef *port;               /*!< GPIO port */
  int           state;              /*!< Current state of the button */
  int           last_state;         /*!< Last state of the button */
  int           last_stable_state;  /*!< Last stable state of the button */
  int           debounce_counter;   /*!< Debounce counter */
  int           press_counter;      /*!< Press counter */
  int           hold_counter;       /*!< Hold counter */
  int           single_click_flag;  /*!< Single click flag */
  int           hold_flag;          /*!< Hold flag */
} drv_button_t;

/* Public variables --------------------------------------------------- */
extern drv_button_t buttons[NUM_BUTTONS]; /*!< Array of button structures */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Update the state of a button
 *
 * @param[in]  button  Pointer to the button structure
 */
void update_button_state(drv_button_t *button);

/**
 * @brief  Get the key input from all buttons
 */
void get_key_input(void);

/**
 * @brief  Check if a button is pressed
 *
 * @param[in]  index  Index of the button
 * @return     1 if the button is pressed, 0 otherwise
 */
int is_button_pressed(int index);

/**
 * @brief  Check if a button is held
 *
 * @param[in]  index  Index of the button
 * @return     1 if the button is held, 0 otherwise
 */
int is_button_held(int index);

#endif  // __DRV_BUTTON_H

/* End of file -------------------------------------------------------- */
