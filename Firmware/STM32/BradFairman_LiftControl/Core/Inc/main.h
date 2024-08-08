/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define MOTOR_PWM_FREQ	10000U

typedef struct
{
	GPIO_TypeDef*	port;
	uint16_t		pin;
}GPIO_Pins;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PRESENCE_CS_Pin GPIO_PIN_11
#define PRESENCE_CS_GPIO_Port GPIOC
#define PRESENCE_INT_Pin GPIO_PIN_12
#define PRESENCE_INT_GPIO_Port GPIOC
#define PRESENCE_INT_EXTI_IRQn EXTI4_15_IRQn
#define TOF_BOTTOM_GPIO1_Pin GPIO_PIN_0
#define TOF_BOTTOM_GPIO1_GPIO_Port GPIOF
#define TOF_BOTTOM_XSHUT_Pin GPIO_PIN_1
#define TOF_BOTTOM_XSHUT_GPIO_Port GPIOF
#define TOF_LEFT_GPIO1_Pin GPIO_PIN_3
#define TOF_LEFT_GPIO1_GPIO_Port GPIOC
#define TOF_LEFT_XSHUT_Pin GPIO_PIN_0
#define TOF_LEFT_XSHUT_GPIO_Port GPIOA
#define TOF_RIGHT_GPIO1_Pin GPIO_PIN_1
#define TOF_RIGHT_GPIO1_GPIO_Port GPIOA
#define TOF_RIGHT_XSHUT_Pin GPIO_PIN_2
#define TOF_RIGHT_XSHUT_GPIO_Port GPIOA
#define TOUCH_SENSOR_Pin GPIO_PIN_3
#define TOUCH_SENSOR_GPIO_Port GPIOA
#define TOUCH_SENSOR_EXTI_IRQn EXTI2_3_IRQn
#define MOTOR_SLEEP_Pin GPIO_PIN_4
#define MOTOR_SLEEP_GPIO_Port GPIOA
#define MOTOR_DISABLE_Pin GPIO_PIN_5
#define MOTOR_DISABLE_GPIO_Port GPIOA
#define MOTOR1_IN2_Pin GPIO_PIN_6
#define MOTOR1_IN2_GPIO_Port GPIOA
#define MOTOR1_IN1_Pin GPIO_PIN_7
#define MOTOR1_IN1_GPIO_Port GPIOA
#define MOTOR1_CS_Pin GPIO_PIN_4
#define MOTOR1_CS_GPIO_Port GPIOC
#define MOTOR1_FAULT_Pin GPIO_PIN_5
#define MOTOR1_FAULT_GPIO_Port GPIOC
#define MOTOR2_IN2_Pin GPIO_PIN_0
#define MOTOR2_IN2_GPIO_Port GPIOB
#define MOTOR2_IN1_Pin GPIO_PIN_1
#define MOTOR2_IN1_GPIO_Port GPIOB
#define MOTOR2_CS_Pin GPIO_PIN_2
#define MOTOR2_CS_GPIO_Port GPIOB
#define GPIO_IN_1_Pin GPIO_PIN_10
#define GPIO_IN_1_GPIO_Port GPIOB
#define GPIO_IN_2_Pin GPIO_PIN_11
#define GPIO_IN_2_GPIO_Port GPIOB
#define GPIO_OUT_1_Pin GPIO_PIN_12
#define GPIO_OUT_1_GPIO_Port GPIOB
#define MOTOR2_FAULT_Pin GPIO_PIN_8
#define MOTOR2_FAULT_GPIO_Port GPIOA
#define GPIO_OUT_5_Pin GPIO_PIN_9
#define GPIO_OUT_5_GPIO_Port GPIOA
#define GPIO_OUT_6_Pin GPIO_PIN_6
#define GPIO_OUT_6_GPIO_Port GPIOC
#define GPIO_OUT_4_Pin GPIO_PIN_7
#define GPIO_OUT_4_GPIO_Port GPIOC
#define GPIO_OUT_3_Pin GPIO_PIN_8
#define GPIO_OUT_3_GPIO_Port GPIOD
#define GPIO_OUT_2_Pin GPIO_PIN_9
#define GPIO_OUT_2_GPIO_Port GPIOD
#define IR_FEEDBACK_SENSOR_Pin GPIO_PIN_10
#define IR_FEEDBACK_SENSOR_GPIO_Port GPIOA
#define IR_FEEDBACK_SENSOR_EXTI_IRQn EXTI4_15_IRQn
#define SCL_ADC_Pin GPIO_PIN_11
#define SCL_ADC_GPIO_Port GPIOA
#define SDA_ADC_Pin GPIO_PIN_12
#define SDA_ADC_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_8
#define LED_GPIO_Port GPIOC
#define STATUS_LED_Pin GPIO_PIN_9
#define STATUS_LED_GPIO_Port GPIOC
#define SCL_SENSORS_Pin GPIO_PIN_8
#define SCL_SENSORS_GPIO_Port GPIOB
#define SDA_SENSORS_Pin GPIO_PIN_9
#define SDA_SENSORS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
