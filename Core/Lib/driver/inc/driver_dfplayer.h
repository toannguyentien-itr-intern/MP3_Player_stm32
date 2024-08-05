/*
 * driver_dfplayer.h
 *
 *  Created on: Aug 3, 2024
 *      Author: MTC-TTM
 */

#ifndef LIB_DRIVER_DFPLAYER_H_
#define LIB_DRIVER_DFPLAYER_H_

#include <bsp_dfplayer.h>
#include <bsp_timer.h>


typedef struct
{
	uint8_t 	start_byte;
	uint8_t 	version;
	uint8_t 	length;
	uint8_t 	id_command;
	uint8_t 	feedback;
	uint8_t 	para_byte_high;
	uint8_t		para_byte_low;
	uint8_t		check_sum_high;
	uint8_t		check_sum_low;
	uint8_t 	end_byte;

} packet_dfplayer_data_t;

typedef enum
{
	default_mode = 0,
	repeat_mode,
	random_mode
} dfplayer_playback_mode_t;


void dfplayer_test();

#endif /* LIB_DRIVER_DFPLAYER_H_ */
