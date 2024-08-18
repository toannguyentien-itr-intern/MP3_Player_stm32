/**
 * @file       system_manager.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Source file for system_manager
 *
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "system_manager.h"

/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/**
 * @brief Enumeration for system states
 */
typedef enum
{
  BOOT_STATE = 1,
  WAIT_STATE,
  PLAYLIST_STATE,
  MUSIC_PLAYER_DEFAULT_STATE,
  MUSIC_PLAYER_TITLE_STATE,
  MUSIC_PLAYER_PLAYBACK_STATE,
  MUSIC_PLAYER_PlAY_MODE_STATE,
  INVALID_STATE
} system_state_t;

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/**< Current state of the system */
static system_state_t system_state = BOOT_STATE;

/**< Current song ID */
static int system_song_id = 0;

/**< Current volume */
static int system_sound_volume = 1;

/**< Title state (0 = Not scrolling, 1 = Scrolling) */
static uint8_t system_title_state = 0;

/**< Playback state (0 = Pause, 1 = Play, 99 = Uninitialized) */
static uint8_t system_playback_state = 0;

/**< Play mode state (0 = Once, 1 = Repeat, 2 = Randomize, 99 = Uninitialized) */
static uint8_t system_play_mode_state = 0;

/* Private function prototypes ---------------------------------------- */

/**
 * @brief Check the current state of the system
 *
 * @return The current system state
 */
static system_state_t system_manager_check_state();

/* Function definitions ----------------------------------------------- */
system_manager_error_t system_manager_init(void)
{
  // Initialize the display, dfplayer and timer
  system_display_init();
  dfplayer_init();
  bsp_timer_init();
  rotation_sensor_init();
  system_sound_volume = rotation_sensor_get_volume();

  return SYSTEM_MANAGER_OK;
}

system_manager_error_t system_manager_run(void)
{
  system_manager_error_t status             = SYSTEM_MANAGER_OK;
  system_state_t         system_state_check = BOOT_STATE;

  while (status == SYSTEM_MANAGER_OK)
  {
    // Check the current state of the system
    system_state_check = system_manager_check_state();

    // Update the display based on the current state
    switch (system_state_check)
    {
      case BOOT_STATE:
        system_display_boot_state();
        break;

      case WAIT_STATE:
        system_display_wait_state();
        break;

      case PLAYLIST_STATE:
        system_display_playlist_state(system_song_id, system_sound_volume);
        break;

      case MUSIC_PLAYER_DEFAULT_STATE:
        system_display_music_player_default_state(system_song_id, system_playback_state,
                                                  system_play_mode_state);
        break;

      case MUSIC_PLAYER_TITLE_STATE:
        system_display_music_player_title_state(system_song_id, system_sound_volume);
        break;

      case MUSIC_PLAYER_PLAYBACK_STATE:
        system_display_music_player_playback_state(system_playback_state);
        break;

      case MUSIC_PLAYER_PlAY_MODE_STATE:
        system_display_music_player_play_mode_state(system_play_mode_state);
        break;

      default:
        break;
    }
  }

  return status;
}

/* Private definitions ----------------------------------------------- */

