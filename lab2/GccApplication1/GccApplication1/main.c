/*
 * GccApplication1.c
 *
 * Created: 5/29/2023 9:15:40 PM
 * Author : Asus
 */ 

#include <avr/io.h>

int main(void)
{
	DDRD = 0xFF;
	DDRB &= 0xFD; // Clear bit 1 of DDRB to configure it as input

	PORTB |= (1 << PORTB1); // Enable the internal pull-up resistor for PINB1
	
	/* Replace with your application code */
	while (1)
	{
		if ((PINB & (1 << PINB1)) == 0) // Check if PINB1 is LOW (button is pressed)
		{
			PORTD ^= (1 << PORTD1); // Toggle bit 1 of PORTD to turn on/off the LED
		}
	}
}

