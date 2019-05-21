/*
 * 1lab17var.c
 *
 * Created: 21.05.2019 16:19:12
 * Author : nekit
 */ 

/*
После запуска программы включен светодиод LED5. При нажатии одной из трех
кнопок SW4 – SW6 включается дополнительно к светодиоду LED5 светодиод LED4.
При нажатии двух из трех кнопок SW4 – SW6 светит только один светодиод LED6.

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
    DDRB = 0xFF ; //port B to output ;
	PORTB = LED5; // switch on LED5
	DDRD = 0x00; //port D to input (SW)
	PORTD = 0xFF ; //pull up resistors
    while (1) 
    {
		if (PIND == SW4 || PIND == SW5 || PIND == SW6  ) //no comment 
			PORTB=LED4&LED5; 
		if (PIND == SW4&SW5 || SW4&SW6 || SW5&SW6 )
			PORTB=LED6;	
		
		
    }
}

