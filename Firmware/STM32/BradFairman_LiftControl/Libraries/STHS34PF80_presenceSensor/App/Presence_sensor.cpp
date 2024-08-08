/*
 * Presence_sensor.cpp
 *
 *  Created on: Aug 8, 2024
 *      Author: Syed Farhan Ahmed
 */

#include <main.h>
#include <Presence_sensor.h>
#include <sths34pf80_reg.h>
//#include "stm32g0xx_hal.h"
//#include <string.h>
//#include <stdio.h>

#define    BOOT_TIME         100 //ms


//static uint8_t tx_buffer[1000];
static stmdev_ctx_t dev_ctx;
static int wakeup_thread = 0;


void sths34pf80_tmos_presence_detection_handler(void)
{
  wakeup_thread = 1;
}

void Presence_Sensor_Init(I2C_HandleTypeDef* i2c_handle) {

  uint8_t whoami;
  uint32_t status;
  sths34pf80_lpf_bandwidth_t lpf_m, lpf_p, lpf_p_m, lpf_a_t;

  /* Initialize mems driver interface */
  dev_ctx.write_reg = platform_write;
  dev_ctx.read_reg = platform_read;
  dev_ctx.mdelay = platform_delay;
  dev_ctx.handle = i2c_handle;

  /* Initialize platform specific hardware */
  // platform_init();

//  HAL_GPIO_WritePin(PRESENCE_CS_GPIO_Port, PRESENCE_CS_Pin, GPIO_PIN_RESET);
//  platform_delay(BOOT_TIME);
//  HAL_GPIO_WritePin(PRESENCE_CS_GPIO_Port, PRESENCE_CS_Pin, GPIO_PIN_SET);
  /* Wait sensor boot time */
  platform_delay(BOOT_TIME);

  /* Check device ID */
  do {
	  status = sths34pf80_device_id_get(&dev_ctx, &whoami);
  }
  while (whoami != STHS34PF80_ID || status != 0);
//	while(1);

  /* Set averages (AVG_TAMB = 8, AVG_TMOS = 32) */
  status = sths34pf80_avg_tobject_num_set(&dev_ctx, STHS34PF80_AVG_TMOS_32);
  if(status) while(1);
  status = sths34pf80_avg_tambient_num_set(&dev_ctx, STHS34PF80_AVG_T_8);
  if(status) while(1);
  /* read filters */
  status = sths34pf80_lpf_m_bandwidth_get(&dev_ctx, &lpf_m);
  if(status) while(1);
  status = sths34pf80_lpf_p_bandwidth_get(&dev_ctx, &lpf_p);
  if(status) while(1);
  status = sths34pf80_lpf_p_m_bandwidth_get(&dev_ctx, &lpf_p_m);
  if(status) while(1);
  status = sths34pf80_lpf_a_t_bandwidth_get(&dev_ctx, &lpf_a_t);
  if(status) while(1);

  /* Set BDU */
  status =  sths34pf80_block_data_update_set(&dev_ctx, 1);
  if(status) while(1);
  status = sths34pf80_presence_threshold_set(&dev_ctx, 200);
  if(status) while(1);
  status = sths34pf80_presence_hysteresis_set(&dev_ctx, 20);
  if(status) while(1);
  status = sths34pf80_motion_threshold_set(&dev_ctx, 300);
  if(status) while(1);
  status = sths34pf80_motion_hysteresis_set(&dev_ctx, 30);
  if(status) while(1);
  status = sths34pf80_algo_reset(&dev_ctx);
  if(status) while(1);
  /* Set interrupt */
  status = sths34pf80_int_or_set(&dev_ctx, STHS34PF80_INT_PRESENCE);
  if(status) while(1);
  status = sths34pf80_route_int_set(&dev_ctx, STHS34PF80_INT_OR);
  if(status) while(1);
  /* Set ODR */
  status = sths34pf80_odr_set(&dev_ctx, STHS34PF80_ODR_AT_30Hz);
  if(status) while(1);

}

void Presence_Sensor_Loop(void) {
	sths34pf80_func_status_t func_status;
	uint8_t motion;
	uint8_t presence;

	/* handle event in a "thread" alike code */
	if (wakeup_thread) {
	  wakeup_thread = 0;
	  motion = 0;
	  presence = 0;

	  do {
		sths34pf80_func_status_get(&dev_ctx, &func_status);

		if (func_status.pres_flag != presence)
		{
		  presence = func_status.pres_flag;

		  if (presence) {
			// sprintf((char *)tx_buffer, "Start of Presence\r\n");
			// tx_com(tx_buffer, strlen((char const *)tx_buffer));

			// LED ON HERE
				HAL_GPIO_WritePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin, GPIO_PIN_SET);
		  } else {
			// sprintf((char *)tx_buffer, "End of Presence\r\n");
			// tx_com(tx_buffer, strlen((char const *)tx_buffer));

			// LED OFF HERE
				HAL_GPIO_WritePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin, GPIO_PIN_RESET);
		  }
		}

		if (func_status.mot_flag != motion)
		{
		  motion = func_status.mot_flag;

		  if (motion) {
			// sprintf((char *)tx_buffer, "Motion Detected!\r\n");
			// tx_com(tx_buffer, strlen((char const *)tx_buffer));
		  }
		}
	  } while (func_status.pres_flag);
	}
}


/*
 * @brief  Write generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to write
 * @param  bufp      pointer to data to write in register reg
 * @param  len       number of consecutive register to write
 *
 */
static int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp,
                              uint16_t len)
{
  HAL_I2C_Mem_Write((I2C_HandleTypeDef*)handle, STHS34PF80_I2C_ADD, reg,
                    I2C_MEMADD_SIZE_8BIT, (uint8_t *)bufp, len, 1000);
  return 0;
}

/*
 * @brief  Read generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to read
 * @param  bufp      pointer to buffer that store the data read
 * @param  len       number of consecutive register to read
 *
 */
static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp,
                             uint16_t len)
{
	HAL_StatusTypeDef ret = HAL_I2C_Mem_Read((I2C_HandleTypeDef*)handle, STHS34PF80_I2C_ADD, reg,
                   I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
	return ret;

//	HAL_StatusTypeDef ret;
//	uint8_t Reg[1];
//	Reg[0]=reg;
//
//	ret=HAL_I2C_Master_Transmit((I2C_HandleTypeDef*)handle, STHS34PF80_I2C_ADD, Reg, len, 1000);
//	if(len>0 && !ret){
//		ret=HAL_I2C_Master_Receive((I2C_HandleTypeDef*)handle, STHS34PF80_I2C_ADD, bufp, len, 1000);
//	}
//	else if(ret){
//	  // error
//	}
//	return ret;
}

/*
 * @brief  platform specific delay (platform dependent)
 *
 * @param  ms        delay in ms
 *
 */
static void platform_delay(uint32_t ms)
{
  HAL_Delay(ms);
}

/*
 * @brief  platform specific initialization (platform dependent)
 */
static void platform_init(void)
{
//#if defined(STEVAL_MKI109V3)
//  TIM3->CCR1 = PWM_1V8;
//  TIM3->CCR2 = PWM_1V8;
//  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
//  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
//  HAL_Delay(1000);
//#endif
}

