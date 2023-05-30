/*
 * GccApplication1.c
 *
 * Created: 5/27/2023 11:25:21 AM
 * Author : Asus
 */ 

#include <avr/io.h>
#include "motor.h"

DDRD =0x00; //input for sensor
DDRB = 0xFF; // output for motors
char sensors; //it only takes one byte for 8 bit because here one pin will take only 8bit only
char line_break;
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		PORTB = PIND;
		sensors = PIND;
		
		//forward
		if ((sensors== 0xE7)||(sensors ==0xEF)||(sensors==0xF7))
		{
			//move forward
		}
		else if((sensors==0xF3)||(sensors==0xE3))
		{
				//left turn			
			
		}
		else if((sensors==0xF9)||(sensors==0xF1))
		{
			//left turn
			
		}
		else if((sensors==0xFC)||(sensors==0xFE))
		{
			//left turn
			
		}
		else if((sensors==0xF9)||(sensors==0xF1))
		{
			//left turn
			
		}
		else if((sensors==0xF8))
		{
			//left turn
			
		}
		//right turn
		else if((sensors==0xCF)||(sensors==0xC7))
		{
			//right turn
			
		}
		else if((sensors==0x87)||(sensors==0x97))
		{
			//right turn
			
		}
		else if((sensors==0x7F)||(sensors==0x3F))
		{
			//right turn
			
		}
		else if((sensors==0x1F))
		{
			//right turn
			
		}
		//90 degree turn
		//90 turn to right
		else if((sensors==0xE0)||(sensors==0xF0))
		{
			
		}
		//90 turn left
		else if ((sensors==0x07)||(sensors==0x0F))
		{
			
		}
		//actual turn right
		else if((sensors==0xE6)||(sensors==0xE4)||(sensors==0xCC))
		{
			
		}
		//actual turn left
		else if((sensors==0x67)||(sensors==0x27)||(sensors==0x33))
		{
			
		}
		else if ((sensors==0xFF)&&(line_break==0))
		{
			line_break=1
		}
		else
		{
			//stop robot
		}
    }
}

