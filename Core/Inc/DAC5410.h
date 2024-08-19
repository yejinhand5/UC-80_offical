#ifndef _DAC5410_H_
#define _DAC5410_H_

#include "stm32g4xx.h"
#include "main.h"


#define	Bit13_REXT											  0x0000							//Internal R.
#define	Bit12_OutEN											  0x1000							//Out Enable.
#define	Bit12_OutDisable								  	  0x0000							//Out Disable.
#define	B11_B8_SRCLK								 		  0x0F00							//SRCLK=1111(3.3kHz).
#define	B7_B5_SRStep							  			  0x00C0							//SR Step=110, 64LSB.
#define	B4_SREN											      0x0010							//=1SR Enable
#define	B3_DCEN_DISABLE							      		  0x0000							//=0,Dainy Disable
#define	B3_DCEN_ENABLE							      		  0x0008							//=0,Dainy Disable
#define	B2_B0_R2R1R0										  0x0006							//=110, 0-20mA.
//#define	B2_B0_R2R1R0										  0x0005							//=101, 4-24mA.

#define	DAC_ControlREG_ADDR									  0x55
#define	DAC_RSTREG_ADDR										  0x56
#define	DAC_DataREG_ADDR								   	  0x01

#define DAC_NO_DEVICE_1_mA									  ((float)(65535 * 1.0 / 24.0))
#define DAC_2_mA											  ((float)(65535 * 2.0 / 24.0))
#define DAC_3_mA											  ((float)(65535 * 3.0 / 24.0))
#define DAC_4_mA											  ((float)(65535 * 4.0 / 24.0))

#define DAC5410_LATCH_HIGH()		HAL_GPIO_WritePin(AD5410_LATCH_GPIO_Port, AD5410_LATCH_Pin, GPIO_PIN_SET)
#define DAC5410_LATCH_LOW()			HAL_GPIO_WritePin(AD5410_LATCH_GPIO_Port, AD5410_LATCH_Pin, GPIO_PIN_RESET)

#define DAC5410_SCLK_HIGH()			HAL_GPIO_WritePin(AD5410_SCLK_GPIO_Port, AD5410_SCLK_Pin, GPIO_PIN_SET)
#define DAC5410_SCLK_LOW()			HAL_GPIO_WritePin(AD5410_SCLK_GPIO_Port, AD5410_SCLK_Pin, GPIO_PIN_RESET)

#define DAC5410_SIMO_HIGH()			HAL_GPIO_WritePin(AD5410_SDIN_GPIO_Port, AD5410_SDIN_Pin, GPIO_PIN_SET)
#define DAC5410_SIMO_LOW()			HAL_GPIO_WritePin(AD5410_SDIN_GPIO_Port, AD5410_SDIN_Pin, GPIO_PIN_RESET)

#define DAC5410_CLEAR_HIGH()   		HAL_GPIO_WritePin(AD5410_CLEAR_GPIO_Port, AD5410_CLEAR_Pin, GPIO_PIN_SET)
#define DAC5410_CLEAR_LOW()    		HAL_GPIO_WritePin(AD5410_CLEAR_GPIO_Port, AD5410_CLEAR_Pin, GPIO_PIN_RESET)


extern void AD5410_init(void);
extern void AD5410_IOUT(float DATA1,float DATA2);  //0<DATA<20
extern void AD5410_IOUTx100(float DATA1,float DATA2);
#endif

