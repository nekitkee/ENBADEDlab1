/*
 * 1lab16var.c
 *
 * Created: 03.05.2019 16:07:20
 * Author : nekit
 
 * Task   : 1 lab 16var
 
  if sw6 pressed run diodes from right to left
  is sw1 pressed reverse
 
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
	 DDRB = 0xFF; //port b to output (diodes)
	 DDRD = 0x00; //port d to input (switches)
	 PORTD = 0xFF; //pull up resistors for switches
    
	unsigned char mask = 0b00010000;  
	PORTB=~mask; //switch on middle diode
	
	/*
	0 - diode ON
	1 - diode OFF
	According to this, we have to invert our mask 
	
	Actually we use mask , because we cant make circular shift (>>) without lossing '1' values
	
	example:
	11110111 -- > = 011110111 (exactly what we don't need)
	
	*/
	
	
    while (1) 
    {
		
		//check switches
		
		//left to right direction
		
		if(!(PIND & (1 << 6))){ 
			//shift to right
			mask = mask >> 1;
			//if we reach the end , lets start from the beginning
			mask = mask == 0x00 ? 0b10000000 : mask;  
			

		}
			//reverse
		else if (!(PIND & (1 << 1))){
			mask = mask << 1; 
			mask = mask == 0x00 ? 0b00000001 : mask;
			
		}
		
		PORTB = ~mask;
		_delay_ms(200);
		
	}
		
		
		
		
    
}

