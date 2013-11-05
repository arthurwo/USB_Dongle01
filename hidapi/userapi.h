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
	BYTE SlaveAddr;			// �]�ƪ��z��}�Abit7-1����
	BYTE Databuffer[520];	// Data ���媺�ƾڡF
	UINT WriteNum;			// ��}�M��ƪ��`�Ӽ�
	UINT ReadNum;			// �ݭnŪ����ƪ��Ӽ�
	BYTE IoSel;				// 1 ��ܳQ��ܡA�N�QŪ/�g
	BYTE IoData;			// IO�f���A�Abit3��0���O���4��IO�f
							// �u���PIoSel����1����ۦP����Ȧ���
	UINT DlyMsRead;			// I2CŪ�ާ@�ɡAPC�o�XŪ�R�O��A���ɦh��ms�ШDŪ�쪺�ƾڡC
	BYTE Reserved[4];		// Reserved �t�ΫO�d�C
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
	DWORD	HID_API_EXPORT_CALL  GYI2C_Connect   (DWORD DeviceType,DWORD DeviceInd,DWORD Reserved);//�d��USB-I2C�]�ƬO�_�q�t�Τ����u�Ϊ̳Q�ޥX�C

	DWORD	HID_API_EXPORT_CALL  GYI2C_SetIO     (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO pDataInfo);
	DWORD	HID_API_EXPORT_CALL  GYI2C_GetIO     (DWORD DeviceType,DWORD DeviceInd,pGYI2C_DATA_INFO pDataInfo);

	DWORD	HID_API_EXPORT_CALL  GYI2C_Start     (DWORD DeviceType,DWORD DeviceInd);
	DWORD	HID_API_EXPORT_CALL  GYI2C_WriteByte (DWORD DeviceType,DWORD DeviceInd,BYTE DataValue);
	DWORD	HID_API_EXPORT_CALL  GYI2C_ReadByte  (DWORD DeviceType,DWORD DeviceInd,BYTE AckValue);
	DWORD	HID_API_EXPORT_CALL  GYI2C_Stop      (DWORD DeviceType,DWORD DeviceInd);
    //GYI2C_Write2,GYI2C_Read2��ƻPGYI2C_Read, GYI2C_Write��ƥ\��@�ˡA�ȬO�J�f�Ѽ������t�O
	DWORD	HID_API_EXPORT_CALL  GYI2C_Write2    (DWORD DeviceType,DWORD DeviceInd,BYTE *buf,int buflen);
					                                                           //WRITE buf[]=	A0,00,11,22,33,44	
	DWORD	HID_API_EXPORT_CALL  GYI2C_Read2	(DWORD DeviceType,DWORD DeviceInd,BYTE *buf,DWORD buflen);
/*
buf[0]=slaveaddr;	//I2C�q�]�Ʀ�}
buf[1]=WriteData0;	//�p�G�O��e��}Ū�A�h���ݭn
					//���w��}Ū���ɭԡA�ݭn�bI2CŪ���e���g�J��������}�Ψ�L�R�O�C��pŪAT24C02,�h��24c02��������}
buf[2]=WriteData1;	//�p�G�O��r�`������}�A�άO���e��}Ū�A�h���ݭnWriteData1�C
...
buf[buflen-2]=ReadNum>>8;//��8�줸�A�ݭnŪ����Ʀ줸�խӼ�
buf[buflen-1]=ReadNum;
�}�C���̫�2�Ӧ줸�ժ�ܻݭnŪ�����줸�խӼơC
�|�ҡGAT24C02���w�a�}Ū : A1,00,01,00	//Ū�ƾڪ���0100��256
	         ��e�a�}Ū : A1,01,00 //����Ū�A�����w�����a�}�C
	  AT24C256���w�a�}Ū�GA1,00,00,01,00
*/

/********************************************************/
// TI Adapter

#ifdef __cplusplus
}
#endif

#endif