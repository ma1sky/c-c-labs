#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>

using namespace std;

void printArr(float* arr, int size) {
	cout << "Вывод массива чисел: " << "\t";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n";
}

void sumCols(float** pMat, float* pArr, int n, int m) {
	float sum = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (i >= n / 2 && j >= m / 2 || i < n / 2 && j < m / 2) {
				sum += pMat[i][j]; 
			}
		}
		pArr[j] = sum;
		sum = 0;
	}
}

void sumRows(float** pMat, float* pArr, int n, int m) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i >= n / 2 && j >= m / 2 || i < n / 2 && j < m / 2) {
				sum += pMat[i][j];
			}
		}
		pArr[i] = sum;
		sum = 0;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	time_t k;
	srand(time(&k));

	int n;
	int m;

	cin >> n >> m;

	//declaration
	float** matrix = new float* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new float[m];
	}

	float* arrCols = new float[m];
	float* arrRows = new float[n];

	//initialization
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 10;
	}

	//printing
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}

	sumCols(matrix, arrCols, n, m);
	sumRows(matrix, arrRows, n, m);
	cout << "\n" << "=================================================================" << "\n\n";
	printArr(arrCols, m);
	printArr(arrRows, n);

	//cleanup
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] arrCols;
	delete[] arrRows;
}