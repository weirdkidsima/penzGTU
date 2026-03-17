#include <iostream>
#include <locale.h>

using namespace std;

void repchar();	// прототипы
void repchar(char);
void repchar(char, int);

int main()
{

	repchar();
	repchar('/');
	repchar('#', 777);

    return 0;
}

// функция repchar() выводит на экран 45 символов '*'
void repchar() {
	for (int j = 0; j < 15; j++) {	// цикл, выполняющийся 45 раз
		cout << '|';	// вывод символа '*'
	}
}

// функция repchar() выводит 45 заданных символов
void repchar(char ch) {
	for (int j = 0; j < 2048; j++) {	// цикл, выполняющийся 45 раз
		cout << ch;	// вывод заданного символа
	}
}

// функция repchar() выводит заданный символ заданное число раз
void repchar(char ch, int n) {
	for (int j = 0; j < n; j++) {
		cout << ch;
	}
}
