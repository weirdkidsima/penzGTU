#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

struct HORSEPOWER
{
	int horsepower;
};

struct MOTOR
{
	char firm[20]; char number[20]; char vid1[20]; char vid2[20]; HORSEPOWER horse;
};

const char filename[] = "file.txt";
fstream file;

void writeToFile(int num)//функция записи в файл
{
	setlocale(0, "Russian");
	MOTOR st; 
	system("cls");
	file.open(filename, ios::out);
	cout << "Введите данные: ";
	for (int i = 0; i < num; i++)
	{
		cout << "фирма мотоцикла: "; cin >> st.firm;
		cout << "номер транспорта: "; cin >> st.number;
		cout << "вид: "; cin >> st.vid1 >> st.vid2;
		cout << "лошадиные силы: "; cin >> st.horse.horsepower;
		file << st.firm << "\n" << st.number << "\n" << st.vid1 << "\n" << st.vid2 << "\n" << st.horse.horsepower << "\n";
	}
	file.close();
	system("pause");
}

void printFile()//функция чтения файла
{
	setlocale(0, "Russian");
	MOTOR st; system("cls");
	file.open(filename, ios::in);
	cout << "-------------------------------------------------------------------------------\n";
	cout << "|фирма мотоцикла" << " || " << setw(10) << "  " << setw(10) << "номер" << "      || " << setw(15) << "вид" << "      || " << setw(10) << "лошадиные силы|\n";
	while (!file.eof())
	{
		file >> st.firm >> st.number >> st.vid1 >> st.vid2 >> st.horse.horsepower;
		if (file.peek() != EOF)
			cout << "|" << st.firm << "      || " << setw(10) << "  " << setw(10) << st.number << "      || " << setw(10) << st.vid1 << " || " << st.vid2 << " ||       " << st.horse.horsepower << "|" << "\n";
		cout << "--------------------------------------------------------------------------------\n";
	}

	file.close();
	system("pause");
}

void fileRewrite()//функция перезаписи файла
{
	setlocale(0, "Russian");
	file.open(filename, ios::out);
	file.close();
}

void choose()//функция поиска
{
	setlocale(0, "Russian");
	MOTOR st; system("cls");
	file.open(filename, ios::in);
	cout << "-------------------------------------------------------------------------------\n";
	cout << "Фирма мотоцикла номер\t вид\t лошадиные силы\n";
	while (!file.eof())
	{
		file >> st.firm >> st.number >> st.vid1 >> st.vid2 >> st.horse.horsepower;
		if ((file.peek() != EOF) && (st.horse.horsepower == 46))
			cout << "|" << st.firm << "||" << st.number << "||" << st.vid1 << "||" << st.vid2 << "||" << st.horse.horsepower << "/n";
	}
	cout << "--------------------------------------------------------------------------------";
	file.close(); system("pause");
}

void order()//функция сортировки
{
	setlocale(0, "Russian");
	MOTOR moto[20], x; int i, j, k = 0;
	file.open(filename, ios::in);
	system("cls");
	cout << "|Фирма мотоцикла" << setw(20) << "номер " << setw(25) << "вид" << setw(23) << "лошадиные силы|\n ";
	while (!file.eof())
	{
		file >> x.firm >> x.number >> x.vid1 >> x.vid2 >> x.horse.horsepower;
		if (file.peek() != EOF) { moto[k] = x; k++; }
	}
	file.close();
	for (i = 0; i < k - 1; i++)
		for (j = 0; j < k - 1; j++)
			if (moto[j].horse.horsepower < moto[j + 1].horse.horsepower)
			{
				x = moto[j]; moto[j] = moto[j + 1]; moto[j + 1] = x;
			}
	for (i = 0; i < k; i++)
	{
		cout << "|" << moto[i].firm << "      || " << setw(10) << "  " << setw(10) << moto[i].number << "      || " << setw(10) << moto[i].vid1 << " || " << moto[i].vid2 << " ||       " <<
			moto[i].horse.horsepower << "|" << "\n";
	}
	cout << "--------------------------------------------------------------------------------";
	system("pause");
}

void main()
{
	setlocale(0, "Russian");
	char menu; int i;
	do
	{
		system("cls"); cout << "1-Запись в файл\n2-Вывод на экран\n3-Очистка файла\n4-Выбор\n5-Сортировка\n6-Выход";
		cin >> menu; switch (menu)
		{
		case'1':cout << "Количество записей"; cin >> i;
			writeToFile(i); break;
		case'2':printFile(); break;
		case'3':fileRewrite(); break;
		case'4':choose(); break;
		case'5':order(); break;
		}
		if (menu == '6') break;
	} while (1);
}