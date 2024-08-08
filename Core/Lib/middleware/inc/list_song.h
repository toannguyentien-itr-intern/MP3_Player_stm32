/**
 * @file       list_song.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-08-05
 * @author     Toan Nguyen
 *
 * @brief      Header file for list_song
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __LIST_SONG_H
#define __LIST_SONG_H

/* Includes ----------------------------------------------------------- */
#include "stddef.h"
#include "stdint.h"

/* Public defines ----------------------------------------------------- */

// Macros to define song titles and authors
#define SONG_1_TITLE       "Short_Ghe_qua"
#define SONG_1_AUTHOR      "Kim_Xuan_cover"

#define SONG_2_TITLE       "Short_River_flows_in_you"
#define SONG_2_AUTHOR      "Unknown_piano_cover"

#define SONG_3_TITLE       "Short_Noi_Nay_co_anh"
#define SONG_3_AUTHOR      "Nguyen_Danh_Tu_Guitar_cover"

#define SONG_4_TITLE       "Short_Co_hen_voi_thanh_xuan"
#define SONG_4_AUTHOR      "Tung_Tic_Guitar_cover"

#define SONG_5_TITLE       "Short_Khi_con_mo_dan_phai"
#define SONG_5_AUTHOR      "Tez_Myra_Tran"

#define SONG_6_TITLE       "Full_Mat_Moc"
#define SONG_6_AUTHOR      "Ngoc_VAnh_Nhi"

#define SONG_7_TITLE       "Full_Cho_Toi_Lang_Thang"
#define SONG_7_AUTHOR      "Ngot_Den"

#define SONG_8_TITLE       "Full_Con_mua_thang_5"
#define SONG_8_AUTHOR      "Tran_Lap_Tung_Duong"

#define SONG_9_TITLE       "Full_Dua_nhau_di_tron"
#define SONG_9_AUTHOR      "Den_Linh_cao"

#define SONG_10_TITLE      "Full_Dung_lam_trai_tim_anh_dau"
#define SONG_10_AUTHOR     "Son_Tung"

#define LIST_SONG_QUANTITY 10
/* Public enumerate/structure ----------------------------------------- */

typedef struct
{
  char *song_name;
  char *author_name;
} song_info_struct_t;
/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Get the number of songs.
 *
 * @attention   This function returns the total number of songs available.
 *
 * @return      The number of songs.
 */
uint8_t get_list_song_size(void);

/**
 * @brief  Get the song name information by index.
 *
 * @param[in]   index    The index of the song.
 *
 * @attention   This function retrieves the song name information based on the provided index.
 *
 * @return      The song name information.
 */
char *get_song_name_info(uint8_t index);

/**
 * @brief  Get the author name information by index.
 *
 * @param[in]   index    The index of the song.
 *
 * @attention   This function retrieves the author name information based on the provided index.
 *
 * @return      The author name information.
 */
char *get_author_name_info(uint8_t index);

#endif /* __LIST_SONG_H */

/* End of file -------------------------------------------------------- */
