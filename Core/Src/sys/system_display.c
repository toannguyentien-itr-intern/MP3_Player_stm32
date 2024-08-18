/**
 * @file       system_display.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Source file for system_display
 *
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "system_display.h"

/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
system_display_error_t system_display_init(void)
{
  if (!(drv_ssd1306_init()))
    return SYSTEM_DISPLAY_ERROR;
  return SYSTEM_DISPLAY_OK;
}

system_display_error_t system_display_boot_state(void)
{
  drv_ssd1306_fill(DRV_SSD1306_COLOR_BLACK);
  return SYSTEM_DISPLAY_OK;
}

system_display_error_t system_display_wait_state(void)
{
  ssd1306_starting_screen();
  return SYSTEM_DISPLAY_OK;
}

system_display_error_t system_display_playlist_state(uint16_t song_id, int volume)
{
  ssd1306_playlist_menu(song_id, volume);
  return SYSTEM_DISPLAY_OK;
}

system_display_error_t system_display_music_player_default_state(uint16_t song_id, uint8_t playback_state,
                                                                 uint8_t play_mode_state)
{
  ssd1306_music_player_menu_default(song_id, playback_state, play_mode_state);
  return SYSTEM_DISPLAY_OK;
}

system_display_error_t system_display_music_player_title_state(uint16_t song_id, int volume)
{
  ssd1306_music_player_menu_title(song_id, volume);
  return SYSTEM_DISPLAY_OK;
}

system_display_error_t system_display_music_player_playback_state(uint8_t state)
{
  switch (state)
  {
    case 0:
      ssd1306_music_player_menu_pause();
      break;
    case 1:
      ssd1306_music_player_menu_play();
      break;
    default:
      break;
  }
  return SYSTEM_DISPLAY_OK;
}

system_display_error_t system_display_music_player_play_mode_state(uint8_t state)
{
  switch (state)
  {
    case 0:
      ssd1306_music_player_menu_once();
      break;
    case 1:
      ssd1306_music_player_menu_repeat();
      break;
    case 2:
      ssd1306_music_player_menu_randomize();
    default:
      break;
  }
  return SYSTEM_DISPLAY_OK;
}

void system_display_update(void) { drv_ssd1306_update_screen(); }
/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
