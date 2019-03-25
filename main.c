/*
 * firstetst.c
 *
 * Created: 25.03.2019 14:31:42
 * Author : nekit
 */ 
/*
Первоначально светодиод LED6 включается и выключается с частотой 0,5 Гц (2 sek).
Каждое нажатие на кнопку SW1 увеличивает период переключения светодиода на 1
с, а каждое нажатие на кнопку SW5 уменьшает период переключения светодиода на
0,3 с. Значение периода переключения светодиода может изменяться от 0,2 с до 7 с.
*/

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL

int main(void)
{
	
	DDRB = 0xFF; //port B to output
	PORTB = 0b10111111; // switch off diodes (switch on pull up resistors )
	DDRD = 0x00; //port D to input 
	PORTD = 0xFF; // switch on pull up resistors
	int pTime = 2000;

	while(1)
	{
		
		
		PORTB^=0b01000000; //switch on-off 6LED
		//_delay_ms(pTime)
		
		if (!(PIND & (1<<5)) && pTime >= 500 )
		pTime-=300;
		if (!(PIND & (1<<1)) && pTime <= 6000 )
		pTime+=1000;

	}
}

