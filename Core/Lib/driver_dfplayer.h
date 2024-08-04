/*
 * driver_dfplayer.h
 *
 *  Created on: Aug 3, 2024
 *      Author: MTC-TTM
 */

#ifndef LIB_DRIVER_DFPLAYER_H_
#define LIB_DRIVER_DFPLAYER_H_

#include "bsp_dfplayer.h"


typedef struct
{
	uint8_t 	start_byte;
	uint8_t 	version;
	uint8_t 	length;
	uint8_t 	id_command;
	uint8_t 	feedback;
	uint8_t 	byte_para_high;
	uint8_t		byte_para_low;
	uint16_t	check_sum;
	uint8_t 	end_byte;

} packet_dfrplayer_data_t;

#define PACKET_TRANSMIT_DATA ((uint8_t*)&dfr_player)

#define PACKET_SIZE 10

#endif /* LIB_DRIVER_DFPLAYER_H_ */
