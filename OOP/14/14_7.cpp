/*#include <iostream>
#include <cstring>
#include <locale.h>

using namespace std;

class part {
	private:
		string partname;	// название
		int partnumber;	// номер
		double cost;	// цена
	public:
		void setpart(const string& pname, int pn, double c) {
			partname = pname;
			partnumber = pn;
			cost = c;
		}
		void showpart() {
			cout << "\nНазвание = " << partname;
			cout << ", номер = " << partnumber;
			cout << ", цена = $" << cost;
		}
};

int main() {
	setlocale(LC_ALL, "ru");

	part part1, part2;
	part1.setpart("пружина", -7246, -5448.323);
	part2.setpart("винт", -1024, -8.25);

	cout << "\nПервая деталь: ";
	part1.showpart();
	cout << "\nВторая деталь: ";
	part2.showpart();
	cout << endl;

	return 0;
}*/