static system_state_t system_manager_check_state()
{
  // Check current volume from rotation sensor
  if (rotation_sensor_detect_volume_change()){
	system_sound_volume = rotation_sensor_get_volume();
  	dfplayer_adjust_volume(system_sound_volume);
  }
  rotation_sensor_init();

  switch (system_state)
  {
    case BOOT_STATE:
      // Transition to WAIT_STATE if button 1 is held
      if (is_button_held(1))
      {
        system_state = WAIT_STATE;
      }
      break;

    case WAIT_STATE:
      // Transition to PLAYLIST_STATE if button 1 is pressed
      if (is_button_pressed(1))
      {
        system_state = PLAYLIST_STATE;
      }
      break;

    case PLAYLIST_STATE:
      // Transition to MUSIC_PLAYER_DEFAULT_STATE if button 1 is pressed
      //ssd1306_set_scroll_flag(1);
      if (is_button_pressed(1))
      {
        system_state = MUSIC_PLAYER_DEFAULT_STATE;
        //ssd1306_set_scroll_flag(0);
        if (system_play_mode_state == 0)
        	dfplayer_normal_mode_play();
        if (system_play_mode_state == 1)
        	dfplayer_repeat_mode_play();
        if (system_play_mode_state == 2)
        {
        	dfplayer_normal_mode_play();
        	system_play_mode_state = 0;
        }
        dfplayer_track_play(system_song_id + 1);
        system_playback_state = 1;  // Set playback state to play
      }

      // Navigate through the playlist
      if (is_button_pressed(2))  		// Navigate down (right button)
        system_song_id++;
      else if (is_button_pressed(0))  	// Navigate up (left button)
        system_song_id--;

      // Wrap around the song index
      if (system_song_id < 0)
        system_song_id = LIST_SONG_QUANTITY - 1;
      if (system_song_id >= LIST_SONG_QUANTITY)
        system_song_id = 0;

      // Adjust volume
      if (is_button_held(2)) // Volume up
      {
        system_sound_volume++;
        if (system_sound_volume > 30)
          system_sound_volume = 30;
        dfplayer_adjust_volume(system_sound_volume);
      }

      if (is_button_held(0)) // Volume down
      {
        system_sound_volume--;
        if (system_sound_volume < 0)
          system_sound_volume = 0;
        dfplayer_adjust_volume(system_sound_volume);
      }
      break;

    case MUSIC_PLAYER_DEFAULT_STATE:
      // Transition to MUSIC_PLAYER_TITLE_STATE
      system_state = MUSIC_PLAYER_TITLE_STATE;
      break;

    case MUSIC_PLAYER_TITLE_STATE:
      // Transition to PLAYLIST_STATE if button 1 is held
      if (is_button_held(1))
        system_state = PLAYLIST_STATE;

      // Toggle title scrolling if button 1 is pressed
      if (is_button_pressed(1))
      {
        switch (system_title_state)
        {
          case 0:
            system_title_state = 1;
            ssd1306_set_scroll_flag(system_title_state);
            break;
          case 1:
            system_title_state = 0;
            ssd1306_set_scroll_flag(system_title_state);
            break;
        }
      }

      // Adjust volume
      if (is_button_held(2)) // Volume up
      {
        system_sound_volume++;
        if (system_sound_volume > 30)
          system_sound_volume = 30;
        dfplayer_adjust_volume(system_sound_volume);
      }

      if (is_button_held(0)) // Volume down
      {
        system_sound_volume--;
        if (system_sound_volume < 0)
          system_sound_volume = 0;
        dfplayer_adjust_volume(system_sound_volume);
      }

      // Navigate to play mode or playback state
      if (is_button_pressed(0))
        system_state = MUSIC_PLAYER_PlAY_MODE_STATE;
      if (is_button_pressed(2))
        system_state = MUSIC_PLAYER_PLAYBACK_STATE;
      break;

    case MUSIC_PLAYER_PLAYBACK_STATE:
      // Toggle playback state if button 1 is pressed
      if (is_button_pressed(1))
        switch (system_playback_state)
        {
          case 0:
            system_playback_state = 1;
            dfplayer_track_play_continue();
            break;
          case 1:
            system_playback_state = 0;
            dfplayer_track_pause();
            break;
          default:
            break;
        }

      // Transition to PLAYLIST_STATE if button 1 is held
      if (is_button_held(1))
        system_state = PLAYLIST_STATE;

      // Navigate to title or play mode state
      if (is_button_pressed(0))
      {
        system_state = MUSIC_PLAYER_TITLE_STATE;
        ssd1306_deselect_fsm(system_playback_state, 99);
      }
      if (is_button_pressed(2))
      {
        system_state = MUSIC_PLAYER_PlAY_MODE_STATE;
        ssd1306_deselect_fsm(system_playback_state, 99);
      }
      break;

    case MUSIC_PLAYER_PlAY_MODE_STATE:
      // Cycle through play modes if button 1 is pressed
      if (is_button_pressed(1))
        switch (system_play_mode_state)
        {
          case 0:
            system_play_mode_state = 1;
            dfplayer_repeat_mode_play();
            break;
          case 1:
            system_play_mode_state = 2;
            dfplayer_random_mode_play();
            break;
          case 2:
            system_play_mode_state = 0;
            dfplayer_normal_mode_play();
          default:
            break;
        }

      // Transition to PLAYLIST_STATE if button 1 is held
      if (is_button_held(1))
        system_state = PLAYLIST_STATE;

      // Navigate to playback or title state
      if (is_button_pressed(0))
      {
        system_state = MUSIC_PLAYER_PLAYBACK_STATE;
        ssd1306_deselect_fsm(99, system_play_mode_state);
      }
      if (is_button_pressed(2))
      {
        system_state = MUSIC_PLAYER_TITLE_STATE;
        ssd1306_deselect_fsm(99, system_play_mode_state);
      }
      break;

    default:
      break;
  }

  return system_state;
}
/* End of file -------------------------------------------------------- */
