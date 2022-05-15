/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stdio.h"
#include "string.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"
#include "ap3426.h"


extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart2;
/* USER CODE END PV */
                              
/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void AP3426_WriteOneByte(uint8_t reg, uint8_t data)
{
	uint16_t write_data = reg | (data << 8);
	if (HAL_I2C_Master_Transmit(&hi2c1, (AP3426_ADDR << 1) | AP3426_W, (uint8_t*)&write_data, 2, 300) != HAL_OK)
	{
		Error_Handler();
	}
	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY) ;
}

uint8_t AP3426_ReadOneByte(uint8_t reg)
{
	uint8_t read_data = 0;
	if (HAL_I2C_Master_Transmit(&hi2c1, (AP3426_ADDR << 1) | AP3426_W, (uint8_t*)&reg, 1, 300) != HAL_OK)
	{
		Error_Handler();
	}
	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY) ;
	if (HAL_I2C_Master_Receive(&hi2c1, (AP3426_ADDR << 1) | AP3426_R, (uint8_t*)&read_data, 1, 300) != HAL_OK)
	{
		Error_Handler();
	}
	return read_data;
}

uint8_t AP3426_Init(void)
{
	AP3426_WriteOneByte(SYS_CONTROL_ADDR,AP3426_MODE_SW_RESET ); // AP3426 execute reset
	HAL_Delay(50);
	AP3426_WriteOneByte(SYS_CONTROL_ADDR,AP3426_MODE_IR_ALS_AND_PS ); // AP3426 enable IR, ALS and PsData
	HAL_Delay(50);
	AP3426_WriteOneByte(PS_Low_LowThreshold, Init_ps_lowThreshold); //PS Low Threshold=0x200
	HAL_Delay(50);
	AP3426_WriteOneByte(PS_High_LowThreshold, Init_pshi_lowbyteThreshold); //PS High Threshold=500
	AP3426_WriteOneByte(PS_High_LowThreshold, Init_pshi_upbyteThreshold); //PS High Threshold=500
	HAL_Delay(50);




}

void AP3426_Read_IR_Data(uint16_t* ir)
{
	uint8_t ir_l = 0, ir_h = 0;
	ir_l = AP3426_ReadOneByte(IR_Data_Low);
	ir_h = AP3426_ReadOneByte(IR_Data_High);
	if ((ir_l & 0x80) == 0x80) // Invalid IR and PS data
	{
		*ir = 0;
	}
	else // ir_l Bit[1:0] is data, ps_l bits[3:0] ans ps_h bits[5:0] is data
	{
		*ir = (ir_h << 8) | (ir_l & 0x03);
	}
}

void AP3426_Read_ALS_Data(uint16_t* als)
{
	uint8_t als_l = 0, als_h = 0;
	als_l = AP3426_ReadOneByte(ALS_Data_Low);
	als_h = AP3426_ReadOneByte(ALS_Data_High);
	*als = (als_h << 8) | (als_l);
}

void AP3426_Read_PS_Data(uint16_t* ps)
{
	uint8_t ps_l = 0, ps_h = 0;
	ps_l = AP3426_ReadOneByte(PS_Data_Low);
	ps_h = AP3426_ReadOneByte(PS_Data_High);
//	if ((ps_l & 0x40) == 0x40) // Invalid IR and PS data
//	{
//		*ps = 0;
//	}
//	else // ir_l Bit[1:0] is data, ps_l bits[3:0] ans ps_h bits[5:0] is data
//	{
//		*ps = ((ps_h & 0x1F) << 8) | (ps_l & 0x0F);
		*ps = (ps_h  << 8) | (ps_l);
//	}
}

void AP3426_ReadDataTest(void)
{
	uint16_t ir = 0, ps = 0, als = 0;
	AP3426_Read_IR_Data(&ir);
	AP3426_Read_ALS_Data(&als);
	AP3426_Read_PS_Data(&ps);
	printf("AP3426 IR = 0x%x\n\r", ir);
	printf("AP3426 PS = 0x%x\n\r", ps);
	printf("AP3426 ALS = 0x%x\n\r", als);
    
}


