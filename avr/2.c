#define F_CPU 16000000UL  // частота тактирования 16 МГц
#include <avr/io.h>
#include <util/delay.h>   // библиотека для программных задержек

#define DELAY_TIME 3.74

int main(void)
{
	// Настройка портов (PB1, PB2, PB3 — на выход)
	DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3);

	while (1)
	{
		// Светодиод 1
		PORTB |=  (1 << PB1);
		PORTB &= ~((1 << PB2) | (1 << PB3));
		_delay_ms(DELAY_TIME * 1000);  // 3.74 сек
		PORTB &= ~(1 << PB1);

		// Светодиод 2
		PORTB |=  (1 << PB2);
		PORTB &= ~((1 << PB1) | (1 << PB3));
		_delay_ms(DELAY_TIME * 1000);
		PORTB &= ~(1 << PB2);

		// Светодиод 3
		PORTB |=  (1 << PB3);
		PORTB &= ~((1 << PB1) | (1 << PB2));
		_delay_ms(DELAY_TIME * 1000);
		PORTB &= ~(1 << PB3);
	}
}


