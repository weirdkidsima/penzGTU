#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades }; // масти карт

// от 2 до 10 — обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card {
private:
    int number;   // достоинство карты (2–14)
    Suit suit;    // масть карты

public:
    card() {} // конструктор

    void set(int n, Suit s) { // установка значения
        number = n;
        suit = s;
    }

    void display(); // показ карты
};

// реализация метода display() — вывод карты на экран
void card::display() {
    if (number >= 2 && number <= 10) {
        cout << number; // для чисел 2–10 просто выводим число
    } else {
        switch (number) {
            case jack:  cout << 'J'; break; // Валет — J
            case queen: cout << 'Q'; break; // Дама — Q
            case king:  cout << 'K'; break; // Король — K
            case ace:   cout << 'A'; break; // Туз — A
        }
    }

    switch (suit) {
        case clubs:    cout << static_cast<char>(5); break; // символ треф
        case diamonds: cout << static_cast<char>(4); break; // символ бубен
        case hearts:   cout << static_cast<char>(3); break; // символ червей
        case spades:   cout << static_cast<char>(6); break; // символ пик
    }
}

int main() {
    card deck [52]; // массив из 52 карт (колода)
    int j;

    // создаём упорядоченную колоду карт
    for (j = 0; j < 52; j++) {
        int num = (j % 13) + 2;      // номер карты (2–14)
        Suit su = Suit(j / 13);       // масть карты (0–3)
        deck[j].set(num, su);         // заполняем колоду
    }

    // показываем исходную колоду
    cout << "Исходная колода:\n";
    for (j = 0; j < 52; j++) {
        deck[j].display(); // выводим карту
        cout << " ";       // разделитель между картами

        // начинаем новую строку после каждой 13-й карты (один ряд масти)
        if (!((j + 1) % 13)) {
            cout << endl;
        }
    }

    // инициализируем генератор случайных чисел
    srand(time(NULL));

    // перемешиваем колоду: меняем каждую карту на случайную
    for (j = 0; j < 52; j++) {
        int k = rand() % 52;           // выбираем случайную позицию
        card temp = deck[j];           // сохраняем текущую карту
        deck[j] = deck[k];             // заменяем текущую на случайную
        deck[k] = temp;                // помещаем текущую на случайную позицию
    }

    // показываем перемешанную колоду
    cout << "\nПеремешанная колода:\n";
    for (j = 0; j < 52; j++) {
        deck[j].display(); // выводим перемешанную карту
        cout << " ";       // разделитель между картами

        // начинаем новую строку после каждой 13-й карты
        if (!((j + 1) % 13)) {
            cout << endl;
        }
    }

    return 0;
}
