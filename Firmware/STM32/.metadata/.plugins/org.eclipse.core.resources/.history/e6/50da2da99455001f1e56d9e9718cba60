/*
 * DRV8873.hpp
 *
 *  Created on: Aug 6, 2024
 *      Author: Syed Farhan Ahmed
 */

#ifndef DRV8873_DRV8873_HPP_
#define DRV8873_DRV8873_HPP_

#include "main.h"
//#include <mainApp.hpp>

// IC1_REG
#define REG_MODE_PH_EN			0x00
#define REG_MODE_PWM			0x01
#define REG_MODE_INDEPENDANT	0x02
#define REG_MODE_DISABLE_HIZ	0x03
#define REG_SR_53_2		0x00
#define REG_SR_34		0x04
#define REG_SR_18_3		0x08
#define REG_SR_13		0x0C
#define REG_SR_10_8		0x10
#define REG_SR_7_9		0x14
#define REG_SR_5_3		0x18
#define REG_SR_2_6		0x1C
#define REG_SPI_IN		0x00
#define REG_SPI_EN_PH	0x20
#define REG_TOFF_20		0x00
#define REG_TOFF_40		0x40
#define REG_TOFF_60		0x80
#define REG_TOFF_80		0xC0
// IC2_REG
// IC3_REG
// IC4_REG


typedef enum
{
	DRV8873_FAULT = -1,
	DRV8873_OK = 0,
	DRV8873_SS_SELECT,
	DRV8873_SS_DESELECT,
	DRV8873_INITIALIZE,
	DRV8873_TURNOFF
}DRV8873_Mode_t;

typedef enum
{
	FAULT_REG = 0x00,		// READ only register
	DIAG_REG =  0x01,		// READ only register
	IC1_REG =  0x02,
	IC2_REG =  0x03,
	IC3_REG =  0x04,
	IC4_REG =  0x05
}DRV8873_Registers_t;

class DRV8873 {
public:
	DRV8873(SPI_HandleTypeDef* spi, TIM_HandleTypeDef* tim, GPIO_Pins cs, uint32_t in1, uint32_t in2);

	uint8_t* Init(DRV8873_Mode_t mode);
	void Extend(void);
	void Retract(void);
	void Halt(void);
	DRV8873_Mode_t Write_REG(uint8_t reg, uint8_t data);

private:
	uint8_t Read_(uint8_t reg);
	DRV8873_Mode_t Write_(uint8_t reg, uint8_t data);
	void Select_CS(DRV8873_Mode_t state);
	void SetPWMDutyCycle(uint32_t channel, uint16_t dutyCycle);

	SPI_HandleTypeDef* _SPI_HANDLE;
	TIM_HandleTypeDef* _TIM_HANDLE;
	uint32_t _IN1;
	uint32_t _IN2;
	GPIO_Pins _CS;

	uint8_t status;
};


#endif /* DRV8873_DRV8873_HPP_ */
