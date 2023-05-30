/*
 * GccApplication6cometomidel.c
 *
 * Created: 5/30/2023 3:08:28 AM
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
    /* Replace with your application code */
    while(1)
    {
		if((PINB & (1 << PINB1)) == 0){
	    // Turn on LED_PIN0 and LED_PIN7 LEDs
	    PORTD |= (1 << PIND0) | (1 << PIND7);
	    _delay_ms(500);

	    // Turn off PD0 and PD7 LEDs
	    PORTD &= ~((1 << PIND0) | (1 << PIND7));
	    _delay_ms(500);

	    // Turn on PD1 and PD6 LEDs
	    PORTD |= (1 << PIND1) | (1 << PIND6);
	    _delay_ms(500);

	    // Turn off PD1 and PD6 LEDs
	    PORTD &= ~((1 << PIND1) | (1 << PIND6));
	    _delay_ms(500);
	    
	    // Turn on PD2 and PD5 LEDs
	    PORTD |= (1 << PIND2) | (1 << PIND5);
	    _delay_ms(500);

	    // Turn off PD2 and PD5 LEDs
	    PORTD &= ~((1 << PIND2) | (1 << PIND5));
	    _delay_ms(500);
	    
	    // Turn on PD3 and PD4 LEDs
	    PORTD |= (1 << PIND3) | (1 << PIND4);
	    _delay_ms(500);

	    // Turn off PD3 and PD4 LEDs
	    PORTD &= ~((1 << PIND3) | (1 << PIND4));
	    _delay_ms(500);
		}
		else{
			PORTD=0;
		}
	
	}
}

