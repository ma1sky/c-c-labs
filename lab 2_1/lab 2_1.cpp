#include <cstdlib>
#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Вывести сумму + чисел 1 части массива и сумму - чисел 2 части массива" << '\n';

	time_t k;
	srand(time(&k));

	const int N = 10;
	float X[N];
	float s1 = 0.0;
	float s2 = 0.0;

	for (int i = 0; i < N; i++) {
		X[i] = float(rand() % 11 - 5);

		if (i == int(N / 2)) { cout << '\n'; }
		cout << X[i] << ' ';

		if (i < int(N / 2) && X[i] > 0) {
			s1 += X[i];
		}
		if (i >= int(N / 2) && X[i] < 0) {
			s2 += X[i];
		}
	}
	cout << '\n';

	cout << "Вывод суммы положительных чисел 1 половины массива" << '\n';
	cout << s1 << '\n';

	cout << "Вывод суммы отрицательных чисел 2 половины массива" << '\n';
	cout << s2 << '\n';
}

