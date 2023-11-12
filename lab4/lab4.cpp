#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>

using namespace std;

const int n = 4;

void initMas(int* pMatr)
{
	for (int* i = pMatr; i < (pMatr + n * n); i++)
		*i = rand() % 100;
}

void printMas(int* pMatr)
{
	for (int i = 0; i < n*n; i++, pMatr++)
	{
		cout.width(4);
		cout << right << *pMatr;
		if ((i + 1) % n) cout << "\t";
		else cout << "\n";
	}
	cout << "\n";
}

void avgRow(int* pMatr, double* pArr) {
	int sum = 0;
	for (int i = 0; i < n * n; i++, pMatr++)
	{
		if ((i + 1) % n != 0) {
			sum += *pMatr;
		}
		else {
			sum += *pMatr;
			*pArr = sum / n;
			pArr++;
			sum = 0;
		}
	}
}

void printAvg(double* pArr) {
	for (int i = 0; i < n; i++, pArr++)
	{
		cout.width(4);
		cout << right << *pArr;
	}
	cout << "\n";
}

void calcMaxMin(int* pMatr, int* pMaxMin) {
	int max = *pMatr;
	int	min = *pMatr;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++) {
			if (*pMatr > max) max = *pMatr;
			if (*pMatr < min) min = *pMatr;
			if (j+1 == n - i) {
				pMatr += i+1;
			}
			else {
				pMatr++;
			}
		}
	}
	*pMaxMin = max;
	pMaxMin++;
	*pMaxMin = min;
}

int main()
{
	time_t k;
	srand(time(&k));

	setlocale(LC_ALL, "Rus");

	int matrix[n * n];
	double avgArr[n];
	int maxmin[2];

	initMas(matrix);
	printMas(matrix);
	avgRow(matrix, avgArr);
	printAvg(avgArr);
	calcMaxMin(matrix, maxmin);

	cout.width(4);
	cout << right << maxmin[0] << " " << maxmin[1] << "\n";
}