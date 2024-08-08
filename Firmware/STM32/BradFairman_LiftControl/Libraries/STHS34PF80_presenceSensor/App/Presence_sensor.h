/*
 * Presence_sensor.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Syed Farhan Ahmed
 */

#ifndef STHS34PF80_PRESENCESENSOR_APP_PRESENCE_SENSOR_H_
#define STHS34PF80_PRESENCESENSOR_APP_PRESENCE_SENSOR_H_

//#include "stm32g0xx_hal_i2c.h"


static int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len);
static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);
static void platform_delay(uint32_t ms);
static void platform_init(void);
void Presence_Sensor_Init(I2C_HandleTypeDef* i2c_handle);
void Presence_Sensor_Loop(void);


#endif /* STHS34PF80_PRESENCESENSOR_APP_PRESENCE_SENSOR_H_ */
