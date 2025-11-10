#define F_CPU 16000000UL
#include <avr/io.h>

void delay_timer_3s74(void)
{
	// Настройка таймера
	TCCR1A = 0x00; // Нормальный режим
	TCCR1B = 0x00; // Остановить таймер, чтобы настроить
	TCNT1 = 65536 - 58438; // Загрузка начальноо значения (7098)
	TIFR1 |= (1 << TOV1); // Сброс флага переполнения
	TCCR1B |= (1 << CS12) | (1 << CS10); // Запуск таймера с делителем 1024
	
	// Ожидание переполнения
	while (!(TIFR1 & (1 << TOV1)));
	
	// Остановка таймера
	TCCR1B = 0x00;
}

int main(void)
{
	DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3); // PB1 - PB3 на выход
	
	while(1)
	{
		// LED1
		PORTB = (1 << PB1);
		delay_timer_3s74(); // 3.74 сек
		PORTB = 0;
		
		// LED2
		PORTB = (1 << PB2);
		delay_timer_3s74();
		PORTB = 0;
		
		// LED3
		PORTB = (1 << PB3);
		delay_timer_3s74();
		PORTB = 0;
	}
}