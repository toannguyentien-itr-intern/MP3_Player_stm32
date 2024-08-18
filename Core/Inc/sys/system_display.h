/**
 * @file       system_display.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Header file for system_display
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __SYSTEM_DISPLAY_H
#define __SYSTEM_DISPLAY_H

/* Includes ----------------------------------------------------------- */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "draw_ui_icons.h"
#include "drv_ssd1306.h"
// #include "list_song.h"
#include "main.h"

/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */

/**
 * @brief System display status
 */
typedef enum
{
  SYSTEM_DISPLAY_OK,
  SYSTEM_DISPLAY_ERROR,
} system_display_error_t;

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Initialize the display
 *
 * This function initializes the SSD1306 display driver.
 *
 * @param      void
 *
 * @attention  This function must be called before any other display functions.
 *
 * @return
 *  - SYSTEM_DISPLAY_OK: Success
 *  - SYSTEM_DISPLAY_ERROR: Error
 */
system_display_error_t system_display_init(void);

/**
 * @brief  Display the boot state
 *
 * This function fills the display with black color to indicate the boot state.
 *
 * @param      void
 *
 * @attention  None
 *
 * @return
 *  - SYSTEM_DISPLAY_OK: Success
 */
system_display_error_t system_display_boot_state(void);

/**
 * @brief  Display the wait state
 *
 * This function shows the starting screen on the display.
 *
 * @param      void
 *
 * @attention  None
 *
 * @return
 *  - SYSTEM_DISPLAY_OK: Success
 */
system_display_error_t system_display_wait_state(void);

/**
 * @brief  Display the playlist state
 *
 * This function shows the playlist menu on the display with the current song ID.
 *
 * @param[in]     song_id  The ID of the current song
 *
 * @attention  None
 *
 * @return
 *  - SYSTEM_DISPLAY_OK: Success
 */
system_display_error_t system_display_playlist_state(uint16_t song_id, int volume);

/**
 * @brief  Display the music player default state
 *
 * This function shows the default music player menu on the display with the current song title, playback
 * state, and play mode state.
 *
 * @param[in]     song_id         The ID of the current song
 * @param[in]     volume		  The current volume
 *
 * @attention  None
 *
 * @return
 *  - SYSTEM_DISPLAY_OK: Success
 */
system_display_error_t system_display_music_player_default_state(uint16_t song_id, uint8_t playback_state,
                                                                 uint8_t play_mode_state);

/**
 * @brief  Display the music player title state
 *
 * This function shows the music player title menu on the display with the current song ID.
 *
 * @param[in]     song_id  The ID of the current song
 *
 * @attention  None
 *
 * @return
 *  - SYSTEM_DISPLAY_OK: Success
 */
system_display_error_t system_display_music_player_title_state(uint16_t song_id, int volume);

/**
 * @brief  Display the music player playback state
 *
 * This function shows the music player playback menu on the display based on the current playback state.
 *
 * @param[in]     state  The current playback state (0 = Pause, 1 = Play)
 *
 * @attention  None
 *
 * @return
 *  - SYSTEM_DISPLAY_OK: Success
 */
system_display_error_t system_display_music_player_playback_state(uint8_t state);

/**
 * @brief  Display the music player play mode state
 *
 * This function shows the music player play mode menu on the display based on the current play mode state.
 *
 * @param[in]  state  The current play mode state (0 = Once, 1 = Repeat, 2 = Randomize)
 *
 * @attention  None
 *
 * @return
 *  - SYSTEM_DISPLAY_OK: Success
 */
system_display_error_t system_display_music_player_play_mode_state(uint8_t state);

void system_display_update(void);
#endif /* __SYSTEM_DISPLAY_H */

/* End of file -------------------------------------------------------- */
