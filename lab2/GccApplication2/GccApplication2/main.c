/*
 * GccApplication2.c
 *
 * Created: 5/29/2023 10:35:15 PM
 * Author : Asus
 */ 

#include <avr/io.h>


int main(void)
{
	DDRD =0xFF;
	DDRB &= 0xFD;
	PORTB |= (1<<PINB1);
    /* Replace with your application code */
    while (1) 
    {
		if((PINB &(1<<PINB1))==0)
		{
			PORTD ^= (1<<PORTD1);
		}
		else{
		    PORTD &= ~(1<<PORTD1);
		}
    }
}

