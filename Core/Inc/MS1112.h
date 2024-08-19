/*
 * MS1112.h
 *
 *  Created on: Oct 17, 2023
 *      Author: pyxis
 */

#ifndef MS1112_H_
#define MS1112_H_

#include "stm32g4xx.h"
#include "main.h"

#define MS1112_ID 0x90


extern int16_t ADCGetData(uint8_t ch);
extern uint16_t GetCurrentmAx1000(uint8_t ch);

#endif /* MS1112_H_ */
