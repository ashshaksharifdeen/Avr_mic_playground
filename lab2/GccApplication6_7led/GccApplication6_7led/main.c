/*
 * GccApplication6_7led.c
 *
 * Created: 5/30/2023 2:42:45 AM
 * Author : Asus
 */ 

/*
 * GccApplication5_3.c
 *
 * Created: 5/30/2023 2:05:32 AM
 * Author : Asus
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xFF; // Set PORTD pins as output for LEDs
	DDRB &= ~(1 << DDB1); // Set PINB1 as input for the switch
	PORTB |= (1 << PINB1); // Enable the internal pull-up resistor for PINB1

	while (1)
	{
		if ((PINB & (1 << PINB1)) == 0) // Check if switch is pressed
		{
			for (int i = 0; i < 8; i++)
			{
				PORTD |= (1 << i); // Turn on the current LED
				_delay_ms(200); // Delay for LED on period
				PORTD &= ~(1 << i); // Turn off the current LED
			}
		}
		else
		{
			PORTD = 0; // Turn off all LEDs
		}
	}
}


