
/* BeepSwitch1 	09/01/08  */

/* This will read in switches and react to them */

/* Include useful pre-defined functions */
#include <avr/interrupt.h>    // Defines pins, ports, etc to make programs easier to read
#define F_CPU 1000000UL	      // Sets up the default speed for delay.h
#include <util/delay.h>

// Declare function prototypes


void blinkEm( uint8_t count);
void blinkEm3(void);

int main(){
	uint8_t but1, but1a, oldBut;
	
	/* Initialize Buttons - turn on pull-ups */
	PORTB = _BV(PB0) | _BV(PB1) ;
	oldBut = 0;	// force read first time
  
	/* Initialize LED blinker (PD4)  */
	DDRD = _BV(PD4);		      // enable output on port D, pin 4
  
    blinkEm(2);		// Blink as init signal
  
  while(1){
	/* --------------------------------------------------------------
	** Read switches. If they are changed, then flash quickly for new 
	**   count; otherwise just flash slowly.
	**--------------------------------------------------------------*/
	but1 = ~PINB & 0x03;	// look at two buttons, invert
	if (but1 != oldBut)		// beep when things change
	{
		_delay_ms(500);		// debounce - too long?
		but1a = ~PINB & 0x03;		// read again
		if (but1a == but1) 
		{
			blinkEm(but1a);
			oldBut = but1;
		}	
	}
	else					// if low
	{
		blinkEm3();
	}
  }

  return(0);
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

/*------------------------------------------------------------------------
**  blinkEm3 - function to slowly blink LED using PD4
** ---------------------------------------------------------------------*/
void blinkEm3(void){
	
	PORTD = _BV(PD4); 
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);

	PORTD = ~_BV(PD4);	
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);
		
}