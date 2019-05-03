/*
 * 1lab16var.c
 *
 * Created: 03.05.2019 16:07:20
 * Author : nekit
 
 * Task   : При нажатой кнопке SW6 светодиоды включаются по очереди, создавая эффект
 бегущих огней слева направо, а при нажатой кнопке SW1 включение светодиодов
 происходит в противоположном направлении.
 
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
	 DDRB = 0xFF; //port b to output (diodes)
	 DDRD = 0x00; //port d to input (switches)
	 PORTD = 0xFF; //pull up resistors for swicthes
    
	unsigned char mask = 0b00010000;  
	PORTB=~mask; //seitch on midle diode
	
	/*
	0 - diode ON
	1 - diode OFF
	According to this, we have to invert our mask 
	
	Actually we use mask , because we cant make circular shift (побитовый сдвиг) without lossing '1' values
	
	example:
	11110111 -- > = 011110111 (exactly what we don't need)
	
	*/
	
	
    while (1) 
    {
		
		//check switches
		
		//left to right direction
		if(!(PIND & (1 << 6))){ 
			mask = mask >> 1;
			//if we reach the end , lets start from the begining
			mask = mask == 0x00 ? 0b10000000 : mask;  
			

		}
			//same
		else if (!(PIND & (1 << 1))){
			mask = mask << 1;
			mask = mask == 0x00 ? 0b00000001 : mask;
			
		}
		
		PORTB = ~mask;
		_delay_ms(200);
		
	}
		
		
		
		
    
}

