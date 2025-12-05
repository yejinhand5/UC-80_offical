/*
 * FreeModbus Libary: BARE Demo Application
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id$
 */

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"

#include "main.h"
/* ----------------------- private variables ----------------------------------*/
extern uint8_t RequestAddr;
uint8_t MODBUS_isRegWrite = 0;
/* ----------------------- Start implementation -----------------------------*/
/**
  * @brief  读输入寄存器
  * @param  pucRegBuffer：返回数据指针
						usAddress		：输入寄存器起始地址
						usNRegs			：要读的寄存器数目
  * @retval 错误代码
  */
eMBErrorCode
eMBRegInputCB(UCHAR *pucRegBuffer, USHORT usAddress, USHORT usNRegs)
{
	    uint16_t iRegIndex=usAddress-1;
		uint16_t *data_pointer;
		eMBErrorCode eStatus = MB_ENOERR;
		if(RequestAddr == FLOW_SLAVE_ADDR)
		{
			if(42001 <= usAddress&&usAddress <=42003)
			{
				if( usAddress + usNRegs <=  42004)
				{
					iRegIndex = usAddress-42000-1;
					data_pointer = (void *)&(sys.Parity);
				}
				else
				{
					eStatus=MB_ENOREG;
				}
			}
			else
			{
				eStatus=MB_ENOREG;
			}
		}
		else if (RequestAddr == AIAO_SLAVE_ADDR)
		{
			if(1<=usAddress&&usAddress<=2)
			{
				if(usAddress + usNRegs <= 3)
				{
					data_pointer= (void *)&Ma2Ai2AoReg.AI1;
				}
				else
				{
					eStatus=MB_ENOREG;
				}
			}
			else
			{
				eStatus=MB_ENOREG;
			}
		}

		else
		{
		     eStatus=MB_ENOREG;
		}

		if(eStatus==MB_ENOREG)		return eStatus;

		while( usNRegs > 0 )
		{

			//获取高位字节
			*pucRegBuffer++ = ( uint8_t )( *(data_pointer + iRegIndex) >> 8 );

			//获取低位字节
			*pucRegBuffer++ = ( uint8_t )( *(data_pointer +iRegIndex) & 0xFF );

			iRegIndex++;

			usNRegs--;
		}
}


/**
  * @brief  读/写保持寄存器
  * @param  pucRegBuffer：数据指针
			usAddress	：输入寄存器起始地址
			usNRegs		：要操作的寄存器数目
			eMode		: 对保持寄存器的操作（读或写）
  * @retval 错误代码
  */
eMBErrorCode
eMBRegHoldingCB(UCHAR *pucRegBuffer, USHORT usAddress,
		        USHORT usNRegs,eMBRegisterMode eMode)
{
	uint16_t iRegIndex = usAddress - 1;
	uint16_t *data_pointer;
	eMBErrorCode eStatus = MB_ENOERR;
	if(RequestAddr == FLOW_SLAVE_ADDR)
	{
		if(1<=usAddress&&usAddress<=2)
		{
			if(usAddress + usNRegs <= 3)
			{
				data_pointer= (void *)&(PulseReg);
			}
			else
			{
				eStatus=MB_ENOREG;
			}
		}
		else if (42001 <=usAddress&& usAddress <=42003)
		{
			if(usAddress + usNRegs <= 42004)
			{
				iRegIndex = usAddress-42000-1;
				data_pointer =  (void *)&(sys.Parity);
			}
			else
			{
				eStatus=MB_ENOREG;
			}
		}
		else
		{
			eStatus=MB_ENOREG;
		}
	}

	else if (RequestAddr == AIAO_SLAVE_ADDR)
	{
		if(1<=usAddress&&usAddress<=2)
		{
			if(usAddress + usNRegs <= 3)
			{
				data_pointer= (void *)&(Ma2Ai2AoReg.AO1);
			}
			else
			{
				eStatus=MB_ENOREG;
			}
		}
		else
		{
			eStatus=MB_ENOREG;
		}
	}

	else if (RequestAddr == POWER_SWITCH_ADDR)
	{
		if( 48001 <=usAddress&&usAddress<=48002)
		{
			if( usAddress + usNRegs <=  48003)
			{
				iRegIndex = usAddress-48000-1;
				data_pointer = (void *)&(control_settings.usOutV1) ;
			}
			else
			{
				eStatus=MB_ENOREG;
			}
		}
		else
		{
			eStatus=MB_ENOREG;
		}
	}

	else if(RequestAddr == RELAY_CONTROL_ADDR)
	{
	   if(1<=usAddress&&usAddress<=5)
	   {
		  if(usAddress + usNRegs <= 6)
		  {
			  data_pointer = (void *)&(control_relay.usRelay1);
		  }
		  else
		  {
			 eStatus=MB_ENOREG;
		  }
	   }
	   else
	   {
			eStatus=MB_ENOREG;
	   }
	}

	else
	{
		eStatus=MB_ENOREG;
	}
	if(eStatus==MB_ENOREG)
	{
		return eStatus;
	}

	//根据地址确定要访问的寄存器
	switch(eMode)
	{
		//读保持寄存器
		case MB_REG_READ:
			while( usNRegs > 0 )
			{

				//获取高位字节
				*pucRegBuffer++ = ( uint8_t )( *(data_pointer + iRegIndex) >> 8 );

				//获取低位字节
				*pucRegBuffer++ = ( uint8_t )( *(data_pointer + iRegIndex) & 0xFF );

				iRegIndex++;

				usNRegs--;
			}
			break;

		//写保持寄存器
		case MB_REG_WRITE:
			while( usNRegs > 0 )
			{
				*(data_pointer + iRegIndex) = *pucRegBuffer++ << 8;
				*(data_pointer + iRegIndex) |= *pucRegBuffer++;

				iRegIndex++;
				usNRegs--;
			}
			if(42001<=usAddress&&usAddress<= 42003)
			{
				MODBUS_isRegWrite = 1;
			}
			break;

		default:
			break;
	}
}

/**
  * @brief  读/写线圈寄存器
  * @param  pucRegBuffer：数据指针
			usAddress	：寄存器起始地址
			usNCoils	：要操作的线圈数目
			eMode		：操作模式
  * @retval 错误代码
  */
eMBErrorCode
eMBRegCoilsCB(UCHAR *pucRegBuffer, USHORT usAddress, USHORT usNCoils,
              eMBRegisterMode eMode)
{
    return MB_ENOREG;
}

/**
  * @brief  读离散寄存器
  * @param  pucRegBuffer：返回数据指针
			usAddress	：寄存器起始地址
			usNDiscrete	：要读的寄存器数目
  * @retval 错误代码
  */
eMBErrorCode
eMBRegDiscreteCB(UCHAR *pucRegBuffer, USHORT usAddress, USHORT usNDiscrete)
{
    return MB_ENOREG;
}
