// factor2.cpp подсчет факториала числа с помощью рекурсии
#include <iostream>
using namespace std;
unsigned long factfunc(unsigned long); // прототип

int main()
{
    int n; // число от пользователя
    unsigned long fact; // факториал
    cout << "Введите целое число: ";
    cin >> n;
    fact = factfunc(n);
    cout << "Факториал числа " << n << "равен " << fact << endl;
    return 0;
}

unsigned long factfunc(unsigned long n)
{
    if (n > 1)
        return n * factfunc(n - 1);
    else
        return 1;
}