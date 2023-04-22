#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct flash
{

	string firm;
	string model;
	int capacity;
	flash* pred;
	flash* next;
};
flash* first, * q, * p, * last;
void input();
void output();
void dop();



int main()
{

	do
	{
		setlocale(0, "Russian");
		system("cls");
		cout << "Обработка списка:" << endl << endl;
		cout << "1 Ввод списка" << endl;
		cout << "2 Вывод списка" << endl;
		cout << "3 Ввод элемента в конец" << endl;
		cout << "4 Выход" << endl << endl;
		cout << "Введите действие: ";
		int n;
		cin >> n;
		switch (n)
		{
		case 1: input(); break;
		case 2: output(); break;
		case 3: dop(); break;
		case 4: break;
		}
		if (n == 4) break;
	} while (1);
	system("pause");
	return 0;
}
void input()
{
	first = new flash;

	int flag;
	p = first;
	first->pred = NULL;
	first->next = NULL;
	cout << "Введите фирму флешки: " << endl;
	cin >> first->firm;
	cout << "Введите модель флешки: " << endl;
	cin >> first->model;
	cout << "Введите объём памяти флешки: " << endl;
	cin >> first->capacity;
	cout << "Ввести следующий элемент? (да-1, нет-0) " << endl;
	cin >> flag;
	while (flag == 1)
	{
		last = new flash;
		last->next = NULL;
		cout << "Введите фирму флешки: " << endl;
		cin >> last->firm;
		cout << "Введите модель флешки: " << endl;
		cin >> last->model;
		cout << "Введите объём памяти флешки: " << endl;
		cin >> last->capacity;


		last->pred = p;
		p->next = last;
		p = last;
		cout << "Ввести следующий элемент списка? (да-1, нет-0) " << endl;
		cin >> flag;
	}
	system("pause");
}
void output()

{

	cout << "Список создан!" << endl;
	cout << "*************************************************************************************\n";
	cout << "Фирма флешки " << setw(20) << " Модель флешки " << setw(20) << " объём памяти флешки" << endl;
	cout << "*************************************************************************************\n";
	p = first;

	while (p != NULL)
	{
		cout << "*************************************************************************************\n";
		cout << p->firm << setw(25) << p->model << setw(27) << p->capacity << endl;
		cout << "*************************************************************************************\n";
		p = p->next;
	}
	system("pause");
}
void dop()
{
	q = new flash;
	cout << "Введите фирму флешки: " << endl;
	cin >> q->firm;
	cout << "Введите Модель флешки: " << endl;
	cin >> q->model;
	cout << "Введите объём памяти флешки: " << endl;
	cin >> q->capacity;


	p = first;

	cout << "Список создан!" << endl;
	cout << "*************************************************************************************\n";
	cout << "Фирма флешки " << setw(20) << " Модель флешки " << setw(20) << " объём памяти флешки" << endl;
	cout << "*************************************************************************************\n";
	while (p != NULL)
	{
		cout << "*************************************************************************************\n";
		cout << p->firm << setw(25) << p->model << setw(27) << p->capacity << endl;
		cout << "*************************************************************************************\n";
		p = p->next;

	}
	cout << q->firm << setw(25) << q->model << setw(27) << q->capacity << endl;
	cout << "-*************************************************************************************\n";
	system("pause");
}