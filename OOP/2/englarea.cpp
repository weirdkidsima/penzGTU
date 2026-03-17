// englarea.cpp использование вложенных структур
#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inches;
};

struct Room
{
    Distance length; // длина прямоугольника
    Distance width; // ширина прямоугольника
};

int main()
{
    Room dining;
    dining.length.feet = 5000;
    dining.length.inches = 150;
    dining.width.feet = 5500;
    dining.width.inches = 500;

    // преобразование длины и ширины в вещественный формат
    float l = dining.length.feet + dining.length.inches/12;
    float w = dining.width.feet + dining.width.inches/12;

    // вычисленеи площади комнаты и вывод на экран
    cout << "Площадь комнаты равна " << l * w << " квадратных футов\n";
    return 0;
}