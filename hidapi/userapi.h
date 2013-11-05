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

#if defined(DLL_BUILD)
	#define USR_API_EXPORT __declspec(dllexport)
	#define USR_API_CALL
#else
	#define USR_API_EXPORT __declspec(dllimport)
	#define USR_API_CALL
#endif

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

/********************************************************/
//#include "VCI_GYI2C.H"

#define DEV_GY7501A		1   //1ch-I2C
#define DEV_GY7512		2	//2ch-I2C
#define DEV_GY7514		3	//4ch-I2C
#define DEV_GY7518		4	//8ch-I2C
#define DEV_GY7503		5	//1ch-I2C
#define DEV_GY7506		6	//1ch-I2C,module/
#define DEV_GY7601		7	//1ch-I2C
#define DEV_GY7602		8	//2ch-I2C
#define DEV_GY7604		9	//4ch-I2C
#define DEV_GY7608		10	//8ch-I2C

typedef struct GYI2C_DATA_INFO{
	BYTE SlaveAddr;			// 設備物理位址，bit7-1有效
	BYTE Databuffer[520];	// Data 報文的數據；
	UINT WriteNum;			// 位址和資料的總個數
	UINT ReadNum;			// 需要讀的資料的個數
	BYTE IoSel;				// 1 表示被選擇，將被讀/寫
	BYTE IoData;			// IO口狀態，bit3－0分別表示4個IO口
							// 只有與IoSel中為1的位相同的位值有效
	UINT DlyMsRead;			// I2C讀操作時，PC發出讀命令後，延時多少ms請求讀到的數據。
	BYTE Reserved[4];		// Reserved 系統保留。
	}GYI2C_DATA_INFO,*pGYI2C_DATA_INFO;

	DWORD	HID_API_EXPORT_CALL  GYI2C_Open      (DWORD DeviceType,DWORD DeviceInd,DWORD Reserved);
	DWORD	HID_API_EXPORT_CALL  GYI2C_Close     (DWORD DeviceType,DWORD DeviceInd);

	/** @brief Set Operation mode as Easy I2C or Timing I2C

		@ingroup USRAPI
		@param DeviceType >> input. 1 Only for DEV_GY7501A
		@param DeviceInd  >> input. 0 Only for DEV_GY7501A
		@param ModeValue  >> input. 0 = Easy I2C ; 1 = Timing I2C

		@returns
		   -1: device off or device not found
			0: fail
			1: success
	*/
	DWORD	HID_API_EXPORT_CALL  GYI2C_SetMode   (DWORD DeviceType,DWORD DeviceInd,BYTE ModeValue);

	/** @brief Get Operation mode

		@ingroup USRAPI
		@param DeviceType >> input. 1 Only for DEV_GY7501A
		@param DeviceInd  >> input. 0 Only for DEV_GY7501A

		@returns
			0: Easy I2C
			1: Timing I2C
	*/
	DWORD	HID_API_EXPORT_CALL  GYI2C_GetMode   (DWORD DeviceType,DWORD DeviceInd);

	/** @brief Set I2C clock

		@ingroup USRAPI
		@param DeviceType >> input. 1 Only for DEV_GY7501A
		@param DeviceInd  >> input. 0 Only for DEV_GY7501A
		@param ClkValue   >> input. 1 - 400, unit: 1KHz

		@returns
		   -1: device off or device not found
			0: fail
			1: success
	*/
	DWORD	HID_API_EXPORT_CALL  GYI2C_SetClk    (DWORD DeviceType,DWORD DeviceInd,DWORD ClkValue);

	/** @brief Get I2C clock

		@ingroup USRAPI
		@param DeviceType >> input. 1 Only for DEV_GY7501A
		@param DeviceInd  >> input. 0 Only for DEV_GY7501A

		@returns
			1 - 400, unit: 1KHz
	*/
	DWORD	HID_API_EXPORT_CALL  GYI2C_GetClk    (DWORD DeviceType,DWORD DeviceInd);

	/** @brief Set I2C Channel

		@ingroup USRAPI
		@param DeviceType >> input. 1 Only for DEV_GY7501A
		@param DeviceInd  >> input. 0 Only for DEV_GY7501A
		@param ChValue   >> 

		@returns
		   -1: device off or device not found
			0: fail
			1: success
	*/
	DWORD	HID_API_EXPORT_CALL  GYI2C_SetChannel(DWORD DeviceType,DWORD DeviceInd,BYTE ChannelValue);

	/** @brief Get I2C Channel

		@ingroup USRAPI
		@param DeviceType >> input. 1 Only for DEV_GY7501A
		@param DeviceInd  >> input. 0 Only for DEV_GY7501A
		@param ChValue   >> 

		@returns
		   Currently channel selected
	*/
	DWORD	HID_API_EXPORT_CALL  GYI2C_GetChannel(DWORD DeviceType,DWORD DeviceInd);

	DWORD	HID_API_EXPORT_CALL  GYI2C_Read      (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO  pDataInfo);
	DWORD	HID_API_EXPORT_CALL  GYI2C_Write     (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO pDataInfo);
	DWORD	HID_API_EXPORT_CALL  GYI2C_Connect   (DWORD DeviceType,DWORD DeviceInd,DWORD Reserved);//查詢USB-I2C設備是否從系統中掉線或者被拔出。

	DWORD	HID_API_EXPORT_CALL  GYI2C_SetIO     (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO pDataInfo);
	DWORD	HID_API_EXPORT_CALL  GYI2C_GetIO     (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO pDataInfo);

	DWORD	HID_API_EXPORT_CALL  GYI2C_Start     (DWORD DeviceType,DWORD DeviceInd);
	DWORD	HID_API_EXPORT_CALL  GYI2C_WriteByte (DWORD DeviceType,DWORD DeviceInd,BYTE DataValue);
	DWORD	HID_API_EXPORT_CALL  GYI2C_ReadByte  (DWORD DeviceType,DWORD DeviceInd,BYTE AckValue);
	DWORD	HID_API_EXPORT_CALL  GYI2C_Stop      (DWORD DeviceType,DWORD DeviceInd);
    //GYI2C_Write2,GYI2C_Read2函數與GYI2C_Read, GYI2C_Write函數功能一樣，僅是入口參數類型差別
	DWORD	HID_API_EXPORT_CALL  GYI2C_Write2    (DWORD DeviceType,DWORD DeviceInd,BYTE *buf,int buflen);
					                                                           //WRITE buf[]=	A0,00,11,22,33,44	
	DWORD	HID_API_EXPORT_CALL  GYI2C_Read2	(DWORD DeviceType,DWORD DeviceInd,BYTE *buf,DWORD buflen);
/*
buf[0]=slaveaddr;	//I2C從設備位址
buf[1]=WriteData0;	//如果是當前位址讀，則不需要
					//指定位址讀的時候，需要在I2C讀之前先寫入的內部位址或其他命令。比如讀AT24C02,則為24c02的內部位址
buf[2]=WriteData1;	//如果是單字節內部位址，或是對當前位址讀，則不需要WriteData1。
...
buf[buflen-2]=ReadNum>>8;//高8位元，需要讀的資料位元組個數
buf[buflen-1]=ReadNum;
陣列的最後2個位元組表示需要讀取的位元組個數。
舉例：AT24C02指定地址讀 : A1,00,01,00	//讀數據長度0100＝256
	         當前地址讀 : A1,01,00 //直接讀，不指定內部地址。
	  AT24C256指定地址讀：A1,00,00,01,00
*/

/********************************************************/
// TI Adapter

#ifdef __cplusplus
}
#endif

#endif