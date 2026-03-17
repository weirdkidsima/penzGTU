#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;
    // длина в английской системе

public:
    // конструктор без аргументов
    Distance() : feet(0), inches(0.0)
    {}

    // конструктор с двумя аргументами
    Distance(int ft, float in) : feet(ft), inches(in)
    {}

    // ввод длины пользователем
    void getdist()
    {
        cout << "\nВведите число футов: ";
        cin >> feet;
        cout << "Введите число дюймов: ";
        cin >> inches;
    }

    // вывод длины на экран
    void showdist()
    {
        cout << feet << "'-" << inches << '"';
    }

    void add_dist(Distance, Distance); // прототип
};

void Distance::add_dist(Distance d2, Distance d3) // сложение длин d2 и d3
{
    inches = d2.inches + d3.inches; // сложение дюймов
    feet = 0; // с возможным заёмом
    if (inches >= 12.0) // если число дюймов больше 12.0
    {
        inches -= 12.0; // то уменьшаем число дюймов
        feet++; // на 12.0 и увеличиваем
    }                  // число футов на 1

    feet += d2.feet + d3.feet; // сложение футов
}

int main()
{
    Distance dist1, dist3; // две длины
    Distance dist2(11, 6.25); // определение и инициализация
    dist1.getdist(); // ввод dist1
    dist3.add_dist(dist1, dist2); // dist3 = dist1 + dist2

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
