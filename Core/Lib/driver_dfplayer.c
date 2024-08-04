/*
 * driver_dfplayer.c
 *
 *  Created on: Aug 3, 2024
 *      Author: MTC-TTM
 */

#include "driver_dfplayer.h"

#define START_BYTE			0x7E
#define VERSION 			0xEF
#define	LENGTH				0x06
#define	ENABLE_FEEDBACK 	0x01
#define END_BYTE			0x7E



packet_dfrplayer_data_t dfr_player =
{
    .start_byte = START_BYTE,
    .version	= VERSION,
    .length 	= LENGTH,
	.feedback	= ENABLE_FEEDBACK
};

static uint16_t dfrplayer_cal_checksum (uint8_t id_command, uint8_t byte_para_high, uint8_t byte_para_low)
{
	uint16_t temp_checksum = VERSION + LENGTH + id_command + ENABLE_FEEDBACK + byte_para_high + byte_para_low;
	temp_checksum = 0-temp_checksum;

	return temp_checksum;
}

void dfrplayer_send_command (uint8_t id_command, uint8_t byte_data_high, uint8_t byte_data_low)
{
	dfr_player.id_command = id_command;

	dfr_player.byte_para_high = byte_data_high;

	dfr_player.byte_para_low = byte_data_low;

	dfr_player.check_sum = dfrplayer_cal_checksum(id_command, byte_data_high, byte_data_low);

	bsp_transmit_data(PACKET_TRANSMIT_DATA, PACKET_SIZE);
}







