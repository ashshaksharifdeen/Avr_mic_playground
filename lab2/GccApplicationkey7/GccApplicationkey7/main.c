/*
 * GccApplicationkey7.c
 *
 * Created: 5/30/2023 3:25:03 AM
 * Author : Asus
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	
    while(1){
		if ((PINB & (1 << PINB1)) == 0)
		{
	    for (int i = 0, j = 7; i <= 3; i++, j--)
	    {
		    PORTD |= (1 << i) | (1 << j);
		    _delay_ms(500);
	    }

	    // Turn off LEDs from middle LEDs to both ends
	    for (int i = 3, j = 4; i >= 0; i--, j++)
	    {
		    PORTD &= ~((1 << i) | (1 << j));
		    _delay_ms(500);
	    }
		}
		else{
		  PORTD=0;
		}
    }
}

