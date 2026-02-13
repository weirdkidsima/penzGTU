// englstrc.cpp английская система мер, реализованная с помощью структуры
#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inches;
};

int main()
{
    Distance d1, d3; // определение двух переменных
    Distance d2 = {12, 8.24}; // опр. и инициализация

    // ввод полей d1
    cout << "\n Введите число футов: ";
    cin >> d1.feet;
    cout << "Введите число дюймов: ";
    cin >> d1.inches;

    // сложение d1 и d2, присвоение d3
    d3.inches = d1.inches + d2.inches;
    d3.feet = 0;
    if (d3.inches >= 12.0)
    {
        d3.inches -= 12.0;
        d3.feet++;
    }
    d3.feet += d1.feet + d2.feet;

    cout << d1.feet << "\'-" << d1.inches << "\" + ";
    cout << d2.feet << "\'-" << d2.inches << "\" = ";
    cout << d3.feet << "\'-" << d3.inches << "\"\n";
    return 0;
    
}