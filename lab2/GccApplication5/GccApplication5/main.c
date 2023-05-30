/*
 * GccApplication5.c
 *
 * Created: 5/30/2023 1:10:11 AM
 * Author : Asus
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#define LED_PIN_1 PD0
#define LED_PIN_2 PD2
#define LED_PIN_3 PD4
#define LED_PIN_4 PD6
#define BUTTON_PIN PB2
int main(void){
	DDRD |= (1<<LED_PIN_1) | (1<<LED_PIN_2) | (1<<LED_PIN_3) | (1<<LED_PIN_4); // Set LED_PINs (PD0, PD2, PD4, PD6) as outputs
	DDRB &= ~(1<<BUTTON_PIN); // Set BUTTON_PIN (PB2) as input
	PORTB |= (1<<BUTTON_PIN); // Enable pull-up resistor for BUTTON_PIN
	while (1) {
		if (!(PINB & (1<<BUTTON_PIN))) { // Check if the button is pressed
			PORTD ^= (1<<LED_PIN_1) | (1<<LED_PIN_2) | (1<<LED_PIN_3) | (1<<LED_PIN_4); // Toggle LED_PINs (PD0, PD2, PD4, PD6)
			_delay_ms(100); // Delay for debouncing
		}
	}
	return 0;
}

