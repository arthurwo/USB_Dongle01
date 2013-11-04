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
	

#ifdef __cplusplus
} // extern "C"
#endif
