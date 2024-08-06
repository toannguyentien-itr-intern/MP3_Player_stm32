/*
 * sys_manager.c
 *
 *  Created on: Aug 1, 2024
 *      Author: MTC-TTM
 */

#include "sys_manager.h"



void system_audio_init()
{
	dfplayer_init();
	rotation_sensor_init();
}



void system_manage_loop()
{

//	dfplayer_test();

	system_audio_init();

	dfplayer_track_play(5);

	dfplayer_repeat_mode_play();

	while (1)
	{
		if (rotaion_sensor_detect_volumn_change())
		{
			uint8_t new_volumn = rotation_sensor_get_volumn();
			dfplayer_adjust_volumn(new_volumn);

		}
			// Ready for the playing music for the next time
		rotation_sensor_init();

	}
}




