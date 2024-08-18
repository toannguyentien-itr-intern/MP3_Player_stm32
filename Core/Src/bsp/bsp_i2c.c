/**
 * @file       bsp_i2c.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    1.0.0
 * @date       2024-07-31
 * @author     Tuan Nguyen
 *
 * @brief      Source file for bsp_i2c
 *
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_i2c.h"

/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
bool bsp_i2c_status(I2C_HandleTypeDef *hi2c)
{
  return (HAL_I2C_GetState(hi2c) == HAL_I2C_STATE_READY) ? true : false;
}

bool bsp_i2c1_is_device_ready(I2C_HandleTypeDef *hi2c, uint16_t dev_addr, uint32_t trials, uint32_t timeout)
{
  HAL_StatusTypeDef status = HAL_I2C_IsDeviceReady(hi2c, dev_addr, trials, BSP_I2C_TIMEOUT);
  return (status == HAL_OK) ? true : false;
}

bool bsp_i2c_write_mem(I2C_HandleTypeDef *hi2c, uint16_t dev_addr, uint16_t mem_addr, uint16_t mem_addr_size,
                       uint8_t *p_data, uint16_t size)
{
  if (HAL_I2C_GetState(hi2c) == HAL_I2C_STATE_BUSY)
    return false;
  HAL_StatusTypeDef status =
  HAL_I2C_Mem_Write(hi2c, dev_addr, mem_addr, mem_addr_size, p_data, size, BSP_I2C_TIMEOUT);
  return (status == HAL_OK) ? true : false;
}

bool bsp_i2c_read_mem(I2C_HandleTypeDef *hi2c, uint16_t dev_addr, uint16_t mem_addr, uint16_t mem_addr_size,
                      uint8_t *p_data, uint16_t size)
{
  if (HAL_I2C_GetState(hi2c) == HAL_I2C_STATE_BUSY)
    return false;
  HAL_StatusTypeDef status =
  HAL_I2C_Mem_Read(hi2c, dev_addr, mem_addr, mem_addr_size, p_data, size, BSP_I2C_TIMEOUT);
  return (status == HAL_OK) ? true : false;
}
/* Private definitions ----------------------------------------------- */
/* End of file -------------------------------------------------------- */
