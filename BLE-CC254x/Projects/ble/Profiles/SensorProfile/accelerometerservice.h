/**************************************************************************************************
  Filename:       accelerometerservice.h
  Revised:        $Date: 2013-02-07 05:39:50 -0800 (Thu, 07 Feb 2013) $
  Revision:       $Revision: 33009 $

  Description:    Accelerometer service definitions and prototypes


  Copyright 2012  Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED ?AS IS? WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
**************************************************************************************************/

#ifndef ACCELEROMETERSERVICE_H
#define ACCELEROMETERSERVICE_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */

/*********************************************************************
 * CONSTANTS
 */

// Profile Parameters
#define ACCELEROMETER_DATA              2       // R  uint8 - Profile Attribute value
#define ACCELEROMETER_CONF              3       // RW uint8 - Profile Attribute value
#define ACCELEROMETER_PERI              4       // RW uint8 - Profile Attribute Value

// Service UUID
#define ACCELEROMETER_SERV_UUID         0xAA10  // F0000000-0451-4000-B000-00000000-AA10
#define ACCELEROMETER_DATA_UUID         0xAA11
#define ACCELEROMETER_CONF_UUID         0xAA12
#define ACCELEROMETER_PERI_UUID         0xAA13

// Sensor Profile Services bit fields
#define ACCELEROMETER_SERVICE           0x00000002

// Length of sensor data in bytes
#define ACCELEROMETER_DATA_LEN          3

  // Minimum accelerometer period
#define ACCELEROMETER_MIN_PERIOD        100
#define ACCELEROMETER_TIME_UNIT         10 // resolution 10 ms

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * Profile Callbacks
 */

// Callback when a characteristic value has changed
typedef NULL_OK void (*accelChange_t)( uint8 paramID );

typedef struct
{
  accelChange_t        pfnAccelChange;  // Called when characteristic value changes
} accelCBs_t;

/*********************************************************************
 * API FUNCTIONS
 */


/*
 * Acc_AddService- Initializes the Sensor GATT Profile service by registering
 *          GATT attributes with the GATT server.
 *
 * @param   services - services to add. This is a bit map and can
 *                     contain more than one service.
 */
extern bStatus_t Accel_AddService( uint32 services );

/*
 * Acc_RegisterAppCBs - Registers the application callback function.
 *                    Only call this function once.
 *
 *    appCallbacks - pointer to application callbacks.
 */
extern bStatus_t Accel_RegisterAppCBs( accelCBs_t *appCallbacks );

/*
 * Acc_SetParameter - Set a Sensor GATT Profile parameter.
 *
 *    param - Profile parameter ID
 *    len - length of data to right
 *    value - pointer to data to write.  This is dependent on
 *          the parameter ID and WILL be cast to the appropriate
 *          data type (example: data type of uint16 will be cast to
 *          uint16 pointer).
 */
extern bStatus_t Accel_SetParameter( uint8 param, uint8 len, void *value );

/*
 * Acc_GetParameter - Get a Sensor GATT Profile parameter.
 *
 *    param - Profile parameter ID
 *    value - pointer to data to write.  This is dependent on
 *          the parameter ID and WILL be cast to the appropriate
 *          data type (example: data type of uint16 will be cast to
 *          uint16 pointer).
 */
extern bStatus_t Accel_GetParameter( uint8 param, void *value );


/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* ACCELEROMETERSERVICE_H */

