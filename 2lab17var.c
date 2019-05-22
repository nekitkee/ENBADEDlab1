/*
 * 2lab17var.c
 *
 * Created: 22.05.2019 18:52:17
 * Author : nekit
 */ 


/*
 Светодиоды подключены к порту D. Кнопки не используются. Светодиоды загораются
 по очереди, создавая эффект бегущих огней слева направо. 
 
 После каждых 5 повторений
 вызывается запрос на прерывание PCINT0, путем подачи значения 0х10 на линии ввода
 порта В. В обработчике на прерывание PCINT0 необходимо запрограммировать
 отображение числа повторений бегущих огней в течение 6 секунд.
 */

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define FIRE_DELAY 100
#define STOP_DELAY 6000
#define CYCLE_COUNT 5

ISR (PCINT0_vect)
{
	
	PORTB = 0x00;
	
	PORTD = ~CYCLE_COUNT;
	_delay_ms(STOP_DELAY);
	

	
}


int main(void)
{
	DDRD = 0xFF;
	PORTD = 0xFF;
	
	DDRB = 0x00;
	PORTB = 0x00;
	
	
    PCICR |= (1<<PCIE0);
    PCMSK0 |= (1<<PCINT4);
    sei();
	
    while (1) 
    {
		
		for (char cycle = 0 ; cycle < CYCLE_COUNT ; cycle++  ){
			char fire = 0b10000000;
			for (char i = 0 ; i < 8; i++){
				PORTD=~fire;
				_delay_ms(FIRE_DELAY);
				fire >>=1;
			}
		}
		PORTB = 0x10;
	
		
	}
}

