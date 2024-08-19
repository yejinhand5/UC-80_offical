/*
 * MS1112.c
 *
 *  Created on: Oct 17, 2023
 *      Author: pyxis
 */
#include "MS1112.h"

uint8_t AdcRes[3];

int16_t ADCGetData(uint8_t ch)
{
	uint8_t config;
	if(ch==0){config =0xDC; }
	else {config =0xFC;}
	HAL_I2C_Master_Transmit(&hi2c2,MS1112_ID,&config,1,100);
	HAL_Delay(100);
	HAL_I2C_Master_Receive(&hi2c2,MS1112_ID,AdcRes,3,100);
	int16_t res = AdcRes[0];
	res<<=8;
	res+=AdcRes[1];
	return res;
}

uint16_t GetCurrentmAx1000(uint8_t ch)
{
	float code = ADCGetData(ch);
	float vot = 2.048f/32768.0f*code;
	float mA = vot*1000.0f/100.0f;
	if(mA>20.0f)mA=20.0f;
	else if(mA<0.0f)mA=0.0f;

	return (uint16_t)(mA*1000.0f);
}


