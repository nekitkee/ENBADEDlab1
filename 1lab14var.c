/*
 * lab1var14.c
 *
 * Created: 15.05.2019 10:06:06
 * Author : nekit
 */ 

/*
Трехразрядная кодовая комбинация вводится с помощью кнопок SW1 – SW6 и
подтверждается нажатием на кнопку SW0. Если код верный, то включается
светодиод LED0. При трех неверных попытках ввод код блокируется и включается
светодиод LED7. Выключение светодиодов при верном коде происходит через 5 с.
Набор кодовой комбинации производится в произвольной последовательности.
*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


#define bincode 0b00110010 //145

int main(void)
{
    DDRB = 0xFF; //output for diodes
	PORTB = 0xFF;
	DDRD = 0x00; //input for switches
	PORTD = 0xFF; //pull-up resistors
	unsigned char attempts = 3;
	unsigned char buffer = 0;
    while (attempts) 
    {
		//read pressed buttons(from 1 to 7) and write to BUFFER if pressed
		for (unsigned char i = 1 ; i < 8 ; i++){
			if (!(PIND & (1 << i))){
				buffer|= (1<<i);
			}
		}
		
		
		if (!(PIND & (1 << 0)))//sw0 pressed
		{
					//input correct
					if (buffer==bincode){ 
						
						PORTB=0xFE;  // switch on LED0
						_delay_ms(5000);
						PORTB=0xFF; //switch off LED0 
						buffer=0;
						attempts=3; 
					}
					//incorrect
					else {
						
						_delay_ms(500); //kill noise from button
						attempts--; 
						buffer=0;
					}
						
		}
		
	
	}
	//out off 3 attempts
	//LED7
	PORTB = 0x7F;
	
}

