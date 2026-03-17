// ecopycon.cpp // инициализация объектов с помощью копирующего конструктора
#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches; // длина в английской системе

public:
    Distance() : feet(0), inches(0.0) // конструктор без аргументов
    {}

    // конструктора с одним аргументом нет!
    // конструктор с двумя аргументами
    Distance(int ft, float in) : feet(ft), inches(in)
    {}

    void getdist() // ввод длины пользователем
    {
        cout << "\nВведите число футов: ";
        cin >> feet;
        cout << "Введите число дюймов: ";
        cin >> inches;
    }

    void showdist() // вывод длины
    {
        cout << feet << "'-" << inches << '"';
    }
};

int main()
{
    Distance dist1(0, 11.99); // конструктор с двумя аргументами
    Distance dist2(dist1);     // конструктор с одним аргументом (копирующий)
    Distance dist3 = dist1;    // конструктор с одним аргументом (копирующий)

    // вывод всех длин
    cout << "\ndist1 = ";
    dist1.showdist();
    cout << "\ndist2 = ";
    dist2.showdist();
    cout << "\ndist3 = ";
    dist3.showdist();
    cout << endl;

    return 0;
}
