#include <avr/interrupt.h>    // Defines pins, ports, etc to make programs easier to read
#define F_CPU 1000000UL	      // Sets up the default speed for delay.h
#include <util/delay.h>

void blinkEm( uint8_t count);

int main(){
	
	/* Initialize LED blinker (PD4)  */
	DDRD = _BV(PD4);		      // enable output on port D, pin 4
  
  while(1){
			blinkEm(1);
	}
}
/*------------------------------------------------------------------------
**  blinkEm - function to blink LED using PD4 for count passed in
** ---------------------------------------------------------------------*/
void blinkEm( uint8_t count){
	while (count > 0){
		PORTD = _BV(PD4); 
		_delay_ms(1000);

		PORTD = ~_BV(PD4);	
		_delay_ms(1000);
		count--;

	}
}
