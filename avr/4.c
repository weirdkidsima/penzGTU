#include <avr/io.h>
#include <util/delay.h>

#define BUTTON PD2
#define DEBOUNCE_TIME 30

int main(void)
{
	// Настраиваем PB1, PB2, PB3 как выходы
	DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3);
	
	// Все светодиоды выключены при старте
	PORTB &= ~((1 << PB1) | (1 << PB2) | (1 << PB3));

	// Кнопка как вход с подтяжкой к VCC
	DDRD &= ~(1 << BUTTON);
	PORTD |= (1 << BUTTON);

	// Массив с пинами светодиодов
	const uint8_t leds[] = {PB1, PB2, PB3};
	uint8_t current_led = 0;
	uint8_t button_prev = 1;
	uint8_t button_event = 0; // Флаг, который считывает нажатие и отпускание

	while (1)
	{
		uint8_t button_now = (PIND & (1 << BUTTON)) ? 1 : 0;

		// Обнаружение нажатия (фронт 1 -> 0)
		if (button_prev == 1 && button_now == 0)
		{
			_delay_ms(DEBOUNCE_TIME);
			button_now = (PIND & (1 << BUTTON)) ? 1 : 0;
			
			if (button_now == 0) // Кнопка действительно нажата
			{
				// Ожидание отпускания
				while (!(PIND & (1 << BUTTON))) {}
				_delay_ms(DEBOUNCE_TIME);
				
				// Убеждаемся, что кнопка отпущена
				if ((PIND & (1 << BUTTON)))
				{
					// Регистрация события "нажатие и отпускание"
					button_event = 1;
				}
			}
		}
		
		// Обработка события "нажатие и отпускание"
		if (button_event)
		{
			// Выключаем все светодиоды
			PORTB &= ~((1 << PB1) | (1 << PB2) | (1 << PB3));
			
			// Включаем текущий светодиод
			PORTB |= (1 << leds[current_led]);
			
			// Переходим к следующему светодиоду
			current_led++;
			if (current_led > 2) current_led = 0;
			
			button_event = 0; // Сбрасываем флаг события
		}

		button_prev = button_now;
	}
}