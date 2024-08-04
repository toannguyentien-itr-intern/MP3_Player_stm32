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

#define SPECIFY_TRACK		0x03



packet_dfrplayer_data_t dfr_player =
{
    .start_byte = START_BYTE,
    .version	= VERSION,
    .length 	= LENGTH,
	.feedback	= ENABLE_FEEDBACK
};

#define PACKET_TRANSMIT_DATA ((uint8_t*)&dfr_player)

#define PACKET_SIZE sizeof(packet_dfrplayer_data_t)

static uint16_t dfrplayer_cal_checksum (uint8_t id_command, uint16_t para_byte)
{
	uint16_t checksum = VERSION + LENGTH + id_command + ENABLE_FEEDBACK + para_byte;
	checksum = 0 - checksum;

	return checksum;
}

static void dfrplayer_send_command (uint8_t id_command, uint16_t para_byte)
{
	dfr_player.id_command = id_command;

	dfr_player.para_byte_high = (para_byte>>8)&0x00FF;

	dfr_player.para_byte_low = para_byte & 0x00FF;


	uint16_t temp_checksum = dfrplayer_cal_checksum(id_command, para_byte);

	dfr_player.check_sum_high = (temp_checksum >> 8) & 0x00FF;

	dfr_player.check_sum_low = temp_checksum & 0x00FF;

	bsp_transmit_data(PACKET_TRANSMIT_DATA, PACKET_SIZE);

}


void dfrplayer_play_song (uint16_t ordinal_song_number)
{
	dfrplayer_send_command (SPECIFY_TRACK, ordinal_song_number);
}


void test()
{

	dfrplayer_play_song(1);
//
//	bsp_delay(5000);
//
//	dfrplayer_play_song(2);
//
//	bsp_delay(5000);
//
//	dfrplayer_play_song(3);


}













