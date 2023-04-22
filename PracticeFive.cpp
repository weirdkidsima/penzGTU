#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#define KOL 4
using namespace std;
class MOTOR {
	struct HORSEPOWER {
		int horsepower;
	};
	struct Motor {
		char firm[20]; char number[20]; char vid[20]; HORSEPOWER r;
	} h[KOL];
public:
	void input();
	void output();
	void choose();
	void order();
};

void MOTOR::input() {
	system("cls");
	cout << "Введите данные: " << endl;
	for (int i = 0; i < KOL; i++) {
		cout << "Фирма:->"; cin >> h[i].firm;
		cout << "Номер:->"; cin >> h[i].number;
		cout << "Виж:->"; cin >> h[i].vid;
		cout << "Лошадиные силы:->"; cin >> h[i].r.horsepower;
	}system("cls");
}

void MOTOR::output() {
	system("cls");
	cout << "-------------------------------------------------------------------------------\n";
	cout << "Фирма" << "|| " << setw(10) << "  " << setw(10) << "Номер" << "    || " << setw(15) << "Вид" << "     || " << setw(10) << "Лошадиные силы|\n";
	for (int i = 0; i < KOL; i++)
		cout << "|" << h[i].firm << "     || " << setw(10) << "  " << setw(10) << h[i].number << "    || " << setw(15) << h[i].vid << "     || " << setw(6) << h[i].r.horsepower << "  |" << "\n";
	system("pause");
}

void MOTOR::choose()
{
	system("cls");
	cout << "-------------------------------------------------------------------------------\n";
	cout << "|Фирма" << "|| " << setw(10) << "  " << setw(10) << "Номер" << "    || " << setw(15) << "Виж" << "     || " << setw(10) << "Лошадиные силы| \n";
	for (int i = 0; i < KOL; i++)
		if (h[i].r.horsepower == 46)
			cout << "|" << h[i].firm << "     || " << setw(10) << "  " << setw(10) << h[i].number << "    || " << setw(15) << h[i].vid << "     || " << setw(6) << h[i].r.horsepower << "  |" << "\n";
	system("pause");
}

void MOTOR::order() {
	Motor x; int i, j;
	system("cls");
	cout << "-------------------------------------------------------------------------------\n";
	cout << "|Фирма" << "|| " << setw(10) << "  " << setw(10) << "Номер" << "    || " << setw(15) << "Вид" << "     || " << setw(10) << "Лошадиные силы|\n";
	for (i = 0; i < KOL - 1; i++)
		for (j = 0; j < KOL - 1; j++)
			if (h[j].r.horsepower < h[j + 1].r.horsepower)
			{
				x = h[j]; h[j] = h[j + 1]; h[j + 1] = x;
			}
	for (i = 0; i < KOL; i++)
		cout << "|" << h[i].firm << "     || " << setw(10) << "  " << setw(10) << h[i].number << "    || " << setw(15) << h[i].vid << "     || " << setw(6) << h[i].r.horsepower << "  |" << "\n";
	system("pause");
}

void main()
{
	setlocale(0, "Russian");
	MOTOR o;
	o.input();
	o.output();
	o.choose();
	o.order();
}