/*
 * mainApp.hpp
 *
 *  Created on: Aug 6, 2024
 *      Author: Syed Farhan Ahmed
 */

#ifndef INCLUDES_MAINAPP_HPP_
#define INCLUDES_MAINAPP_HPP_

#include "main.h"
#include <cstdlib>
#include <DRV8873.hpp>

//extern GPIO_Pins Motor1_CS, Motor2_CS;
typedef enum {
	MOTOR_OK,
	MOTOR_SLEEP,
	MOTOR_ENABLE,
	MOTOR_DISABLE
}motor_control_e;

class mainApp{
public:
	mainApp(SPI_HandleTypeDef* SPI_handle, I2C_HandleTypeDef* I2C1_handle, I2C_HandleTypeDef* I2C2_handle, TIM_HandleTypeDef* TIM_handle); //{
//		_SPI_handle_ = SPI_handle;
//		_I2C_ADC_handle_ = I2C2_handle;
//		_I2C_SENSOR_handle_ = I2C1_handle;
//		_MOTOR_PWM_TIM_handle_ = TIM_handle;
//
//		MOTOR1_drv = new DRV8873(_SPI_handle_, _MOTOR_PWM_TIM_handle_, Motor1_CS, TIM_CHANNEL_2, TIM_CHANNEL_1);
//		MOTOR2_drv = new DRV8873(_SPI_handle_, _MOTOR_PWM_TIM_handle_, Motor2_CS, TIM_CHANNEL_4, TIM_CHANNEL_3);
//	}
	~mainApp() {
		free(MOTOR1_drv);
		free(MOTOR2_drv);
	};

	void initialize(void);
	void motor_control(motor_control_e state);
	void loop(void);
private:
	SPI_HandleTypeDef* _SPI_handle_;
	I2C_HandleTypeDef* _I2C_ADC_handle_;
	I2C_HandleTypeDef* _I2C_SENSOR_handle_;
	TIM_HandleTypeDef* _MOTOR_PWM_TIM_handle_;


	DRV8873* MOTOR1_drv = NULL;
	DRV8873* MOTOR2_drv = NULL;

	uint8_t* motor1_status = NULL;
	uint8_t* motor2_status = NULL;
};





#endif /* INCLUDES_MAINAPP_HPP_ */
