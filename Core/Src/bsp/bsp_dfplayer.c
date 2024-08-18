/**
 * @file       bsp_dfplayer.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-08-01
 * @author     Toan Nguyen
 *
 * @brief      Source file for DF Player
 *
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include <bsp_dfplayer.h>

/* Private defines ---------------------------------------------------- */
extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef  hdma_usart2_rx;
#define DF_PLAYER_UART   &huart2
#define DF_PLAYER_DMA_RX &hdma_usart2_rx
/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */
volatile static uint8_t transmit_flag = 0;
volatile static uint8_t receive_flag  = 0;
/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
// Transmit data
void bsp_transmit_data(uint8_t *data, uint8_t size)
{
  if (HAL_UART_Transmit_IT(DF_PLAYER_UART, data, size) == HAL_OK)
    return;
}

// Ready to receive data
void bsp_receive_data(uint8_t *data, uint8_t size)
{
  if (HAL_UART_Receive_DMA(DF_PLAYER_UART, data, size) == HAL_OK)
    return;
}

// Check the transmit flag
uint8_t bsp_check_transmit_status(void)
{
  if (transmit_flag)
    return transmit_flag;
  return 0;
}

// Check the receive flag
uint8_t bsp_check_receive_status(void)
{
  if (receive_flag)
    return receive_flag;
  return 0;
}

uint8_t bsp_check_playing_status(void)
{
  uint8_t status = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_14);
  if (status)
    return 0;

  return 1;
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

// Call back receive data
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  __NOP();
  if (huart->Instance == USART2)
  {
    __HAL_DMA_DISABLE(DF_PLAYER_DMA_RX);
    receive_flag = 1;
  }
}
/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
