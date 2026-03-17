/*#include <iostream>
#include <cstring>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	char str1[] = "Зима близко";	// исходная строка
	const int MAX = 100;	// максимальная длина строки
	char str2[MAX];	// сама строка

	int len = strlen(str1);
	for (int j = 0; j < len; j++) {	// копируем strlen(str1)
		str2[j] = str1[j];	// символов из str1 в str2
	}
	str2[len] = '\0';	// завершаем строку нулем

	cout << str2 << endl;

	return 0;
}*/