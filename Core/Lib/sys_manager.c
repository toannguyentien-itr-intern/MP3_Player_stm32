/*
 * sys_manager.c
 *
 *  Created on: Aug 1, 2024
 *      Author: MTC-TTM
 */

#include "sys_manager.h"


uint8_t change;
uint8_t volumn;


void system_audio_init()
{
	dfplayer_init();
	rotation_sensor_init();
}



void system_manage_loop()
{

	dfplayer_test();

//	system_audio_init();
//
//
//	dfplayer_track_play(2);
//
//	dfplayer_repeat_mode_play();
//
//	while (1)
//	{
//		__NOP();
//
//		change = rotation_sensor_get_volumn();
//
//		if (change)
//		{
//			volumn = rotation_sensor_get_volumn();
//
//			dfplayer_adjust_volumn(volumn);
//		}
//
//		rotation_sensor_init();
//	}
}




