/*
 * list_song.h
 *
 *  Created on: Aug 7, 2024
 *      Author: MTC-TTM
 */

#ifndef LIB_MIDDLEWARE_INC_LIST_SONG_H_
#define LIB_MIDDLEWARE_INC_LIST_SONG_H_

#include "stddef.h"
#include "stdint.h"

// Macros to define song titles and authors
#define SONG_1_TITLE     "Short_Ghe_qua"
#define SONG_1_AUTHOR    "Kim_Xuan_cover"

#define SONG_2_TITLE     "Short_River_flows_in_you"
#define SONG_2_AUTHOR    "Unknown_piano_cover"

#define SONG_3_TITLE     "Short_Noi_Nay_co_anh"
#define SONG_3_AUTHOR    "Nguyen_Danh_Tu_Guitar_cover"

#define SONG_4_TITLE     "Short_Co_hen_voi_thanh_xuan"
#define SONG_4_AUTHOR    "Tung_Tic_Guitar_cover"

#define SONG_5_TITLE     "Short_Khi_con_mo_dan_phai"
#define SONG_5_AUTHOR    "Tez_Myra_Tran"

#define SONG_6_TITLE     "Full_Mat_Moc"
#define SONG_6_AUTHOR    "Ngoc_VAnh_Nhi"

#define SONG_7_TITLE     "Full_Cho_Toi_Lang_Thang"
#define SONG_7_AUTHOR    "Ngot_Den"

#define SONG_8_TITLE     "Full_Con_mua_thang_5"
#define SONG_8_AUTHOR    "Tran_Lap_Tung_Duong"

#define SONG_9_TITLE     "Full_Dua_nhau_di_tron"
#define SONG_9_AUTHOR    "Den_Linh_cao"

#define SONG_10_TITLE    "Full_Dung_lam_trai_tim_anh_dau"
#define SONG_10_AUTHOR   "Son_Tung"

#define LIST_SONG_QUANTITY  10

// Structure to access song information
typedef struct
{
    char* song_name;
    char* author_name;
} song_info_struct_t;



// Function to get the number of songs
uint8_t get_list_song_size(void);

// Function to get song information by index
char *get_song_name_info (uint8_t index);

char *get_author_name_info (uint8_t index);

#endif /* LIB_MIDDLEWARE_INC_LIST_SONG_H_ */
