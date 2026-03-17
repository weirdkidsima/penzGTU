#include <iostream>
using namespace std;

// Перечисление мастей карт
enum Suit { clubs, diamonds, hearts, spades };

// Именованные достоинства карт
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

// Класс карты
class card {
private:
    int number;      // достоинство карты
    Suit suit;       // масть

public:
    // Конструктор без аргументов
    card() {}

    // Конструктор с двумя аргументами
    card(int n, Suit s) : number(n), suit(s) {}

    // Вывод карты на экран
    void display();

    // Результат сравнения карт
    bool isEqual(card);
};

// Реализация метода display() — вывод карты на экран
void card::display() {
    if (number >= 2 && number <= 10) {
        cout << number;
    } else {
        switch (number) {
            case jack:   cout << "Валет "; break;
            case queen:  cout << "Дама ";   break;
            case king:   cout << "Король";  break;
            case ace:    cout << "Туз ";    break;
        }
    }

    // Вывод масти карты
    switch (suit) {
        case clubs:    cout << "треф"; break;
        case diamonds: cout << "бубей"; break;
        case hearts:   cout << "червей"; break;
        case spades:   cout << "пик";   break;
    }
}

// Реализация метода isEqual() — сравнение двух карт
bool card::isEqual(card c2) {
    return (number == c2.number && suit == c2.suit) ? true : false;
}

// Главная функция
int main() {
    card temp, chosen, prize;  // 3 карты
    int position;

    // Определение и инициализация card1
    card card1(7, clubs);
    cout << "\nКарта 1: ";
    card1.display();  // Вывод card1

    // Определение и инициализация card2
    card card2(jack, hearts);
    cout << "\nКарта 2: ";
    card2.display();  // Вывод card2

    // Определение и инициализация card3
    card card3(ace, spades);
    cout << "\nКарта 3: ";
    card3.display();  // Вывод card3

    prize = card3;  // Карту prize будет необходимо угадать

    // Перемешивание карт
    cout << "\nМеняем местами карты 1 и 3...";
    temp = card3; card3 = card1; card1 = temp;

    cout << "\nМеняем местами карты 2 и 3...";
    temp = card3; card3 = card2; card2 = temp;

    cout << "\nМеняем местами карты 1 и 2...";
    temp = card2; card2 = card1; card1 = temp;

    // Запрос позиции угадываемой карты
    cout << "\nНа какой позиции (1, 2 или 3) теперь ";
    prize.display();
    cout << "? ";
    cin >> position;

    // Выбор карты по позиции, указанной игроком
    switch (position) {
        case 1: chosen = card1; break;
        case 2: chosen = card2; break;
        case 3: chosen = card3; break;
    }

    // Сравнение выбранной карты с prize
    if (chosen.isEqual(prize)) {
        cout << "Правильно! Вы выиграли!";
    } else {
        cout << "Неверно. Вы проиграли.";
    }

    cout << "\nВы выбрали карту ";
    chosen.display();  // Вывод выбранной карты
    cout << endl;

    return 0;
}
