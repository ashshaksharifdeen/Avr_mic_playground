/*
 * GccApplication6_knightrider.c
 *
 * Created: 5/30/2023 2:58:52 AM
 * Author : Asus
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
 DDRD = 0xFF; // Set PORTD pins as output for LEDs
 DDRB &= ~(1 << DDB1); // Set PINB1 as input for the switch
 PORTB |= (1 << PINB1); // Enable the internal pull-up resistor for PINB1   
 while(1)
 {
	if ((PINB & (1 << PINB1)) == 0) // Check if switch is pressed
	{
	for (int i=1;i<=8;i++)
	{
		PORTD |=(1 << i);
		_delay_ms(500);
		PORTD &=~(1 << i);
		
		//PORTD &= ~(1 << pin) performs a bitwise AND operation between the current value of the PORTD register and the inverted value from step 2. This ensures that all other bits in the PORTD register remain unchanged, while the bit corresponding to the pin is set to 0.
		//Effectively, this code turns off the LED connected to the specific pin (pin) on Port D, while preserving the state of other pins.
		
	}
	for (int i=8;i>=0;i--)
	{
		PORTD |=(1 << i);
		_delay_ms(500);
		PORTD &=~(1 << i);
		
		//PORTD &= ~(1 << pin) performs a bitwise AND operation between the current value of the PORTD register and the inverted value from step 2. This ensures that all other bits in the PORTD register remain unchanged, while the bit corresponding to the pin is set to 0.
		//Effectively, this code turns off the LED connected to the specific pin (pin) on Port D, while preserving the state of other pins.
		
	}
	}
	else
	{
		PORTD=0;
	}
}
}

