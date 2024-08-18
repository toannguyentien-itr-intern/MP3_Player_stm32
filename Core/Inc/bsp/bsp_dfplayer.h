/**
 * @file       bsp_dfplayer.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-08-01
 * @author     Toan Nguyen
 *
 * @brief      Header file for DF Player
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_DFPLAYER_H
#define __BSP_DFPLAYER_H

/* Includes ----------------------------------------------------------- */
#include "stdint.h"
#include "stm32f4xx_hal.h"

/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Transmit data using UART.
 *
 * @param[in]     data    The data to transmit.
 * @param[in]     size    The size of the data to transmit.
 *
 * @attention  This function sends data using the UART in interrupt mode.
 *
 * @return      void
 */
void bsp_transmit_data(uint8_t* data, uint8_t size);

/**
 * @brief  Receive data using UART.
 *
 * @param[in]     data    The buffer to store received data.
 * @param[in]     size    The size of the data to receive.
 *
 * @attention  This function receives data using the UART in DMA mode.
 *
 * @return      void
 */
void bsp_receive_data(uint8_t* data, uint8_t size);

/**
 * @brief  Check the transmit status.
 *
 * @attention  This function checks the transmit flag to determine if data transmission is complete.
 *
 * @return      The transmit flag status.
 */
uint8_t bsp_check_transmit_status(void);

/**
 * @brief  Check the receive status.
 *
 * @attention  This function checks the receive flag to determine if data reception is complete.
 *
 * @return      The receive flag status.
 */
uint8_t bsp_check_receive_status(void);

/**
 * @brief  Check the playing status.
 *
 * @attention  This function checks the GPIO pin status to determine if the player is playing.
 *
 * @return      The playing status.
 */
uint8_t bsp_check_playing_status(void);
#endif /* __BSP_DFPLAYER_H */

/* End of file -------------------------------------------------------- */
