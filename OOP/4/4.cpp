#include <iostream>
#include <locale.h>

using namespace std;

const int jack = 11;	// валет
const int queen = 12;	// дама
const int king = 13;	// король
const int ace = 14;	// туз

enum Suit { clubs, diamonds, hearts, spades };	// масти карт - крести, бубны, черви, пики

struct card {
	int number;	// число карты
	Suit suit;	// масть карты
};

int main() {
	card temp, chosen, prize;	// определение карт
	int position;

	card card1 = { king, spades };
	cout << "Карта 1: король пик\n";

	card card2 = { 6, hearts };
	cout << "Карта 2: шестерка червей\n";

	card card3 = { 7, clubs };
	cout << "Карта 3: семерка крестей\n";

	prize = card1;	// запоминаем карту
	cout << "Меняем местами карту 1 и карту 2\n";
	temp = card2;
	card2 = card1;
	card1 = temp;

	cout << "Меняем местами карту 2 и карту 3\n";
	temp = card3;
	card3 = card2;
	card2 = temp;

	cout << "Меняем местами карту 1 и карту 3\n";
	temp = card3;
	card3 = card1;
	card1 = temp;

	cout << "На какой позиции (1,2 или 3) теперь король пик?" << endl;
	cin >> position;
	switch (position)
	{
		case 1:
			chosen = card1;
			break;
		case 2:
			chosen = card2;
			break;
		case 3:
			chosen = card3;
			break;
	}
	if (chosen.number == prize.number && chosen.suit == prize.suit) {
		cout << "Правильно! Вы выиграли!\n";
	}
	else {
		cout << "Неверно! Вы проиграли.\n";
	}
}
