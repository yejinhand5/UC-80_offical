/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/*Rigister Map*/
#pragma pack (2)

typedef struct
{
  uint16_t usPulse_num;
  uint16_t usLevel_status;
} PULSE_TypeDef;

typedef struct
{
    uint16_t  AI1;
    uint16_t  AI2;
    uint16_t  AO1;
    uint16_t  AO2;
}MA2AI2AOREG_TypeDef;


typedef struct
{
   uint16_t usOutV1;
   uint16_t usOutV2;
} CONTROL_SETTINGS_t;

typedef struct
{
  uint16_t usRelay1;
  uint16_t usRelay2;
  uint16_t usRelay3;
  uint16_t usRelay4;
  uint16_t usRelay5;
} CONTROL_RELAY_t;

typedef struct
{
		uint32_t	ParaAddr;
		uint32_t	ParaSize;
}FLASH_ADDR;


typedef struct
{								/* Register		 Type  		Description  	R/W */
//	uint16_t Modbus_Address;    // 42000		 not used
	uint16_t Parity;			// 42000		 0=NONE, 1=ODD, 2=EVEN
	uint32_t Baudrate;  		// 42001-42002
}SYS_TypeDef;


#pragma pack ()

extern uint32_t systick_1s;
extern uint32_t ulTickPrev;
extern uint16_t pulse_num;
extern uint16_t freq ;

extern PULSE_TypeDef PulseReg;

extern uint8_t pulse_flag ;

extern CONTROL_SETTINGS_t control_settings;

extern CONTROL_RELAY_t control_relay;


extern MA2AI2AOREG_TypeDef Ma2Ai2AoReg;

extern TIM_HandleTypeDef htim17;

extern UART_HandleTypeDef huart2;

extern I2C_HandleTypeDef hi2c2;

extern CONTROL_SETTINGS_t ControlReg;

extern SYS_TypeDef sys;
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
#define USART_DE_Pin GPIO_PIN_1
#define USART_DE_GPIO_Port GPIOA
#define RELAY5_Pin GPIO_PIN_6
#define RELAY5_GPIO_Port GPIOA
#define RELAY4_Pin GPIO_PIN_7
#define RELAY4_GPIO_Port GPIOA
#define RELAY3_Pin GPIO_PIN_4
#define RELAY3_GPIO_Port GPIOC
#define RELAY2_Pin GPIO_PIN_0
#define RELAY2_GPIO_Port GPIOB
#define RELAY1_Pin GPIO_PIN_1
#define RELAY1_GPIO_Port GPIOB
#define PULSE_Pin GPIO_PIN_12
#define PULSE_GPIO_Port GPIOB
#define PULSE_EXTI_IRQn EXTI15_10_IRQn
#define STATUS_Pin GPIO_PIN_10
#define STATUS_GPIO_Port GPIOA
#define AD5410_SDIN_Pin GPIO_PIN_10
#define AD5410_SDIN_GPIO_Port GPIOC
#define AD5410_SCLK_Pin GPIO_PIN_11
#define AD5410_SCLK_GPIO_Port GPIOC
#define AD5410_LATCH_Pin GPIO_PIN_3
#define AD5410_LATCH_GPIO_Port GPIOB
#define AD5410_CLEAR_Pin GPIO_PIN_4
#define AD5410_CLEAR_GPIO_Port GPIOB
#define OUT2_Pin GPIO_PIN_5
#define OUT2_GPIO_Port GPIOB
#define OUT1_Pin GPIO_PIN_6
#define OUT1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

#define FLOW_SLAVE_ADDR (1)
#define AIAO_SLAVE_ADDR (2)
#define POWER_SWITCH_ADDR (240)
#define RELAY_CONTROL_ADDR (4)


#define LED_Toggle 	        HAL_GPIO_TogglePin(STATUS_GPIO_Port, STATUS_Pin)


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
