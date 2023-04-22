#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct flash
{
	flash* firstElement;
	string firm;
	string model;
	int capacity;
	flash* pred;
	flash* next;
};
flash* first, * q, * p, * last;
int main()
{
	system("cls");
	setlocale(0, "Russian");
	first = new flash;
	first->firstElement = first;
	int flag;
	p = first;
	first->pred = NULL;
	first->next = NULL;
	cout << "Введите фирму флешки: " << endl;
	cin >> first->firm;
	cout << "Введите модель флешки: " << endl;
	cin >> first->model;
	cout << "Введите объём памяти у флешки: " << endl;
	cin >> first->capacity;
	cout << "Ввести следующий элемент? (да-1, нет-0) " << endl;
	cin >> flag;
	while (flag == 1)
	{
		last = new flash;
		cout << "Введите фирму флешки: " << endl;
		cin >> last->firm;
		cout << "Введите модель флешки: " << endl;
		cin >> last->model;
		cout << "Введите объём памяти у флешки: " << endl;
		cin >> last->capacity;
		last->firstElement = first;
		last->next = NULL;
		last->pred = p;
		p->next = last;
		p = last;
		cout << "Ввести следующий элемент списка? (да-1, нет-0) " << endl;
		cin >> flag;
	}

	cout << "Список создан!" << endl;
	cout << "*************************************************************************************\n";
	cout << "Фиима флешки " << setw(20) << " Модель флешки " << setw(20) << " объём памяти флешки" << endl;
	cout << "*************************************************************************************\n";
	p = first;

	while (p != NULL)
	{
		cout << "*************************************************************************************\n";
		cout << p->model << setw(25) << p->firm << setw(27) << p->capacity << endl;
		cout << "*************************************************************************************\n";
		p = p->next;

	}
	flag = 100;
	cout << "Хотите ввести новые элементы? (1 - да, 0 - нет) " << endl;
	cin >> flag;
	while (flag == 1) {


		flag = 1;
		q = new flash;
		q->pred = last;
		cout << "Введите фирму флешки: " << endl;
		cin >> q->firm;
		cout << "Введите модель флешки: " << endl;
		cin >> q->model;
		cout << "Введите объём памяти у флешки: " << endl;
		cin >> q->capacity;
		q->next = NULL;
		q->pred = last;
		last->next = q;
		last = q;

		cout << "Хотите ввести новые элементы? (1 - да, 0 - нет) " << endl;
		cin >> flag;

	}

	cout << "Список создан!" << endl;
	cout << "*************************************************************************************\n";
	cout << "Фирма флешки " << setw(20) << " Модель флешки " << setw(20) << " Объём памяти флешки" << endl;
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
