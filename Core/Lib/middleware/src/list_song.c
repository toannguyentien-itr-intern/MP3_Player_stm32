/*
 * list_song.c
 *
 *  Created on: Aug 7, 2024
 *      Author: MTC-TTM
 */

#include "list_song.h"


// Array of songs
static song_info_struct_t list_song_index[LIST_SONG_QUANTITY] =
{
    {SONG_1_TITLE, SONG_1_AUTHOR},
    {SONG_2_TITLE, SONG_2_AUTHOR},
    {SONG_3_TITLE, SONG_3_AUTHOR},
    {SONG_4_TITLE, SONG_4_AUTHOR},
    {SONG_5_TITLE, SONG_5_AUTHOR},
    {SONG_6_TITLE, SONG_6_AUTHOR},
    {SONG_7_TITLE, SONG_7_AUTHOR},
    {SONG_8_TITLE, SONG_8_AUTHOR},
    {SONG_9_TITLE, SONG_9_AUTHOR},
    {SONG_10_TITLE, SONG_10_AUTHOR}
};

// Function to get the number of songs
uint8_t get_list_song_size(void)
{
    return LIST_SONG_QUANTITY;
}

// Function to get song information by  index
uint8_t *get_song_name_info (uint8_t index)
{
  uint8_t struct_index = index - 1;

  uint8_t *song_name_info =  list_song_index[struct_index].song_name;

  return song_name_info;
}

uint8_t *get_author_name_info (uint8_t index)
{
  uint8_t struct_index = index - 1;

  uint8_t *author_name_info =  list_song_index[struct_index].author_name;

  return author_name_info;
}

