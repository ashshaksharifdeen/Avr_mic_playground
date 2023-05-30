/*
 * GccApplication1.c
 *
 * Created: 5/22/2023 2:38:11 PM
 * Author : Asus
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL /*it works in 16Megahertz*/
#include <util/delay.h>

#define LED_PIN0 PD0
#define LED_PIN1 PD1
#define LED_PIN2 PD2
#define LED_PIN3 PD3
#define LED_PIN4 PD4
#define LED_PIN5 PD5
#define LED_PIN6 PD6
#define LED_PIN7 PD7



 


int main(void)
{
    /* Replace with your application code */
	DDRD |=(1 << LED_PIN0); //set this output for the register DDRD or we can write like this DDRB |=00000001 
	//PORTD |=(1 << LED_PIN0); //make the Port D PIN0 as High or can write 00000001
	//b. blink led of PD0
    /*while (1) 
    {
		PORTD ^=(1 << LED_PIN0);
		
		//In the infinite while loop, PORTD ^= (1 << LED_PIN) toggles the state of the PD0 pin using the XOR operator (^). It will turn the LED on if it was off, and turn it off if it was on.
		//when system is off while in delay led blink while the system is on on delay it will off led.
		//_delay_ms(100);
		//PORTD |=~(1 << LED_PIN0) ;
		
    }*/
	//c.blink only even numbered
	/*while(1)
	{
		PORTD ^=(1 << LED_PIN2);
		PORTD ^=(1 << LED_PIN4);
		PORTD ^=(1 << LED_PIN6);
		_delay_ms(500);
		
	}*/
	//d.blink only odd numbered
	/*while(1)
	{
		PORTD ^=(1 << LED_PIN1);
		PORTD ^=(1 << LED_PIN3);
		PORTD ^=(1 << LED_PIN5);
		PORTD ^=(1 << LED_PIN7);
		_delay_ms(500);
	}*/
	//Blink LEDs one after another from PD0 to PD7
	/*
	while(1)
	{
	for (int i=1;i<=8;i++)
	{
		PORTD |=(1 << i);
		_delay_ms(500);
		PORTD &=~(1 << i);
		
		//PORTD &= ~(1 << pin) performs a bitwise AND operation between the current value of the PORTD register and the inverted value from step 2. This ensures that all other bits in the PORTD register remain unchanged, while the bit corresponding to the pin is set to 0.
		//Effectively, this code turns off the LED connected to the specific pin (pin) on Port D, while preserving the state of other pins.
		
	//}
	//}*/
	//Knight Rider Pattern
	/*while(1)
	{
	for (int i=1;i<=8;i++)
	{
		PORTD |=(1 << i);
		_delay_ms(500);
		PORTD &=~(1 << i);
		
		//PORTD &= ~(1 << pin) performs a bitwise AND operation between the current value of the PORTD register and the inverted value from step 2. This ensures that all other bits in the PORTD register remain unchanged, while the bit corresponding to the pin is set to 0.
		//Effectively, this code turns off the LED connected to the specific pin (pin) on Port D, while preserving the state of other pins.
		
	}
	for (int i=8;i>0;i--)
	{
		PORTD |=(1 << i);
		_delay_ms(500);
		PORTD &=~(1 << i);
		
		//PORTD &= ~(1 << pin) performs a bitwise AND operation between the current value of the PORTD register and the inverted value from step 2. This ensures that all other bits in the PORTD register remain unchanged, while the bit corresponding to the pin is set to 0.
		//Effectively, this code turns off the LED connected to the specific pin (pin) on Port D, while preserving the state of other pins.
		
	}
	}*/
	//Blink LEDs starting from the left most and the rightmost LED (PD0 and PD7) to middle 2 LEDs (PD3 and PD4)
	/*while(1)
	{
		// Turn on LED_PIN0 and LED_PIN7 LEDs
		PORTD |= (1 << LED_PIN0) | (1 << LED_PIN7);
		_delay_ms(500);

		// Turn off PD0 and PD7 LEDs
		PORTD &= ~((1 << LED_PIN0) | (1 << LED_PIN7));
		_delay_ms(500);

		// Turn on PD1 and PD6 LEDs
		PORTD |= (1 << LED_PIN1) | (1 << LED_PIN6);
		_delay_ms(500);

		// Turn off PD1 and PD6 LEDs
		PORTD &= ~((1 << LED_PIN1) | (1 << LED_PIN6));
		_delay_ms(500);
		
		// Turn on PD2 and PD5 LEDs
		PORTD |= (1 << LED_PIN2) | (1 << LED_PIN5);
		_delay_ms(500);

		// Turn off PD2 and PD5 LEDs
		PORTD &= ~((1 << LED_PIN2) | (1 << LED_PIN5));
		_delay_ms(500);
		
		// Turn on PD3 and PD4 LEDs
		PORTD |= (1 << LED_PIN3) | (1 << LED_PIN4);
		_delay_ms(500);

		// Turn off PD3 and PD4 LEDs
		PORTD &= ~((1 << LED_PIN3) | (1 << LED_PIN4));
		_delay_ms(500);
	}*/
	
	//Turn ON LEDs starting from PD0 to PD7 and turn OFF them one by one from PD7 to PD0 once all the LEDs are turned ON
	
	/*
	while(1)
	{
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
	}*/
    //Turn ON LEDs starting from both the ends (PD0 and PD7) to both middle LEDs (PD3 and
    //PD4) and turn them OFF starting from two middle LEDs to LEDs in the both ends.
	// Turn on LEDs from both ends to middle LEDs
	while(1){
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
	return 0;
	
}

