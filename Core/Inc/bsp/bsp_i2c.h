/**
 * @file       bsp_i2c.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Header file for bsp_i2c
 *
 * @note       None
 * @example    None
 */
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_I2C_H
#define __BSP_I2C_H

/* Includes ----------------------------------------------------------- */
#include <stdbool.h>
#include <stdint.h>

#include "stm32f4xx_hal.h"

/* Public defines ----------------------------------------------------- */
#define BSP_I2C_TIMEOUT 1000
/* Public enumerate/structure ----------------------------------------- */

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */
/**
 * @brief  Check the status of the I2C interface.
 *
 * @param[in]     hi2c    Pointer to the I2C handle structure.
 *
 * @attention  This function checks if the I2C interface is ready.
 *
 * @return
 *  - true: I2C interface is ready
 *  - false: I2C interface is not ready
 */
bool bsp_i2c_status(I2C_HandleTypeDef *hi2c);

/**
 * @brief  Check if the I2C device is ready for communication.
 *
 * @param[in]     hi2c        Pointer to the I2C handle structure.
 * @param[in]     dev_addr    The address of the I2C device.
 * @param[in]     trials      Number of trials to check the device readiness.
 * @param[in]     timeout     Timeout duration for each trial.
 *
 * @attention  This function communicates with the HAL layer to check if the I2C device is ready.
 *
 * @return
 *  - true: I2C device is ready
 *  - false: I2C device is not ready
 */
bool bsp_i2c1_is_device_ready(I2C_HandleTypeDef *hi2c, uint16_t dev_addr, uint32_t trials, uint32_t timeout);

/**
 * @brief  Write data to a specific memory address of an I2C device.
 *
 * @param[in]     hi2c          Pointer to the I2C handle structure.
 * @param[in]     dev_addr      The address of the I2C device.
 * @param[in]     mem_addr      The memory address to write to.
 * @param[in]     mem_addr_size The size of the memory address.
 * @param[in]     p_data        Pointer to the data buffer to be written.
 * @param[in]     size          The size of the data buffer.
 *
 * @attention  This function communicates with the HAL layer to write data to the I2C device.
 *
 * @return
 *  - true: Data write was successful
 *  - false: Data write failed
 */
bool bsp_i2c_write_mem(I2C_HandleTypeDef *hi2c, uint16_t dev_addr, uint16_t mem_addr, uint16_t mem_addr_size,
                       uint8_t *p_data, uint16_t size);

/**
 * @brief  Read data from a specific memory address of an I2C device.
 *
 * @param[in]     hi2c        Pointer to the I2C handle structure.
 * @param[in]     dev_addr  The address of the I2C device.
 * @param[in]     mem_addr  The memory address to read from.
 * @param[in]     mem_addr_size  The size of the memory address.
 * @param[in]     p_data       Pointer to the data buffer to store the read data.
 * @param[in]     size        The size of the data buffer.
 *
 * @attention  This function communicates with the HAL layer to read data from the I2C device.
 *
 * @return
 *  - true: Data read was successful
 *  - false: Data read failed
 */
bool bsp_i2c_read_mem(I2C_HandleTypeDef *hi2c, uint16_t dev_addr, uint16_t mem_addr, uint16_t mem_addr_size,
                      uint8_t *p_data, uint16_t size);

#endif /* __BSP_I2C_H */

/* End of file -------------------------------------------------------- */
