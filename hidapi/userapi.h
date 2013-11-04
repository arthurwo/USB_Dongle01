/*******************************************************
 USERAPI - USER-API library for
 communication with HID devices.

 Arthur Wo
 arthur.wo.tw@gmail.com

 11/05/2013

 Copyright 2013, All Rights Reserved.

********************************************************/

/** @file
 * @defgroup USRAPI userapi API
 */

#ifndef USERAPI_H__
#define USERAPI_H__

#include <hidapi.h>

#define USR_API_EXPORT __declspec(dllexport)
#define USR_API_CALL

#define USR_API_EXPORT_CALL USR_API_EXPORT USR_API_CALL /**< API export and call macro*/

#ifdef __cplusplus
extern "C" {
#endif

	/** @brief Simple_Add test.

		@ingroup USRAPI
		@param a >> input.
		@param b >> input.
		@param c >> output, pointer sum of a + b.

		@returns
			0: success
			1: busy
	*/
	int HID_API_EXPORT_CALL Simple_Add(double a, double b, double* c);
	
	/** @brief Simple_Add test2.

		@ingroup USRAPI
		@param a >> input, pointer.
		@param b >> input, pointer.
		@param c >> output, pointer sum of a + b.

		@returns
			0: success
			1: busy
	*/
	int HID_API_EXPORT_CALL Simple_Add2(double *a, double *b, double* c);
	
	/** @brief Simple_Add test3.

		@ingroup USRAPI
		@param a >> input.
		@param b >> input.
		@param c >> output, array.
		@param d >> output, length of array.
		
		@returns
			0: success
			1: busy
	*/
	int HID_API_EXPORT_CALL Simple_Add3(double a, double b, double* c, int* lens);

		
#ifdef __cplusplus
}
#endif

#endif