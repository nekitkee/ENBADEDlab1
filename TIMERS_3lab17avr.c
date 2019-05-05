/*
 * lab3var17.c
 *
 * Created: 03.05.2019 9:09:32
 * Author : nekit
 */ 

/*Таймер Т0 работает в режиме счетчика внешних событий. Событие – нажатие на
кнопку SW0, подключенную к линии РВ0. С помощью таймера Т1 и светодиодов
обеспечить индикацию в двоичном коде количества нажатий на SW0 за последние 5 с*/

//T0 - 8bitb pd4
//T1 - 16BIT CONUTER pd5
//T2 - 8bit


#include <avr/io.h>
#include <avr/interrupt.h>



void my_delay_30ms(void)
{
	TCNT2=0;
	while (TCNT2 < 255)
	{}
}


ISR (PCINT0_vect)
{
	if (!(PINB & 1))
	{
		//when sw0 pressed 
		cli();

		//PORTD &= ~(1<<4);
		//PORTD |= (1<<4);
		TCNT0++;
		
		my_delay_30ms();
		my_delay_30ms();
		sei();
	}
	
	
}

/*
PC[0]   = LED[0]
PB[1~7] = LED[1~7]
*/

ISR(TIMER1_OVF_vect){
	
	cli();
	PORTB=~TCNT0;
	PORTC=~TCNT0;
	sei();
	TCNT0 = 0x00;
	TCNT1 = 0x676A;
}


int main(void)
{
	/*
	PORTB - 0 pin button , 1-7 pins for led[1-7] 
	PORTC - led[0]
	PORTD - INPUT FOR TIMERS 
	*/
	
	
	
	
	DDRD  = 0xFF;
	PORTD = 0xFF;
	DDRB  = 0xFE;
	PORTB = 0xFF;
	DDRC |= 0x01;
	PORTC|= 0x01;
	
	
	TCCR0B = 0x06; //count SW HL
	TCCR1B = 0x05; // 5sec timer f/1024
	TCCR2B = 0x07; // my_delay f/1024
	
	TIMSK1 = 0x01; //enable 5sec timer overflow interrupt 
	
	//T=1024/8kk=0.000128 sec
	//5sec = 39062,5T
	
	TCNT1 = 0x676A; //started value = 65536 - 39065 ;
	TCNT0 = 0x00;
	
	//enable PCINT0 (starts when sw0 pressed)
	PCICR |= (1<<PCIE0);
	PCMSK0 |= (1<<PCINT0);
	sei();
	
	
	
    while (1) 
    {}
}

