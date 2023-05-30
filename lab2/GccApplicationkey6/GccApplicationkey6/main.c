/*
 * GccApplicationkey6.c
 *
 * Created: 5/30/2023 3:19:08 AM
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
	  if ((PINB & (1 << PINB1)) == 0){
	  for (int i = 0; i < 8; i++)
	  {
		  PORTD |= (1 << i);
		  _delay_ms(500);
	  }

	  // Turn off LEDs from PD7 to PD0
	  for (int i = 7; i >= 0; i--)
	  {
		  PORTD &= ~(1 << i);
		  _delay_ms(500);
	  }
	  }
	  else{
	   PORTD=0;
	  }
  }
}

