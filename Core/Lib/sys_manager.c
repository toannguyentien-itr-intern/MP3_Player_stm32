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

char *song_name;
char *author_name;

void system_access_music_info()
{
	uint8_t index = 5;
	while (1)
	{
		song_name = get_song_name_info(index);
		author_name = get_author_name_info(index);
	}
}

void system_manage_loop()
{
	system_access_music_info();

//	dfplayer_test();

	system_audio_init();

//	dfplayer_track_play(9);
//
//	dfplayer_repeat_mode_play();

	dfplayer_random_mode_play();

	while (1)
	{
		if (rotaion_sensor_detect_volume_change())
		{
			uint8_t new_volume = rotation_sensor_get_volume();
			dfplayer_adjust_volume(new_volume);

		}
			// Ready to adjust the volume
		rotation_sensor_init();

	}
}




