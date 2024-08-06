/*
 * bsp_dfplayer.c
 *
 *  Created on: Aug 3, 2024
 *      Author: MTC-TTM
 */

#include <bsp_dfplayer.h>

extern UART_HandleTypeDef huart2;

#define DF_PLAYER_UART &huart2

volatile uint8_t transmit_flag = 0;
volatile static uint8_t receive_flag = 0;

		// Transmit data
void bsp_transmit_data (uint8_t* data, uint8_t size)
{
	if (HAL_UART_Transmit_IT(DF_PLAYER_UART, data, size) == HAL_OK)
		return;
}

		// Ready to receive data
void bsp_receive_data (uint8_t* data, uint8_t size)
{
	if (HAL_UART_Receive_IT(DF_PLAYER_UART, data, size) == HAL_OK)
		return;
}

		// Check the transmit flag
uint8_t bsp_check_transmit_status (void)
{
	if (transmit_flag)
		return transmit_flag;
	return 0;
}

		// Check the receive flag
uint8_t bsp_check_receive_status (void)
{
	if (receive_flag)
		return receive_flag;
	return 0;
}

		// Call back transmit
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  __NOP();
	if (huart->Instance == USART2)
	{
		transmit_flag = 1;
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);

	}
}


