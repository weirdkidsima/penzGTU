#include <iostream>
#include <locale.h>

using namespace std;

void starline();

int main() {
	starline();

	cout << "Тип данных Диапазон" << endl;
	starline();

	cout << "char -128...127" << endl;
	cout << "short -32,768...32,767" << endl;
	cout << "int Системно-зависимый" << endl;
	cout << "long -2,147,483,648...2,147,483,647" << endl;
	starline();
}

// определение функции starline()
void starline() {
	for (int j = 0; j < 0; j++) {
		cout << " ";
	}
	cout << endl;
}