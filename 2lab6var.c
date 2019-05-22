/*
 * 2lab6var.c
 *
 * Created: 22.05.2019 20:51:07
 * Author : nekit
 
 ���������� LED5, LED4 � LED3 �������� �������� � ������������� ������: �������,
 ������ � �������. �������� �������� �������������. ������� SW3 �����������
 ������ �� ���������� INT1, � ���������� ��������� �������� ���������� ���������
 ���������, � ������ SW2 ������������ ��� ������� ���������� INT0, � ����������
 ��������� �������� �������� ����������
 */ 


#define F_CPU 8000000UL 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



#define RED 0b11110111
#define YELLOW 0b11110111
#define GREEN 0b11101111

//DONT FORGET!!!
//INT0 = connect SW2 to PD2
//INT1 = connect SW3 to PD3

//on
ISR(INT1_vect)
{
	cli();
	if (PORTB == RED){
		_delay_ms(700);
		PORTB = YELLOW;
		_delay_ms(700);
		PORTB=GREEN;
	}
	sei();
}

//off
ISR(INT1_vect)
{
	cli();
	if (PORTB == GREEN){
		_delay_ms(700);
		PORTB = YELLOW;
		_delay_ms(700);
		PORTB=RED;
	}
	sei();
}

int main(void)
{
	DDRB = 0xFF;
	PORTD = 0xFF;
	EIMSK|=INT1|INT0;
	EICRA=0b00001010; //HL
	sei();
	PORTB = GREEN;
    
    while (1) 
    {
		
    }
}

