#include <iostream>
#include <locale.h>

using namespace std;

class smallobj
{
    private:
        int somedata;   // поле класса
    public:
        void setdata(int d) {   // метод класса, изменяющий значения поля
            somedata = d;
        }
        void showdata() {   // метод класса, отображающий значение поля
            cout << "Значения поля равно " << somedata << endl;
        }
};

int main()
{
    smallobj s1, s2;    // определение двух объектов класса smallobj

    // вызовы метода setdata()
    s1.setdata(9999999);
    s2.setdata(2305567);

    // вызовы метода showdata()
    s1.showdata();
    s2.showdata();
    return 0;
}
