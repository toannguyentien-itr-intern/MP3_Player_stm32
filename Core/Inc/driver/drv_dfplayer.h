/**
 * @file       drv_dfplayer.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Toan Nguyen
 *
 * @brief      Header file for drv_dfplayer
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __DRV_DFPLAYER_H
#define __DRV_DFPLAYER_H

/* Includes ----------------------------------------------------------- */
#include <bsp_dfplayer.h>
#include <bsp_timer.h>

/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */
typedef struct
{
  uint8_t start_byte;
  uint8_t version;
  uint8_t length;
  uint8_t id_command;
  uint8_t feedback;
  uint8_t para_byte_high;
  uint8_t para_byte_low;
  uint8_t check_sum_high;
  uint8_t check_sum_low;
  uint8_t end_byte;

} packet_dfplayer_data_t;

typedef enum
{
  default_mode = 0,
  repeat_mode,
  random_mode
} dfplayer_playback_mode_t;
/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Initialize the DFPlayer.
 *
 * @attention  This function pauses any playing track, initializes the playback source to TF card, and sets
 * the initial volume.
 *
 * @return      void
 */
void dfplayer_init(void);

/**
 * @brief  Play a track on the DFPlayer.
 *
 * @param[in]     ordinal_song_number    The ordinal number of the song to play.
 *
 * @attention  This function sends the play track command to the DFPlayer and introduces a delay.
 *
 * @return      void
 */
void dfplayer_track_play(uint16_t ordinal_song_number);

/**
 * @brief  Pause the current track on the DFPlayer.
 *
 * @attention  This function sends the pause command to the DFPlayer.
 *
 * @return      void
 */
void dfplayer_track_pause(void);

/**
 * @brief  Continue playing the current track on the DFPlayer.
 *
 * @attention  This function sends the continue play command to the DFPlayer.
 *
 * @return      void
 */
void dfplayer_track_play_continue(void);

/**
 * @brief  Play tracks in normal mode on the DFPlayer.
 *
 * @attention  This function sends the normal mode command to the DFPlayer.
 *
 * @return      void
 */
void dfplayer_normal_mode_play(void);

/**
 * @brief  Play tracks in repeat mode on the DFPlayer.
 *
 * @attention  This function sends the repeat mode command to the DFPlayer.
 *
 * @return      void
 */
void dfplayer_repeat_mode_play(void);

/**
 * @brief  Play tracks in random mode on the DFPlayer.
 *
 * @attention  This function sends the random mode command to the DFPlayer.
 *
 * @return      void
 */
void dfplayer_random_mode_play(void);

/**
 * @brief  Adjust the volume on the DFPlayer.
 *
 * @param[in]     volume    The volume level to set.
 *
 * @attention  This function sends the set volume command to the DFPlayer.
 *
 * @return      void
 */
void dfplayer_adjust_volume(uint8_t volume);

/**
 * @brief  Test the DFPlayer functionality.
 *
 * @attention  This function initializes the DFPlayer, adjusts the volume, plays specific tracks, and sets the
 * player to random mode.
 *
 * @return      void
 */
void dfplayer_test();

uint8_t dfplayer_get_playing_status(void);

#endif /* __DRV_DFPLAYER_H */

/* End of file -------------------------------------------------------- */
