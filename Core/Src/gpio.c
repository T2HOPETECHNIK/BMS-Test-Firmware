/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
static balancer_bat_t balancer_bat[6];
static balancer_state_t balancer_state[2];
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
        * Free pins are configured automatically as Analog (this feature is enabled through
        * the Code Generation settings)
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, WDT_WDI_Pin|BAT_100_Pin|BAL_B2_Pin|BAL_B1_Pin
                          |BAL_B0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, BAT_25_Pin|BAT_50_Pin|BAT_75_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SPI2_ADC_CS2_Pin|SPI2_EEPROM_CS1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin
                           PCPin */
  GPIO_InitStruct.Pin = BATY_B_Pin|BATX_B_Pin|DONE_A_Pin|BAL_A_Pin
                          |UVFLT_A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin
                           PCPin */
  GPIO_InitStruct.Pin = WDT_WDI_Pin|BAT_100_Pin|BAL_B2_Pin|BAL_B1_Pin
                          |BAL_B0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3
                           PC5 PC6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA8 PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = BAT_25_Pin|BAT_50_Pin|BAT_75_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = SPI2_ADC_CS2_Pin|SPI2_EEPROM_CS1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = PTCFLT_A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PTCFLT_A_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = OVFLT_A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OVFLT_A_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin
                           PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = BATY_A_Pin|BATX_A_Pin|PTCFLT_B_Pin|DONE_B_Pin
                          |BAL_B_Pin|UVFLT_B_Pin|OVFLT_B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
void bal_bat_get()
{
	if (DONE_B_stat == 0)
	{
		balancer_state[0].operation = 0;
		balancer_state[0].done = 1;
	}
	else if(DONE_B_stat == 1 && BAL_B_stat == 0)
	{
		balancer_state[0].operation = 1;
		balancer_state[0].done = 0;

		if (BATX_B_stat == 1 && BATY_B_stat == 1)
		{
			bal_bat_update(0,1);
			bal_bat_update(1,0);
			bal_bat_update(2,0);
			bal_bat_update(3,0);
		}
		else if (BATX_B_stat == 1 && BATY_B_stat == 0)
		{
			bal_bat_update(0,0);
			bal_bat_update(1,1);
			bal_bat_update(2,0);
			bal_bat_update(3,0);
		}
		else if (BATX_B_stat == 0 && BATY_B_stat == 0)
		{
			bal_bat_update(0,0);
			bal_bat_update(1,0);
			bal_bat_update(2,1);
			bal_bat_update(3,0);
		}
		else if (BATX_B_stat == 0 && BATY_B_stat == 1)
		{
			bal_bat_update(0,0);
			bal_bat_update(1,0);
			bal_bat_update(2,0);
			bal_bat_update(3,1);
		}
	}

	if (DONE_A_stat == 0)
	{
		balancer_state[1].operation = 0;
		balancer_state[1].done = 1;
	}
	else if (DONE_A_stat == 1 && BAL_A_stat == 0)
	{
		if (BATX_A_stat == 1 && BATY_A_stat == 1)
		{
			bal_bat_update(2,1);
			bal_bat_update(3,0);
			bal_bat_update(4,0);
			bal_bat_update(5,0);
		}
		else if (BATX_A_stat == 1 && BATY_A_stat == 0)
		{
			bal_bat_update(2,0);
			bal_bat_update(3,1);
			bal_bat_update(4,0);
			bal_bat_update(5,0);
		}
		else if (BATX_A_stat == 0 && BATY_A_stat == 0)
		{
			bal_bat_update(2,0);
			bal_bat_update(3,0);
			bal_bat_update(4,1);
			bal_bat_update(5,0);
		}
		else if (BATX_A_stat == 0 && BATY_A_stat == 1)
		{
			bal_bat_update(2,0);
			bal_bat_update(3,0);
			bal_bat_update(4,0);
			bal_bat_update(5,1);
		}
	}
}

void bal_bat_update(uint8_t id, uint8_t connect)
{
	balancer_bat[id].connect = connect;
	if (UVFLT_A_stat == 0 || UVFLT_B_stat == 0)
	{
		balancer_bat[id].under_volt = 1;
	}
	else balancer_bat[id].under_volt = 0;

	if (OVFLT_A_stat == 0 || OVFLT_B_stat == 0)
	{
		balancer_bat[id].over_volt = 1;
	}
	else balancer_bat[id].under_volt = 0;

	if (PTCFLT_B_stat == 0)
	{
		balancer_state[0].ptc_fault = 1;
	}
	else balancer_state[0].ptc_fault = 0;

	if (PTCFLT_A_stat == 0)
	{
		balancer_state[1].ptc_fault = 1;
	}
	else balancer_state[1].ptc_fault = 0;
}

void bms_LED_update()
{
	uint8_t ledx;

	for (int i=0; i<6; i++)
	{
		if (balancer_bat[i].connect == 1)
		{
			ledx = i;
		}
	}

	if (ledx == 0) 		{BAL_B2_OFF; BAL_B1_OFF; BAL_B0_ON;}
	else if (ledx == 1) {BAL_B2_OFF; BAL_B1_ON; BAL_B0_OFF;}
	else if (ledx == 2) {BAL_B2_OFF; BAL_B1_ON; BAL_B0_ON;}
	else if (ledx == 3) {BAL_B2_ON; BAL_B1_OFF; BAL_B0_OFF;}
	else if (ledx == 4) {BAL_B2_ON; BAL_B1_OFF; BAL_B0_ON;}
	else if (ledx == 5) {BAL_B2_ON; BAL_B1_ON; BAL_B0_OFF;}
	else 				{BAL_B2_ON; BAL_B1_ON; BAL_B0_ON;}
}
/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
