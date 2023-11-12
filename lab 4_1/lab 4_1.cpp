#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>

using namespace std;

const int n = 5;

void initMas(int* indMatr)
{
	for (int* i = indMatr; i < (indMatr + n * n); i++)
		*i = rand() % 100;
}

void printMas(int* indMatr)
{
	for (int i = 0; i < n; i++, indMatr++)
	{
		cout.width(4);
		cout << right << *indMatr;
		if ((i + 1) % n) cout << "\t";
		else cout << "\n";
	}
	cout << "\n";
}

int main()
{
	time_t k;
	srand(time(&k));

	setlocale(LC_ALL, "Rus");

	float arrAvg[n];
	int matrix[n*n];

	initMas(matrix);
	printMas(matrix);

	delete[] matrix;
}