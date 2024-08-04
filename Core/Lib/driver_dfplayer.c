/*
 * driver_dfplayer.c
 *
 *  Created on: Aug 3, 2024
 *      Author: MTC-TTM
 */

#include "driver_dfplayer.h"

// Packet structure constants
#define DFPLAYER_START_BYTE        0x7E
#define DFPLAYER_VERSION           0xFF
#define DFPLAYER_LENGTH            0x06
#define DFPLAYER_EN_FEEDBACK       0x01
#define DFPLAYER_END_BYTE          0xEF




// DFPlayer commands
#define DFPLAYER_CMD_PLAY_NEXT     0x01

#define DFPLAYER_CMD_PLAY_PREV     0x02

#define DFPLAYER_CMD_PLAY_TRACK    0x03

#define DFPLAYER_CMD_VOL_UP        0x04

#define DFPLAYER_CMD_VOL_DOWN      0x05

#define DFPLAYER_CMD_SET_VOL       0x06

#define DFPLAYER_CMD_SET_EQ        0x07

#define DFPLAYER_CMD_PLAYBACK_MODE 0x08

#define DFPLAYER_CMD_PLAYBACK_SRC  0x09

#define DFPLAYER_CMD_STANDBY_MODE  0x0A

#define DFPLAYER_CMD_NORMAL_MODE   0x0B

#define DFPLAYER_CMD_RESET         0x0C

#define DFPLAYER_CMD_PLAY          0x0D

#define DFPLAYER_CMD_PAUSE         0x0E

#define DFPLAYER_CMD_REPEAT_PLAY   0x11




	// CONST PARAMETER
#define NONE_PARAMETER			0x0000
#define TF_CARD_PARAMETER		0x02		// Micro SD card



packet_dfplayer_data_t df_player =
{
    .start_byte = DFPLAYER_START_BYTE,
    .version	= DFPLAYER_VERSION,
    .length 	= DFPLAYER_LENGTH,
	.feedback	= DFPLAYER_EN_FEEDBACK,
	.end_byte	= DFPLAYER_END_BYTE
};


#define DFPLAYER_COMMAND_TRANSMIT 	((uint8_t*)&df_player)
#define DFPLAYER_COMMAND_SIZE 		sizeof(packet_dfplayer_data_t)


static uint16_t dfplayer_cal_checksum (uint8_t id_command, uint16_t para_byte)
{
	uint16_t checksum = DFPLAYER_VERSION + DFPLAYER_LENGTH + id_command + DFPLAYER_EN_FEEDBACK + para_byte;
	checksum = 0 - checksum;

	return checksum;
}

static void dfplayer_send_command (uint8_t id_command, uint16_t para_byte)
{
	df_player.id_command = id_command;

	df_player.para_byte_high = (para_byte>>8)&0x00FF;

	df_player.para_byte_low = para_byte & 0x00FF;


	uint16_t temp_checksum = dfplayer_cal_checksum(id_command, para_byte);

	df_player.check_sum_high = (temp_checksum >> 8) & 0x00FF;

	df_player.check_sum_low = temp_checksum & 0x00FF;

	bsp_transmit_data(DFPLAYER_COMMAND_TRANSMIT, DFPLAYER_COMMAND_SIZE);

}


void dfplayer_play_song (uint16_t ordinal_song_number)
{
	dfplayer_send_command (DFPLAYER_CMD_PLAY_TRACK, ordinal_song_number);
}

void dfplayer_pause_song ()
{

}


void dfplayer_init ()
{
//		// Pause the song
//	dfrplayer_send_command

		// initial the playback source: Micro SD card (TF card)
	dfplayer_send_command (DFPLAYER_CMD_PLAYBACK_SRC, TF_CARD_PARAMETER);

		// Setting the initial volumn: 25
	dfplayer_send_command(DFPLAYER_CMD_SET_VOL, 25);

}

void test()
{
	dfplayer_init();

	dfplayer_play_song(1);

	bsp_delay(5000);



//	dfrplayer_play_song(2);
//
//	bsp_delay(5000);
//
//	dfrplayer_play_song(3);
//
//	bsp_delay(5000);
//
//	dfrplayer_play_song(4);


}













