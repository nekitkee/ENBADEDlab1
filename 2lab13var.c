/*
 * 2lab13var.c
 *
 * Created: 06.06.2019 15:30:11
 * Author : nekit
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SW0 0b11111110
#define SW1 0b11111101
#define SW2 0b11111011

volatile char mode=2;

ISR(PCINT0_vect) {
		
	
		
		
	if (PINB == SW1 ) 
		mode = 1; //off
	
	
	if (PINB == SW2)//on
		mode = 0;
		
	
        if(mode==1) 
			
	        PORTD = PORTD | (~(PINB));
	if(mode==0) 
			
		PORTD &= PINB;
			

_delay_ms(600);
}



int main(void)
{
	
	DDRB = 0x00;
	PORTB = 0xFF;

	DDRD = 0xFF;
	PORTD = 0x00;
		
	

	PCICR|=(1<<PCIE0);
	PCMSK0=0b11111111;
	
	
sei();


    while (1) 
    {
		
		
		
    }
}

