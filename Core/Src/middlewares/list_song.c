/**
 * @file       list_song.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-08-12
 * @author     Tuan Nguyen
 *
 * @brief      Source file for song list management
 *
 * @note       This file contains the implementation of functions for managing a list of songs.
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "list_song.h"

/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */
/**
 * @brief Array of songs
 */
static const song_info_struct_t list_song_index[LIST_SONG_QUANTITY] = {
{SONG_1_TITLE, SONG_1_AUTHOR},  {SONG_2_TITLE, SONG_2_AUTHOR}, {SONG_3_TITLE, SONG_3_AUTHOR},
{SONG_4_TITLE, SONG_4_AUTHOR},  {SONG_5_TITLE, SONG_5_AUTHOR}, {SONG_6_TITLE, SONG_6_AUTHOR},
{SONG_7_TITLE, SONG_7_AUTHOR},  {SONG_8_TITLE, SONG_8_AUTHOR}, {SONG_9_TITLE, SONG_9_AUTHOR},
{SONG_10_TITLE, SONG_10_AUTHOR}};

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */

uint8_t get_list_song_size(void) { return LIST_SONG_QUANTITY; }

const char *get_song_name_info(uint8_t index)
{
  if (index >= LIST_SONG_QUANTITY)
  {
    return NULL;  // Return NULL if index is out of range
  }
  return list_song_index[index].song_name;
}

const char *get_author_name_info(uint8_t index)
{
  if (index >= LIST_SONG_QUANTITY)
  {
    return NULL;  // Return NULL if index is out of range
  }
  return list_song_index[index].author_name;
}
/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */