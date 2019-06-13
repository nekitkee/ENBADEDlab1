/*
 * 2lab6var.c
 *
 * Created: 22.05.2019 20:51:07
 * Author : nekit
 
 Ñâåòîäèîäû LED5, LED4 è LED3 îáðàçóþò ñâåòîôîð è ñîîòâåòñòâóþò öâåòàì: êðàñíûé,
 æåëòûé è çåëåíûé. Ñâåòîôîð ðàáîòàåò àâòîìàòè÷åñêè. Êíîïêîé SW3 ôîðìèðóåòñÿ
 çàïðîñ íà ïðåðûâàíèå INT1, â ðåçóëüòàòå îáðàáîòêè êîòîðîãî ïðîèñõîäèò âêëþ÷åíèÿ
 ñâåòîôîðà, à êíîïêà SW2 èñïîëüçóåòñÿ äëÿ çàïðîñà ïðåðûâàíèÿ INT0, â ðåçóëüòàòå
 îáðàáîòêè êîòîðîãî ñâåòîôîð âûêëþ÷àåòñ
 */ 


#define F_CPU 8000000UL 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



#define RED 0b11110111
#define YELLOW 0b11101111
#define GREEN 0b11011111

volatile char  work_mode = 1;

//DONT FORGET!!!
//INT0 = connect SW2 to PD2
//INT1 = connect SW3 to PD3

//on
ISR(INT1_vect)
{
	work_mode = 1
}

//off
ISR(INT1_vect)
{
	work_mode= 0;
	PORTB = 0xFF;
}


int main(void)
{
	DDRB = 0xFF;
	PORTD = 0xFF;
	EIMSK|=INT1|INT0;
	EICRA=0b00001010; //HL
	sei();
    
    while (1) 
    {
		if (work_mode)
			{PORTB = GREEN ; _delay_ms(5000); }
		if (work_mode)
			{PORTB = YELLOW ; _delay_ms(400);} 
		if (work_mode)
			{PORTB = RED ; _delay_ms(2000);}
		if (work_mode)
			{PORTB = YELLOW ; _delay_ms(400);}
    }
}

