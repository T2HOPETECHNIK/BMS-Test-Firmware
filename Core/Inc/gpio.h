/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/*  Balancer A  */
#define BATY_A_stat     HAL_GPIO_ReadPin(BATY_A_GPIO_Port, BATY_A_Pin)
#define BATX_A_stat     HAL_GPIO_ReadPin(BATX_A_GPIO_Port, BATX_A_Pin)
#define DONE_A_stat     HAL_GPIO_ReadPin(DONE_A_GPIO_Port, DONE_A_Pin)
#define BAL_A_stat      HAL_GPIO_ReadPin(BAL_A_GPIO_Port, BAL_A_Pin)
#define PTCFLT_A_stat   HAL_GPIO_ReadPin(PTCFLT_A_GPIO_Port, PTCFLT_A_Pin)
#define UVFLT_A_stat    HAL_GPIO_ReadPin(UVFLT_A_GPIO_Port, UVFLT_A_Pin)
#define OVFLT_A_stat    HAL_GPIO_ReadPin(OVFLT_A_GPIO_Port, OVFLT_A_Pin)

/*  Balancer B  */
#define BATY_B_stat     HAL_GPIO_ReadPin(BATY_B_GPIO_Port, BATY_B_Pin)
#define BATX_B_stat     HAL_GPIO_ReadPin(BATX_B_GPIO_Port, BATX_B_Pin)
#define DONE_B_stat     HAL_GPIO_ReadPin(DONE_B_GPIO_Port, DONE_B_Pin)
#define BAL_B_stat      HAL_GPIO_ReadPin(BAL_B_GPIO_Port, BAL_B_Pin)
#define PTCFLT_B_stat   HAL_GPIO_ReadPin(PTCFLT_B_GPIO_Port, PTCFLT_B_Pin)
#define UVFLT_B_stat    HAL_GPIO_ReadPin(UVFLT_B_GPIO_Port, UVFLT_B_Pin)
#define OVFLT_B_stat    HAL_GPIO_ReadPin(OVFLT_B_GPIO_Port, OVFLT_B_Pin)

/*  State of Charge LED   */
#define BAT_25_ON       HAL_GPIO_WritePin(BAT_25_GPIO_Port, BAT_25_Pin, GPIO_PIN_SET)
#define BAT_25_OFF      HAL_GPIO_WritePin(BAT_25_GPIO_Port, BAT_25_Pin, GPIO_PIN_RESET)
#define BAT_25_TOGGLE   HAL_GPIO_TogglePin(BAT_25_GPIO_Port, BAT_25_Pin)
#define BAT_50_ON       HAL_GPIO_WritePin(BAT_50_GPIO_Port, BAT_50_Pin, GPIO_PIN_SET)
#define BAT_50_OFF      HAL_GPIO_WritePin(BAT_50_GPIO_Port, BAT_50_Pin, GPIO_PIN_RESET)
#define BAT_50_TOGGLE   HAL_GPIO_TogglePin(BAT_50_GPIO_Port, BAT_50_Pin)
#define BAT_75_ON       HAL_GPIO_WritePin(BAT_75_GPIO_Port, BAT_75_Pin, GPIO_PIN_SET)
#define BAT_75_OFF      HAL_GPIO_WritePin(BAT_75_GPIO_Port, BAT_75_Pin, GPIO_PIN_RESET)
#define BAT_75_TOGGLE   HAL_GPIO_TogglePin(BAT_75_GPIO_Port, BAT_75_Pin)
#define BAT_100_ON      HAL_GPIO_WritePin(BAT_100_GPIO_Port, BAT_100_Pin, GPIO_PIN_SET)
#define BAT_100_OFF     HAL_GPIO_WritePin(BAT_100_GPIO_Port, BAT_100_Pin, GPIO_PIN_RESET)
#define BAT_100_TOGGLE  HAL_GPIO_TogglePin(BAT_100_GPIO_Port, BAT_100_Pin)

/*  Balancing LED  */
#define BAL_B0_ON       HAL_GPIO_WritePin(BAL_B0_GPIO_Port, BAL_B0_Pin, GPIO_PIN_SET)
#define BAL_B0_OFF      HAL_GPIO_WritePin(BAL_B0_GPIO_Port, BAL_B0_Pin, GPIO_PIN_RESET)
#define BAL_B0_TOGGLE   HAL_GPIO_TogglePin(BAL_B0_GPIO_Port, BAL_B0_Pin)
#define BAL_B1_ON       HAL_GPIO_WritePin(BAL_B1_GPIO_Port, BAL_B1_Pin, GPIO_PIN_SET)
#define BAL_B1_OFF      HAL_GPIO_WritePin(BAL_B1_GPIO_Port, BAL_B1_Pin, GPIO_PIN_RESET)
#define BAL_B1_TOGGLE   HAL_GPIO_TogglePin(BAL_B1_GPIO_Port, BAL_B1_Pin)
#define BAL_B2_ON       HAL_GPIO_WritePin(BAL_B2_GPIO_Port, BAL_B2_Pin, GPIO_PIN_SET)
#define BAL_B2_OFF      HAL_GPIO_WritePin(BAL_B2_GPIO_Port, BAL_B2_Pin, GPIO_PIN_RESET)
#define BAL_B2_TOGGLE   HAL_GPIO_TogglePin(BAL_B2_GPIO_Port, BAL_B2_Pin)

typedef struct
{
	uint8_t connect;
	uint8_t over_volt;
	uint8_t under_volt;
}balancer_bat_t;

typedef struct
{
	uint8_t operation;
	uint8_t done;
	uint8_t ptc_fault;
	uint8_t error;
}balancer_state_t;
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
void bal_bat_update(uint8_t id, uint8_t connect);
void bal_bat_get(void);
void bms_LED_update(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
