#include <iostream>
#include <locale.h>

using namespace std;

struct Distance {
	int feet;	// длина в английской системе
	float inches;
};

Distance addengl(Distance, Distance);

void engldisp(Distance);

int main() {
	Distance d1, d2, d3;	// три структурные переменные

	cout << "\nВведите число футов: ";
	cin >> d1.feet;
	cout << "Введите число дюймов: ";
	cin >> d1.inches;
	// ввод значений полей d2
	cout << "Введите число футов: ";
	cin >> d2.feet;
	cout << "Введите число дюймов: ";
	cin >> d2.inches;

	d3 = addengl(d1, d2);	// d3 равно сумме d1 и d2

	cout << endl;
	engldisp(d1);
	cout << " + ";
	engldisp(d2);
	cout << " = ";
	engldisp(d3);
	cout << endl;

	return 0;
}

// функция engldisp(), отображающая значения полей структурной переменной типа Distance
Distance addengl(Distance dd1, Distance dd2) {
	Distance dd3;
	dd3.inches = dd1.inches + dd2.inches;
	dd3.feet = 0;

	if (dd3.inches >= 12.0) {
		dd3.inches -= 12.0;
		dd3.feet++;
	}
	dd3.feet += dd1.feet + dd2.feet;
	return dd3;
}

void engldisp(Distance dd) {
	cout << dd.feet << "\'-" << dd.inches << "\"";
}