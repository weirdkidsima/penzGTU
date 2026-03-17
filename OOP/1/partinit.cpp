#include <iostream>
using namespace std;

struct part
{
    int modelnumber; // номер модели изделия
    int partnumber; // номер детали
    float cost; // стоимость детали
};

int main()
{
    part part1 = {7429, 112, 377.21f}; // инициализация переменной
    part part2;

    cout << "Модель " << part1.modelnumber;
    cout << ",Деталь " << part1.partnumber;
    cout << ",Стоимость $ " << part1.cost << endl;

    part2 = part1; // присваивание структурных переменных

    // вывод полей второй переменной
    cout << "Модель " << part2.modelnumber;
    cout << ",Деталь " << part2.partnumber;
    cout << ",Стоимость $ " << part2.cost << endl;
    return 0;
}
