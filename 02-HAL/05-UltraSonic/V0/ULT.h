/*
 *     File name:  ULT.h
 *        Author: Saleh
 *   Description: Header file of the Ultrasonic-Sensor-Driver
 *    Created on: Oct 19, 2022
 */

#ifndef ULT_H_
#define ULT_H_


/***************************************************************************************************
                                          * Functions Definitions *
****************************************************************************************************/

/*
 * Description:
 *            Function to initialize the Ultrasonic-Driver .
 */
void Ultrasonic_init(void);

/*
 * Description:
 *            Function to trigger pulse to the Ultrasonic-Trig Pin .
 */
void Ultrasonic_Trigger(void);

/*
 * Description:
 *            Function to calculate the distance in cm.
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description:
 *            Function to calculate the pulse width & it's the call back function  in cm.
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULT_H_ */
