/*
 * 1lab17var.c
 *
 * Created: 21.05.2019 16:19:12
 * Author : nekit
 */ 

/*
Ïîñëå çàïóñêà ïðîãðàììû âêëþ÷åí ñâåòîäèîä LED5. Ïðè íàæàòèè îäíîé èç òðåõ
êíîïîê SW4 – SW6 âêëþ÷àåòñÿ äîïîëíèòåëüíî ê ñâåòîäèîäó LED5 ñâåòîäèîä LED4.
Ïðè íàæàòèè äâóõ èç òðåõ êíîïîê SW4 – SW6 ñâåòèò òîëüêî îäèí ñâåòîäèîä LED6.

*/

#include <avr/io.h>
#include <util/delay.h>

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
		if (PIND == SW4 || PIND == SW5 || PIND == SW6  ){ //no comment 
			PORTB=LED4&LED5;
                        _delay_ms(200); }
		if (PIND == SW4&SW5 || PIND == SW4&SW6 || PIND == SW5&SW6 ){
			PORTB=LED6;
                        _delay_ms(200);}	
		
		
    }
}

