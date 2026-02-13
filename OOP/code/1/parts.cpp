// структура для хранения информации о деталях изделий
#include <iostream>
using namespace std;

struct part
{
    int modelnumber; // номер модели изделия
    int partnumber; // номер детали
    float cost; // стоимость детали
};

int main(){
    part part1; // определение структурной переменной
    part1.modelnumber = 7429;
    part1.partnumber = 112;
    part1.cost = 377.21f;

    cout << "Модель " << part1.modelnumber << endl;
    cout << "Деталь " << part1.partnumber << endl;
    cout << "Стоимость $ " << part1.cost << endl;
}
