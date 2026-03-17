#include <iostream>
#include <locale.h>

using namespace std;

struct Distance {	// длина в английской системе
	int feet;	
	float inches;
};

void scale(Distance&, float);	// прототипы функций

void engldisp(Distance);

int main() {
	Distance d1 = { 1, 0.5 };	// инициализация d1 и d2
	Distance d2 = { 3, 12 };

	cout << "d1 = ";
	engldisp(d1);	// вывод исходных значений d1 и d2

	cout << "\nd2 = ";
	engldisp(d2);

	scale(d1, 0.5);
	scale(d2, 0.25);

	cout << "\nd1 = ";
	engldisp(d1);
	cout << "\nd2 = ";
	engldisp(d2);
	cout << endl;

	return 0;
}

void scale(Distance& dd, float factor) {
	float inches = (dd.feet * 12 + dd.inches) * factor;
	dd.feet = static_cast<int>(inches / 12);
	dd.inches = inches - dd.feet * 12;
}

void engldisp(Distance dd) {
	cout << dd.feet << "\'-" << dd.inches << "\"";
}