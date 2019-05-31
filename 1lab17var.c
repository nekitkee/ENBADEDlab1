/*
 * 1lab17var.c
 *
 * Created: 21.05.2019 16:19:12

*/

#include <avr/io.h>

#define SW4 0b11101111
#define SW5 0b11011111
#define SW6 0b10111111

#define LED4 0b11101111
#define LED5 0b11011111
#define LED6 0b10111111

int main(void)
{
    DDRB = 0xFF ; 
	PORTB = LED5; 
	DDRD = 0x00; 
	PORTD = 0xFF ; 
    while (1) 
    {

			while (PIND == SW4 || PIND == SW5 ||PIND == SW6  ){
				PORTB=LED4&LED5; 
			}
		
		
			
			while(PIND == (SW4&SW5) || PIND==(SW4&SW6)  || PIND == (SW5&SW6) ){
				PORTB=LED6;	
			}
				PORTB=LED5;
		
		
		
    }
}



