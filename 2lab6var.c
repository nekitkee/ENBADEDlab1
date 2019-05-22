/*
 * 2lab6var.c
 *
 * Created: 22.05.2019 20:51:07
 * Author : nekit
 
 Светодиоды LED5, LED4 и LED3 образуют светофор и соответствуют цветам: красный,
 желтый и зеленый. Светофор работает автоматически. Кнопкой SW3 формируется
 запрос на прерывание INT1, в результате обработки которого происходит включения
 светофора, а кнопка SW2 используется для запроса прерывания INT0, в результате
 обработки которого светофор выключаетс
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

