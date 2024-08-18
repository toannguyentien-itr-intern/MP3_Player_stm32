/**
 * @file       list_song.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-08-12
 * @author     Tuan Nguyen
 *
 * @brief      Header file for song list management
 *
 * @note       This file contains the definitions and function prototypes for managing a list of songs.
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __LIST_SONG_H
#define __LIST_SONG_H

/* Includes ----------------------------------------------------------- */
#include "stddef.h"
#include "stdint.h"

/* Public defines ----------------------------------------------------- */
/* Song titles and authors */
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

#define LIST_SONG_QUANTITY 10 /*!< Number of songs in the list */

/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief Structure to access song information
 */
typedef struct
{
  const char *song_name;   /*!< Name of the song */
  const char *author_name; /*!< Name of the author */
} song_info_struct_t;

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Get the number of songs
 *
 * @return Number of songs in the list
 */
uint8_t get_list_song_size(void);

/**
 * @brief  Get song information by index
 *
 * @param[in]  index  Index of the song
 * @return     Pointer to the song name, or NULL if index is out of range
 */
const char *get_song_name_info(uint8_t index);

/**
 * @brief  Get author information by index
 *
 * @param[in]  index  Index of the song
 * @return     Pointer to the author name, or NULL if index is out of range
 */
const char *get_author_name_info(uint8_t index);

#endif /* __LIST_SONG_H */

/* End of file -------------------------------------------------------- */
