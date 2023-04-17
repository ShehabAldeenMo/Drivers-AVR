/*
 * Servo_Inteface.h
 *
 *  Created on: 10/12/2022
 *      Author: Shehab Aldeen Mohammed
 */

#include "../LIB/STD_TYPES.h"

#ifndef SERVO_INTEFACE_H_
#define SERVO_INTEFACE_H_

void Servo_Init();
void SetAngleOfServo(u16 InitialAngle , u16 LastAngle );         /* to set the angle of servo */

#endif /* SERVO_INTEFACE_H_ */
