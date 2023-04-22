#include<iostream>
using namespace std;
int f(int arr[5][6], int n, int m, int j);
int main()
{
	setlocale(0, "Russian");
	cout << "Введите n строк по m чисел матрицы: " << endl;
	const int n = 5, m = 6;
	int a[n][m], res;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cout << "Ваша матрица: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == m - 1) {
				cout << a[i][j] << endl;
			}
			else {
				cout << a[i][j] << " ";
			}
		}
	}


	for (int i = 0; i < m; ++i) {
		res = f(a, 6, 5, i);
		cout << "Сумма положительных элементов столбца " << i + 1 << ": " << res << endl;
	}


	system("pause");
	return 0;
}

int f(int arr[5][6], int n, int m, int j)
{


	int sum = 0;
	for (int i = 0; i < m; ++i) {

		if (arr[i][j] > 0)
			sum = sum + arr[i][j];

	}

	return sum;

}
