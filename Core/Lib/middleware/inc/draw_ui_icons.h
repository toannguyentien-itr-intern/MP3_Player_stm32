/**
 * @file       draw_ui_icons.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Header file for draw_ui_icons
 *
 * @note       This file is for storing and drawing screens ui and bitmaps
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __DRAW_UI_ICONS_H
#define __DRAW_UI_ICONS_H

/* Includes ----------------------------------------------------------- */
#include "drv_ssd1306.h"
#include "fonts.h"
/* Public defines ----------------------------------------------------- */
#ifdef SSD1306_INCLUDE_FONT_6X8
extern const drv_ssd1306_font_t font_6x8;
#endif
#ifdef SSD1306_INCLUDE_FONT_7X10
extern const drv_ssd1306_font_t font_7x10;
#endif
#ifdef SSD1306_INCLUDE_FONT_11X18
extern const drv_ssd1306_font_t font_11x18;
#endif
#ifdef SSD1306_INCLUDE_FONT_16X26
extern const drv_ssd1306_font_t font_16x26;
#endif
#ifdef SSD1306_INCLUDE_FONT_16X24
extern const drv_ssd1306_font_t font_16x24;
#endif
#ifdef SSD1306_INCLUDE_FONT_16X15
extern const drv_ssd1306_font_t font_16x15;
#endif
/* Public enumerate/structure ----------------------------------------- */

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Draw the starting screen
 *
 * @param[in]   void
 *
 * @attention   This function draws the starting screen by printing the Malkman logo
 *
 * @return      void
 */
void ssd1306_starting_screen(void);

/**
 * @brief  Draw the playlist screen
 *
 * @param[in]   void
 *
 * @attention   None
 *
 * @return      void
 */
void ssd1306_playlist_menu(uint16_t song_id);

void ssd1306_music_player_menu(uint16_t song_id);

void ssd1306_select(uint8_t x, uint8_t y, uint8_t rad, drv_ssd1306_color_t color, const unsigned char* bitmap,
                    uint8_t w, uint8_t h);

void ssd1306_deselect(uint8_t x, uint8_t y, uint8_t rad, drv_ssd1306_color_t color,
                      const unsigned char* bitmap, uint8_t w, uint8_t h);

void ssd1306_icon_transition(uint8_t x, uint8_t y, const unsigned char* bitmap, uint8_t w, uint8_t h,
                             drv_ssd1306_color_t color);
#endif /* __DRAW_UI_ICONS_H */

/* End of file -------------------------------------------------------- */
