#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	void order(int&, int&);	// прототип
	int n1 = 10, n2 = 5;	// неупорядоченная пара
	int n3 = 43, n4 = 85;	// упорядоченная пара

	order(n1, n2);	// упорядочивание
	order(n3, n4);	// обеих пар

	cout << "n1 = " << n1 << endl;	// вывод результатов
	cout << "n2 = " << n2 << endl;
	cout << "n3 = " << n3 << endl;
	cout << "n4 = " << n4 << endl;

	return 0;
}

void order(int& numb1, int& numb2) {	// упорядочивает два числа
	if (numb1 > numb2) {	// если первое число больше второго
		int temp = numb1;	// то меняем их местами
		numb1 = numb2;
		numb2 = temp;
	}
}