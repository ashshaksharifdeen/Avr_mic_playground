/*
 * GccApplication1.c
 *
 * Created: 5/24/2023 8:32:46 AM
 * Author : Asus
 */ 
#define F_CPU 16000000UL
#include <stdint.h>
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
	uint16_t run = 1;
	
	DDRD = 0xFF; //0b11111111
	
	DDRB &= 0xF9;
	/*
	In the case of 0xF9 (binary 11111001), the 2nd and 3rd bits (B1 and B2) are set to 0(make these as input register b1 and b2 other remaining their own state), while the other bits remain unchanged.
	pins B3 and B5 as input pins using the bitmask 0xE7 (binary 11100111).
	Bitmask:  1  1  1  0  0  1  1  1
	PORTB:    B7 B6 B5 B4 B3 B2 B1 B0
	*/
	
	PORTB |= (1 << PORTB1) | (1 << PORTB2); //enabling the state to internal pull-up resistor to high
	
	while (1)
	{
		//here if we press the push button it disable the pullup resitor and b1 goes to low
		if((PORTB & (1 << PINB1)) == 0){
			//here the previous bit is in PORTB and the current bit in PINB1
			_delay_ms(250);
			if(run >= 0x80){
				run = 1; //if it goes to last bit it again start it from first bit
			    
			}
			else{
				run *= 2;
			}
		}
		//reversing the direction of led by dividing the bit
		if((PORTB & (1 << PINB2)) == 0){
			_delay_ms(250);
			if(run <= 1){
				run = 0x80; //if it goes to one and it start if from last bit pi
			}
			else{
				run /= 2;
			}
		}


		PORTD = run; // bit 7 off 0b00000000

	}
}

