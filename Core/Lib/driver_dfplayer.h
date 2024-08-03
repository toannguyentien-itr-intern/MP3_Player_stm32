/*
 * driver_dfplayer.h
 *
 *  Created on: Aug 3, 2024
 *      Author: MTC-TTM
 */

#ifndef LIB_DRIVER_DFPLAYER_H_
#define LIB_DRIVER_DFPLAYER_H_

#include "bsp_dfplayer.h"

#define START_BYTE	0x7E
#define VERSION 	0xEF
#define	LENGTH		0x06
#define	FEEDBACK 	0x01
#define END_BYTE	0x7E


typedef struct
{
	uint8_t 	start_byte;
	uint8_t 	version;
	uint8_t 	length;
	uint8_t 	command;
	uint8_t 	feedack;
	uint8_t 	byte_data_high;
	uint8_t		byte_data_low;
	uint16_t	check_sum;
	uint8_t 	end_byte;

} packet_dfrplayer_data_t;

#endif /* LIB_DRIVER_DFPLAYER_H_ */
