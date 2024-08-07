/*
 * driver_rotation_sensor.h
 *
 *  Created on: Aug 5, 2024
 *      Author: MTC-TTM
 */

#ifndef LIB_DRIVER_ROTATION_SENSOR_H_
#define LIB_DRIVER_ROTATION_SENSOR_H_

#include <bsp_rotation_sensor.h>
#include <bsp_timer.h>



void rotation_sensor_init();

uint8_t rotaion_sensor_detect_volume_change ();

uint8_t rotation_sensor_get_volume();


#endif /* LIB_DRIVER_ROTATION_SENSOR_H_ */
