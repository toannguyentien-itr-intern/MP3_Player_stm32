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
	dfplayer_test();

}

void system_manage_loop()
{

	rotation_sensor_init();

	while (1)
	{
		__NOP();

		change = rotation_sensor_get_volumn();

		if (change)
		{
			volumn = rotation_sensor_get_volumn();
		}

		rotation_sensor_init();
	}
}




