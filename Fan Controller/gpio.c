/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/



#include "gpio.h"
#include "common_macros.h"
#include "avr/io.h"


void GPIO_setupPinDirection(uint8 port_num,uint8 pin_num,Gpio_pinDirectionType direction)
{
	if(port_num >= NUM_OF_PORT || pin_num >= NUM_OF_PIN)
	{

	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}


void GPIO_writePin(uint8 port_num,uint8 pin_num,uint8 value)
{
	if(port_num >= NUM_OF_PORT || pin_num >= NUM_OF_PIN)
	{

	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;
		}
	}
}


uint8 GPIO_readPin(uint8 port_num,uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;

	if(port_num >= NUM_OF_PORT || pin_num >= NUM_OF_PIN)
	{

	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		}
	}
	return pin_value;
}


void GPIO_setupPortDirection(uint8 port_num,Gpio_portDirectionType direction)
{
	if(port_num >= NUM_OF_PORT )
	{

	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
}


void GPIO_writePort(uint8 port_num,uint8 value)
{
	if(port_num >= NUM_OF_PORT )
	{

	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			PORTA =value;
			break;
		case PORTB_ID:
			PORTB=value;
			break;
		case PORTC_ID:
			PORTC =value;
			break;
		case PORTD_ID:
			PORTD =value;
			break;
		}
	}
}


uint8 GPIO_readPort(uint8 port_num)
{
	uint8 port_value= LOGIC_LOW;
	if(port_num >= NUM_OF_PORT )
	{

	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			port_value=PINA;
			break;
		case PORTB_ID:
			port_value=PINB;
			break;
		case PORTC_ID:
			port_value=PINC;
			break;
		case PORTD_ID:
			port_value=PIND;
			break;
		}
	}
	return port_value;
}














