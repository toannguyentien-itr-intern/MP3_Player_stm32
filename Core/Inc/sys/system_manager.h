/**
 * @file       system_manager.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Header file for system_manager
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __SYSTEM_MANAGER_H
#define __SYSTEM_MANAGER_H

/* Includes ----------------------------------------------------------- */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bsp_timer.h"
#include "draw_ui_icons.h"
#include "drv_button.h"
#include "drv_dfplayer.h"
#include "drv_rotation_sensor.h"
#include "drv_ssd1306.h"
#include "fonts.h"
#include "list_song.h"
#include "system_display.h"


/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */

/**
 * @brief System manager status
 */
typedef enum
{
  SYSTEM_MANAGER_OK,
  SYSTEM_MANAGER_ERROR,
} system_manager_error_t;

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Initialize the system manager
 *
 * This function initializes the display and timer.
 *
 * @param      None
 *
 * @attention  This function must be called before any other system manager functions.
 *
 * @return     System status
 *  - SYSTEM_MANAGER_OK: Success
 *  - SYSTEM_MANAGER_ERROR: Error
 */
system_manager_error_t system_manager_init(void);

/**
 * @brief  Run the system manager
 *
 * This function runs the main loop of the system manager, checking the state and updating the display
 * accordingly.
 *
 * @param      None
 *
 * @attention  This function contains an infinite loop and will only return if an error occurs.
 *
 * @return     System status
 *  - SYSTEM_MANAGER_OK: Success
 *  - SYSTEM_MANAGER_ERROR: Error
 */
system_manager_error_t system_manager_run(void);

#endif /* __SYSTEM_MANAGER_H */

/* End of file -------------------------------------------------------- */
