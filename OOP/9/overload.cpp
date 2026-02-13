// overload.cpp перегрузка функций
#include <iostream>
using namespace std;

void repchar(); // прототипы
void repchar(char);
void repchar(char, int);

int main()
{
    repchar();
    repchar('?');
    repchar('^', 15);
    return 0;
}

// функция repchar() выводит 45 символов '*'
void repchar()
{
    for(int i=0; i<45;i++)
        cout << '*';
        cout << endl;
}

// функция repchar() выводит 45 заданных символов
void repchar(char ch)
{
    for(int i=0; i<45;i++)
        cout << ch;
        cout << endl;
}

// функция repchar() выводит заданный символ заданное число раз
void repchar(char ch, int n)
{
    for(int i=0; i<n;i++)
        cout << ch;
        cout << endl;
}