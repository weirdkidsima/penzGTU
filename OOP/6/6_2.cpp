#include <iostream>
#include <locale.h>

using namespace std;

void repchar(char, int);	// прототип функции

int main() {
	char chin;	// символ для повторений
	int nin;	// число повторений символов

	cout << "Введите символ: " << endl;
	cin >> chin;
	cout << "Введите число повторенй символа: " << endl;
	cin >> nin;

	repchar(chin, nin);	// вызов функции
	return 0;
}

void repchar(char ch, int n) {
	for (int j = 0; j < n; j++) {
		cout << ch;
	}
	cout << endl;
}