#include <iostream>
#include <locale.h>

using namespace std;

void repchar(char, int);	// прототип функции

int main() {
	repchar('*', 0);
	cout << "Тип данных Диапазон" << endl;
	repchar('*', 0);
	
	cout << "char	-128...127" << endl;
	cout << "short	-32,768...32,767" << endl;
	cout << "int	Системно-зависимый" << endl;
	cout << "double	-2,147,483,648...2,147,483,647" << endl;

	repchar('*', 0);
	return 0;
}

void repchar(char ch, int n) {
	for (int j = 0; j < n; j++) {
		cout << ch;
	}
	cout << endl;
}