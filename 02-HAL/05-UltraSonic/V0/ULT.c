/*
 *     File name:  ULT.c
 *        Author: Saleh
 *   Description: Source file of the Ultrasonic-Sensor-Driver
 *    Created on: Oct 19, 2022
 */

#ifndef ULT_C_
#define ULT_C_
#include "ULT.h"
#include "ICU.h"
#include "gpio.h"

ICU_ConfigureType ICU_Config={F8_CPU_CLOCK,RISING};
uint8  g_edgeCount=0;
uint16 g_highTime=0;

void Ultrasonic_init(void)
{
	/* Initialize the ICU-Driver */
	ICU_init(ICU_Config);

	/* set the address of the call back function */
	ICU_setTheCallBack(Ultrasonic_edgeProcessing);

	/* Set the direction of the trigger pin as output pin */
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
}
/*
 *       Description:
 *                 Send the trigger pulse
 */
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_HIGH);
}

/*
 * Description:
 *           Function to calculate the distance in cm.
 */
uint16 Ultrasonic_readDistance(void)
{
	uint16 distance;
	Ultrasonic_Trigger();
    if(g_edgeCount==2)
    {
    	distance=(uint16)((float)g_highTime/58.8);
    	g_edgeCount=0;
    }
    return distance;
}

/*
 * Description:
 *          Function to set the required edge detection.
 */
void Ultrasonic_edgeProcessing (void)
{
    ++g_edgeCount;
	if(g_edgeCount==1)
	{
		ICU_clearTimer1Value();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if (g_edgeCount==2)
	{
		g_highTime = ICU_getInputCapture();
		ICU_clearTimer1Value();
		ICU_setEdgeDetectionType(RISING);
	}
}
#endif /* ULT_C_ */
