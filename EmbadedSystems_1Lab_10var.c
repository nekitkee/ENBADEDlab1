/*
 * lab1var10.c
 *
 * Created: 26.04.2019 13:44:46
 * Author : nekit
 */ 



#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>

/*После нажатия на кнопку SW4 («Старт») последовательно с интервалом в 2 с
включаются светодиоды, начиная с LED0 и до LED7, а затем происходит их
выключение, в той же последовательности. После нажатия на кнопку SW3 («Стоп»)
выключаются все диоды и процесс включения останавливается.*/



int main(void)
{
	
    DDRB = 0xFF; 
    PORTB = 0xFF; 
    DDRD = 0x00; 
    PORTD = 0xFF;
	
	unsigned char r = 0; //mask
	unsigned char d = 0; //direction
	unsigned char w = 0; //workmode
	
    while (1) 
    {
		
		while(!(PIND & (1 << 4))) //sw4 start
		{
			// setup values
			d=1;
			w=1;
			r=0b00000001; 
			
			while (w==1) //sw3 is not pressed
			{
				if (d==1) 
					PORTB&=(~r); //switch on next diode
				else
					PORTB|= r; //switch off next diode
				
				_delay_ms(2000);
				
				r<<=1; //shift to next position
				
				if (r==0x00){ //if all diodes are ON or OFF
					d=d==1?0:1; //change direction
					r=0b00000001; //first diode position
				}
				
				if (!(PIND & (1 << 3))) //check SW3 
					w=0;//RESET
			}
		}
    }
}

