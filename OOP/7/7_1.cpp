#include <iostream>
#include <locale.h>

using namespace std;

float lbstokg(float);	// прототип функции

int main() {
	float lbs, kgs;
	cout << "\nВведите вес в фунтах: ";
	cin >> lbs;
	kgs = lbstokg(lbs);
	cout << "Вес в килограммах равен " << kgs << endl;

	return 0;
}

// функция engldisp(), отображающая значения полей структурной переменной типа Distance
float lbstokg(float pounds) {
	float kilograms = 0.453592 * pounds;
	return kilograms;
}