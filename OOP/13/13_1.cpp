#include <iostream>
using namespace std;

//////////////////////////////////////////////////
class Distance  // длина в английской системе
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0)  // конструктор без аргументов
    { }

    Distance(int ft, float in) : feet(ft), inches(in)  // конструктор с двумя аргументами
    { }

    void getdist()  // ввод длины
    {
        cout << "\nВведите число футов: ";
        cin >> feet;
        cout << "Введите число дюймов: ";
        cin >> inches;
    }

    void showdist()  // вывод длины
    {
        cout << feet << "'-" << inches << '"';
    }

    Distance add_dist(Distance);  // сложение
};

// сложение данного объекта с d2, возврат суммы
Distance Distance::add_dist(Distance d2)
{
    Distance temp;  // временная переменная
    temp.inches = inches + d2.inches;  // сложение дюймов
    if (temp.inches >= 12.0)  // если сумма больше 12.0
    {
        temp.inches -= 12.0;  // то уменьшаем её на 12.0
        temp.feet = 1;  // и увеличиваем число футов на 1
    }
    temp.feet += feet + d2.feet;  // сложение футов
    return temp;
}

//////////////////////////////////////////////////
int main()
{
    Distance dist1, dist3;  // две длины
    Distance dist2(11, 6.25);  // определение и инициализация dist2
    dist1.getdist();  // ввод dist1 пользователем
    dist3 = dist1.add_dist(dist2);  // dist3 = dist1 + dist2

    // вывод всех длин
    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << "\ndist3 = "; dist3.showdist();
    cout << endl;
    return 0;
}
