#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Найти сумму элементов побочной диагонали и создать массив из ср.ар. строк" << '\n' << '\n';

	time_t k;
	srand(time(&k));

	const int N = 8;
	float avg[N] = {};
	int arr[N][N] = {};
	int sumDiag = 0;
	int sumStr = 0;
	int count = N;

	cout << "Элементы матрицы:" << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = rand() % 11;
			sumStr += arr[i][j];
			cout.width(3);
			cout << right << arr[i][j] << ' ';
		}
		avg[i] = float(sumStr) / N;
		cout << '\n';
	}
	cout << '\n';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			sumDiag += arr[i][j];
		}
	}

	cout << "Сумма элементов слева от побочной диагонали = "<< sumDiag << '\n' << '\n';
	
	cout << "Массив ср. арифметических строк:" << ' ';

	for (int i = 0; i < N; i++) {
		cout << avg[i] << ' ';
	}
	cout << '\n';
}