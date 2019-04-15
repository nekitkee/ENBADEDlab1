/*
 * Task2.c 
 * Var: 4
 * Created: 15.04.2019 13:57:42
 * Author : Nick Wynther
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define UCHAR_MAX 255

volatile unsigned char count = 0;
unsigned char r;

ISR(INT1_vect)
{
	while(!(PIND & (1 << 3)))
	{
		PORTB = count^0xFF;
	}
	count=0x00;
}



int main(void)
{
	//SETUP PORTS
	DDRB = 0xFF; //PB to output
	PORTB = 0xFF; // switch off diodes (switch on pull up resistor)
	//DDRD = 0x00; //PD to input
	PORTD = 0x08; // switch on pull up resistor for PD3 connected with (SW2)
	
	
	//SETUP INT1
	EIMSK = 0x02;
	//EICRA = 0x00; INTERRUPTION TYPE LOW
	sei();
	
    while (1) 
    {
		r = 0b00000001;	
		while (r!=0)
		{
			PORTB=r^0xFF;	
			//_delay_ms(500);
			r<<=1;
			if (count < UCHAR_MAX)
				count++;
		}
			
		
    }
}

