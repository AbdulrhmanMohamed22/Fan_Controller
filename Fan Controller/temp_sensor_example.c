/*
 ================================================================================================
 Name        : temp_sensor_example.c
 Author      : Mohamed Tarek
 Description : Test the ADC driver designed with polling technique using LM35 Temperature Sensor
 Date        : 5/9/2015
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include <avr/io.h>
#include "dc_motor.h"


int main(void)
{
	uint8 temp;
	ADC_ConfigType  ADC_Configuration ={INTERNAL_AREF,F_CPU_8}; /* choose configurations */
	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Configuration); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC_MOTOR driver */
	LCD_moveCursor(0,3);
	LCD_displayString("FAN is ");

	while(1)
	{
		temp = LM35_getTemperature(); /* get temperature of sensor */
		LCD_moveCursor(0,10);
		if(temp<30)
		{
			LCD_displayString("OFF");
			DcMotor_Rotate(STOP, 0);
		}
		else if(temp >=30 && temp <60)
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CLOCKWISE, 25);
		}
		else if(temp >=60 && temp <90)
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CLOCKWISE, 50);
		}
		else if(temp >=90 && temp <120)
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CLOCKWISE, 75);
		}
		else
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CLOCKWISE, 100);
		}

		LCD_moveCursor(1,3);
		LCD_displayString("Temp = ");
		LCD_intgerToString(temp);
		LCD_displayString("C ");

	}
}
