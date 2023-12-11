#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>


void main() {
	time_t k;
	srand(time(&k));

	int n, m;
	cout << "Введите количество строк и колонок" << endl;
	cin >> n >> m >> endl;
	
	float **matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m]
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 100;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cout << matrix[i][j] << "\t"
		}
		cout << "\n"
	}

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
}