/*
 * sys_manager.c
 *
 *  Created on: Aug 1, 2024
 *      Author: MTC-TTM
 */

#include "sys_manager.h"

// Main loop function

void sys_test_1 ()			// Example driver
{
	DF_Init(30);

	DF_PlayFromStart();

	while (1)
	{
		Check_Key();
	}
}


extern UART_HandleTypeDef huart2;

// Assuming your command is correct and does not need checksum adjustment
uint8_t command[] = { 0x7E, 0xFF, 0x06, 0x0D, 0x00, 0x00, 0x00, 0xFE, 0xEE, 0xEF };
uint8_t command1[] = { 0x7E, 0xFF, 0x06, 0x0E, 0x00, 0x00, 0x00, 0xFE, 0xED, 0xEF };
uint8_t command2[] = { 0x7E, 0xFF, 0x06, 0x01, 0x00, 0x00, 0x00, 0xFE, 0xFA, 0xEF };
uint8_t command3[] = { 0x7E, 0xFF, 0x06, 0x08, 0x00, 0x00, 0x01, 0x7E, 0xF2, 0xEF };


uint8_t command4[] = { 0x7E, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x01, 0xFE, 0xF7, 0xEF };


uint8_t receive[20];

void sys_test_2 ()
{
//	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15); //Neu nhan duoc thi dao led

    HAL_UART_Transmit(&huart2, command4, sizeof(command4), 5000);
    // Wait until transmission is complete
    HAL_Delay(5000);

    HAL_UART_Transmit(&huart2, command3, sizeof(command3), 5000);


    HAL_UART_Receive_IT(&huart2, receive, 20);

}





void system_manage_loop()
{
//	sys_test_2();
	sys_test_1();
}




