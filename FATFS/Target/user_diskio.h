/* USER CODE BEGIN Header */
/**
 ******************************************************************************
  * @file    user_diskio.h
  * @brief   This file contains the common defines and functions prototypes for
  *          the user_diskio driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
 /* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USER_DISKIO_H
#define __USER_DISKIO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* USER CODE BEGIN 0 */
#define SPI hspi2
/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
extern SPI_HandleTypeDef SPI;
/* Exported constants --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
extern Diskio_drvTypeDef  USER_Driver;
void sdcard_systick_timerproc(void);
/* USER CODE END 0 */

#ifdef __cplusplus
}
#endif

#endif /* __USER_DISKIO_H */
