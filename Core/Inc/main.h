/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BATY_B_Pin GPIO_PIN_13
#define BATY_B_GPIO_Port GPIOC
#define BATX_B_Pin GPIO_PIN_14
#define BATX_B_GPIO_Port GPIOC
#define WDT_WDI_Pin GPIO_PIN_15
#define WDT_WDI_GPIO_Port GPIOC
#define BAT_25_Pin GPIO_PIN_5
#define BAT_25_GPIO_Port GPIOA
#define BAT_50_Pin GPIO_PIN_6
#define BAT_50_GPIO_Port GPIOA
#define BAT_75_Pin GPIO_PIN_7
#define BAT_75_GPIO_Port GPIOA
#define BAT_100_Pin GPIO_PIN_4
#define BAT_100_GPIO_Port GPIOC
#define SPI2_ADC_CS2_Pin GPIO_PIN_11
#define SPI2_ADC_CS2_GPIO_Port GPIOB
#define SPI2_EEPROM_CS1_Pin GPIO_PIN_12
#define SPI2_EEPROM_CS1_GPIO_Port GPIOB
#define BAL_B2_Pin GPIO_PIN_7
#define BAL_B2_GPIO_Port GPIOC
#define BAL_B1_Pin GPIO_PIN_8
#define BAL_B1_GPIO_Port GPIOC
#define BAL_B0_Pin GPIO_PIN_9
#define BAL_B0_GPIO_Port GPIOC
#define PTCFLT_A_Pin GPIO_PIN_15
#define PTCFLT_A_GPIO_Port GPIOA
#define DONE_A_Pin GPIO_PIN_10
#define DONE_A_GPIO_Port GPIOC
#define BAL_A_Pin GPIO_PIN_11
#define BAL_A_GPIO_Port GPIOC
#define UVFLT_A_Pin GPIO_PIN_12
#define UVFLT_A_GPIO_Port GPIOC
#define OVFLT_A_Pin GPIO_PIN_2
#define OVFLT_A_GPIO_Port GPIOD
#define BATY_A_Pin GPIO_PIN_3
#define BATY_A_GPIO_Port GPIOB
#define BATX_A_Pin GPIO_PIN_4
#define BATX_A_GPIO_Port GPIOB
#define PTCFLT_B_Pin GPIO_PIN_5
#define PTCFLT_B_GPIO_Port GPIOB
#define DONE_B_Pin GPIO_PIN_6
#define DONE_B_GPIO_Port GPIOB
#define BAL_B_Pin GPIO_PIN_7
#define BAL_B_GPIO_Port GPIOB
#define UVFLT_B_Pin GPIO_PIN_8
#define UVFLT_B_GPIO_Port GPIOB
#define OVFLT_B_Pin GPIO_PIN_9
#define OVFLT_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
