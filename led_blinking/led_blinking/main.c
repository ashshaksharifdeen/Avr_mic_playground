/*
 * led_blinking.c
 *
 * Created: 5/16/2023 4:43:23 AM
 * Author : Asus
 */ 

#include <avr/io.h>
#include "config.h"
#include <stdint.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	uint16_t run =1; //we have to start at first led
	DDRD = 0xFF; // 0b11111111 >> entire d port is output
    while (1) 
    {
		PORTD =0x00; //it first turns off all LEDs. 0x00 is the hexadecimal equivalent of binary 00000000, which means all 8 bits are set to 0, representing a low state or off for each pin on port D.
		_delay_ms(250);
		PORTD = run; //set the current LED bit value at initial set to 0x01=1 
		_delay_ms(250);
		//bit 1 on (0x01) 0b00000001 >> binary value=1
		//bit 2 on (0x02) 0b00000010 >> binary value=2
		//bit 3 on (0x04) 0b00000100 >> binary value=4
		//bit 4 on (0x08) 0b00001000 >> binary value=8
		//bit 5 on (0x10) 0b00010000 >> binary value=16
		//bit 6 on (0x20) 0b00100000 >> binary value=32
		//bit 7 on (0x40) 0b01000000 >> binary value=64
		//bit 8 on (0x80) 0b10000000 >> binary value=128
		//bit 1 on (0x00) 0b00000001 >> binary value=1
		if(run>=0x80)
		{
			run =1;
		}
					else{
						run*=2;
					}
    }
}

