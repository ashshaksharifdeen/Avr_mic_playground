/*
 * GccApplication3.c
 *
 * Created: 5/29/2023 11:19:16 PM
 * Author : Asus
 */ 

#include <avr/io.h>


int main(void)
{
	DDRD = 0xFF; // Set PORTD pins as output for LEDs
	DDRB &= ~(1 << DDB1); // Set PINB1 as input for the switch
	PORTB |= (1 << PINB1); // Enable the internal pull-up resistor for PINB1

	uint16_t  count = 0;

	while (1)
	{
		if ((PINB & (1 << PINB1)) == 0) // Check if switch is pressed
		{
			// Increment count in binary format
			PORTD = count;
			PORTD +=(1<<PORTD);
			
			if (count > 9) // Reset count to 0 after reaching 15 (binary 1111)
			{
				count = 0;
				PIND = 0x00;
				}
			
			// Display binary count on LEDs
			
			count++;
			
			
			// Delay to debounce the switch
			//_delay_ms(200);
		}
	}
}