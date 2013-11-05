/*******************************************************
 USERAPI - USER-API library for
 communication with HID devices.

 Arthur Wo
 arthur.wo.tw@gmail.com

 11/05/2013

 Copyright 2013, All Rights Reserved.

********************************************************/

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif
	#include <setupapi.h>
	#include <winioctl.h>

	// Copied from inc/ddk/hidclass.h, part of the Windows DDK.
	#define HID_OUT_CTL_CODE(id)  \
		CTL_CODE(FILE_DEVICE_KEYBOARD, (id), METHOD_OUT_DIRECT, FILE_ANY_ACCESS)
	#define IOCTL_HID_GET_FEATURE                   HID_OUT_CTL_CODE(100)

#ifdef __cplusplus
} // extern "C"
#endif

#include <stdio.h>
#include <stdlib.h>

#include "userapi.h"

#ifdef _MSC_VER
	// Thanks Microsoft, but I know how to use strncpy().
	#pragma warning(disable:4996)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	int HID_API_EXPORT_CALL Simple_Add(double a, double b, double* c)
	{
		*c = a + b;

		if(*c > 0)
			return (1);
		else
			return (0);
	}

	int HID_API_EXPORT_CALL Simple_Add2(double *a, double *b, double* c)
	{
		*c = *a + *b;

		if(*c > 0)
			return (1);
		else
			return (0);
	}

	int HID_API_EXPORT_CALL Simple_Add3(double a, double b, double* c, int* lens)
	{
		c[0] = a;
		c[1] = b;
		c[2] = a + b;
		*lens = 3;

		if(c[2] > 0)
			return (1);
		else
			return (0);
	}
	
	DWORD	HID_API_EXPORT_CALL  GYI2C_Open      (DWORD DeviceType,DWORD DeviceInd,DWORD Reserved)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_Close     (DWORD DeviceType,DWORD DeviceInd)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_SetMode   (DWORD DeviceType,DWORD DeviceInd,BYTE ModeValue)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_GetMode   (DWORD DeviceType,DWORD DeviceInd)
	{	DWORD ans = 0;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_SetClk    (DWORD DeviceType,DWORD DeviceInd,DWORD ClkValue)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_GetClk    (DWORD DeviceType,DWORD DeviceInd)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_SetChannel(DWORD DeviceType,DWORD DeviceInd,BYTE ChannelValue)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_GetChannel(DWORD DeviceType,DWORD DeviceInd)
	{	DWORD ans = -1;
		return ans;
	}


	DWORD	HID_API_EXPORT_CALL  GYI2C_Read      (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO  pDataInfo)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_Write     (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO pDataInfo)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_Connect   (DWORD DeviceType,DWORD DeviceInd,DWORD Reserved)
	{	DWORD ans = -1;
		return ans;
	}


	DWORD	HID_API_EXPORT_CALL  GYI2C_SetIO     (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO pDataInfo)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_GetIO     (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO pDataInfo)
	{	DWORD ans = -1;
		return ans;
	}


	DWORD	HID_API_EXPORT_CALL  GYI2C_Start     (DWORD DeviceType,DWORD DeviceInd)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_WriteByte (DWORD DeviceType,DWORD DeviceInd,BYTE DataValue)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_ReadByte  (DWORD DeviceType,DWORD DeviceInd,BYTE AckValue)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_Stop      (DWORD DeviceType,DWORD DeviceInd)
	{	DWORD ans = -1;
		return ans;
	}

    
	DWORD	HID_API_EXPORT_CALL  GYI2C_Write2    (DWORD DeviceType,DWORD DeviceInd,BYTE *buf,int buflen)
	{	DWORD ans = -1;
		return ans;
	}

	DWORD	HID_API_EXPORT_CALL  GYI2C_Read2	(DWORD DeviceType,DWORD DeviceInd,BYTE *buf,DWORD buflen)
	{	DWORD ans = -1;
		return ans;
	}


#ifdef __cplusplus
} // extern "C"
#endif
