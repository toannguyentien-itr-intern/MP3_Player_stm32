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




	// DFPlayer commands and parameter for each Command
//#define DFPLAYER_CMD_PLAY_NEXT     0x01

//#define DFPLAYER_CMD_PLAY_PREV     0x02

#define DFPLAYER_CMD_PLAY_TRACK    0x03

#define DFPLAYER_CMD_SET_VOL       0x06

//#define DFPLAYER_CMD_SET_EQ        0x07

#define DFPLAYER_CMD_REPEAT_MODE 	0x08
#define REPEAT_MODE_PARAMETER		0x00


#define DFPLAYER_CMD_PLAYBACK_SRC  	0x09
#define TF_CARD_PARAMETER			0x02		// Micro SD card


//#define DFPLAYER_CMD_STANDBY_MODE  0x0A

//#define DFPLAYER_CMD_NORMAL_MODE   0x0B

#define DFPLAYER_CMD_RESET         0x0C

#define DFPLAYER_CMD_PLAY_CONTINUE 0x0D

#define DFPLAYER_CMD_PLAY_PAUSE    0x0E

#define DFPLAYER_CMD_NORMAL_MODE   0x11
#define NORMAL_MODE_PARAMETER	   0x00





	// CONST PARAMETER
#define NONE_PARAMETER			0x00



#define BUFFER_SIZE 20

uint8_t rx_buffer [BUFFER_SIZE];
uint8_t receive_flag = 0;


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

	bsp_delay(100);
}


void dfplayer_track_play (uint16_t ordinal_song_number)
{
	dfplayer_send_command (DFPLAYER_CMD_PLAY_TRACK, ordinal_song_number);
	bsp_delay(200);
}

void dfplayer_track_pause (void)
{
	dfplayer_send_command(DFPLAYER_CMD_PLAY_PAUSE, NONE_PARAMETER);
}

void dfplayer_track_play_continue (void)
{
	dfplayer_send_command(DFPLAYER_CMD_PLAY_CONTINUE, NONE_PARAMETER);
}

void dfplayer_normal_mode_play (void)
{
	dfplayer_send_command(DFPLAYER_CMD_NORMAL_MODE, NORMAL_MODE_PARAMETER);
}

void dfplayer_repeat_mode_play (void)
{
	dfplayer_send_command(DFPLAYER_CMD_REPEAT_MODE, REPEAT_MODE_PARAMETER);
}

void dfplayer_random_mode_play (void)
{
//	dfplayer_send_command(0x08 , 0x02);
}

void dfplayer_adjust_volumn (uint8_t volumn)
{
	dfplayer_send_command(DFPLAYER_CMD_SET_VOL, volumn);
}

void dfplayer_init (void)
{
		// reset module
//	dfplayer_send_command (DFPLAYER_CMD_RESET, NONE_PARAMETER);
//	bsp_delay(500);

		// Could adding the pause command to make sure there are stop play song
	dfplayer_track_pause();
	bsp_delay(500);

		// initial the playback source: Micro SD card (TF card)
	dfplayer_send_command (DFPLAYER_CMD_PLAYBACK_SRC, TF_CARD_PARAMETER);

		// Setting the initial volumn: 25
	dfplayer_adjust_volumn (25);
}

#define DFPLAYER_CMD_RANDOM_MODE	0X18
#define RANDOM_MODE_PARAMETER		0x02

void dfplayer_test()
{

	dfplayer_init();

	dfplayer_adjust_volumn(2);

	dfplayer_track_play(2);

	bsp_delay(7000);

	dfplayer_send_command(0x18, 0x00);



}















