#include <iostream>
#include <locale.h>

using namespace std;

struct Distance {
	int feet;	// длина в английской системе
	float inches;
};

void engldisp(Distance);

int main() {
	Distance d1, d2;

	cout << "Введите число футов: ";
	cin >> d1.feet;
	cout << "Введите число дюймов: ";
	cin >> d1.inches;
	// ввод значений полей d2
	cout << "Введите число футов: ";
	cin >> d2.feet;
	cout << "Введите число дюймов: ";
	cin >> d2.inches;
	
	cout << "\nd1 = ";
	engldisp(d1);	// вывод значения d1
	cout << "\nd2 = ";
	engldisp(d2);	// вывод значения d2
	cout << endl;

	return 0;
}

// функция engldisp(), отображающая значения полей структурной переменной типа Distance
void engldisp(Distance dd) {	// параметр dd типа Distance
	cout << dd.feet << "\'-" << dd.inches << "\"";
}