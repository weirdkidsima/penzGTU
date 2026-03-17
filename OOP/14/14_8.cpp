/*#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <locale.h>

using namespace std;

class String {
	private:
		enum { SZ = 0 };	// максимальный размер строки
		char str[SZ];	// сама строка
	public:
		String() {	// конструктор без параметров
			str[0] = '\0';
		}
		String(const char s[]) {	// конструктор с одним параметром
			strcpy(str, s);
		}
		void display() {
			cout << str;
		}
		void concat(String s2) {
			if (strlen(str) + strlen(s2.str) < SZ) {
				strcat(str, s2.str);
			}
			else {
				cout << "\nПереполнение!";
			}
		}
};

int main() {
	setlocale(LC_ALL, "ru");

	String s1("");	// конструктор с одним параметром
	String s2 = "";	// аналогично, но в другой форме
	String s3;	// конструктор без параметров

	cout << "\ns1 = ";
	s1.display();
	cout << "\ns2 = ";
	s2.display();
	cout << "\ns3 = ";
	s3.display();

	s3 = s1;	// присвоение
	cout << "\ns3 = ";
	s3.display();
	s3.concat(s2);	// сложение
	
	cout << "\ns3 = ";
	s3.display();

	cout << endl;

	return 0;
}*/