#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>

using namespace std;

int findPos(int Arr[], int s)
{
    for (int i = s; i != 0; i--)
    {
        if (Arr[i] >= 0) {
            return i;
        }
    }
    return -1;
}

int findMin(int Arr[], int s)
{
    int min = Arr[0];
    int pos = findPos(Arr, s);
    if (pos == -1) {
        pos = s+1;
    }
    for (int i = 0; i < pos; i++)
    {
        if (Arr[i] < min) {
            min = Arr[i];
        }
    }
    
    return min;
}

void initArr(int Arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        Arr[i] = rand() % 100 - 19;
    }
}

void printArr(int Arr[], int s)
{
    for (int i = 0; i < s; i++)
    { 
        cout.width(4);
        cout << right << Arr[i] << ' ';
    }
    cout << "\n";
}

int main()
{
    const int n1 = 6;
    const int n2 = 6;

    time_t k;
    srand(time(&k));

    setlocale(LC_ALL, "Rus");

    int A[n1];
    int B[n2];
    
    int term = 1;
    while (term) {
        initArr(A, n1);
        initArr(B, n2);

        printArr(A, n1);
        int minA = findMin(A, n1);
        cout << "Минимальный элемент первой части массива A: " << minA << '\n';

        printArr(B, n2);
        int minB = findMin(B, n2);
        cout << "Минимальный элемент первой части массива B: " << minB << '\n';

        cout << "Продолжить выполнение программы?" << '\n';
        cin >> term;
    }
}