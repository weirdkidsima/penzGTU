#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int jack = 11;    // валет
const int queen = 12;   // дама
const int king = 13;    // король
const int ace = 14;     // туз

enum Suit { clubs, diamonds, hearts, spades }; // масти карт

struct card {
    int number;   // число карты
    Suit suit;    // масть карты
};

// Функция для получения названия масти
string suitToString(Suit s) {
    switch(s) {
        case clubs: return "треф";
        case diamonds: return "бубен";
        case hearts: return "червей";
        case spades: return "пик";
        default: return "";
    }
}

// Функция для получения названия карты
string cardToString(card c) {
    string result;
    
    // Определяем номинал
    switch(c.number) {
        case 11: result = "валет"; break;
        case 12: result = "дама"; break;
        case 13: result = "король"; break;
        case 14: result = "туз"; break;
        default: result = to_string(c.number); break;
    }
    
    // Добавляем масть
    result += " " + suitToString(c.suit);
    return result;
}

int main() {
    // Устанавливаем кодировку UTF-8 для консоли Windows
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    card temp, chosen, prize;
    int position;
    
    card card1 = { jack, clubs };
    cout << "Карта 1: " << cardToString(card1) << endl;
    
    card card2 = { queen, hearts };
    cout << "Карта 2: " << cardToString(card2) << endl;
    
    card card3 = { 8, diamonds };
    cout << "Карта 3: " << cardToString(card3) << endl;
    
    prize = card2;
    cout << "\nНачинаем перемешивание карт!\n";
    
    cout << "Меняем местами карту 2 и карту 3\n";
    temp = card3;
    card3 = card2;
    card2 = temp;
    
    cout << "Меняем местами карту 1 и карту 2\n";
    temp = card2;
    card2 = card1;
    card1 = temp;
    
    cout << "Меняем местами карту 1 и карту 3\n";
    temp = card3;
    card3 = card1;
    card1 = temp;
    
    cout << "\nНа какой позиции (1, 2 или 3) теперь находится " 
         << cardToString(prize) << "?" << endl;
    cin >> position;
    
    switch (position) {
        case 1: chosen = card1; break;
        case 2: chosen = card2; break;
        case 3: chosen = card3; break;
        default:
            cout << "Неверная позиция! Должно быть 1, 2 или 3.\n";
            return 1;
    }
    
    if (chosen.number == prize.number && chosen.suit == prize.suit) {
        cout << "Правильно! Вы выиграли!\n";
    } else {
        cout << "Неверно! Вы проиграли.\n";
    }
    
    return 0;
}