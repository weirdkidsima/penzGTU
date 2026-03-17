#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	void intfrac(float, float&, float&);	// прототип 

	float number, intpart, fracpart;
	do {
		cout << "\nВведите вещественное число: ";
		cin >> number;	// ввод числа пользователем
		intfrac(number, intpart, fracpart);	// нахождение целой и дробной части
		cout << "Целая часть равна " << intpart;	// вывод результатов
		cout << ", дробная часть равна " << fracpart;
		cout << endl;
	} while (number != 0.0);	// выход из цикла, если введен ноль

	return 0;
}

// функция intfrac() вычисляет целую и дробную часть вещественного числа
void intfrac(float n, float& intp, float& fracp) {
	long temp = static_cast<long>(n);	// преобразование к типу long
	intp = static_cast<float>(temp);	// и обратно во float
	fracp = n - intp;	// вычитаем целую часть
}