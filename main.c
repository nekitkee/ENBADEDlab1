/*
 * firstetst.c
 *
 * Created: 25.03.2019 14:31:42
 * Author : nekit
 */ 
/*
������������� ��������� LED6 ���������� � ����������� � �������� 0,5 �� (2 sek).
������ ������� �� ������ SW1 ����������� ������ ������������ ���������� �� 1
�, � ������ ������� �� ������ SW5 ��������� ������ ������������ ���������� ��
0,3 �. �������� ������� ������������ ���������� ����� ���������� �� 0,2 � �� 7 �.
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

