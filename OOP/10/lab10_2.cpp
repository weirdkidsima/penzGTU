#include <iostream>
#include <locale.h>

using namespace std;

class part                
{
    private:
        int modelnumber;   // номер изделия
        int partnumber; // номер детали
        float cost; // стоимость детали
    public: // установка данных
        void setpart(int mn, int pn, float c) {   // метод класса, изменяющий значения поля
            modelnumber = mn;
            partnumber = pn;
            cost = c;
        }
        void showpart() {   // вывод данных
            cout << "Модель " << modelnumber;
            cout << ", деталь " << partnumber;
            cout << ", стоимость $" << cost;
        }
};

int main()
{
    part part1;
    part1.setpart(-102211, -102211, -102211);
    part1.showpart();

    return 0;
}
