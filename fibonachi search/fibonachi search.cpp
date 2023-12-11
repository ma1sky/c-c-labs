#include <iostream>
#include <clocale>
#include <time.h>
using namespace std;


void initArr(int* arr, int size) {
    for (int i = 0; i <= size; i++) {
        arr[i] = rand() % 100000;
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}

int min(int x, int y) 
{ 
    return (x <= y) ? x : y; 
}

int fibSearch(int* arr, int x, int n)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {

        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        else
            return i;
    }

    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int main()
{
    clock_t start, end;

    setlocale(LC_ALL, "Rus");

    int size;
    cout << "Размер массива: ";
    cin >> size;

    int* array = new int[size];

    initArr(array, size);
    selectionSort(array, size);

    int x;
    cout << "Элемент для поиска: ";
    cin >> x;

    start = clock();
    int ind = fibSearch(array, x, size);
    if (ind >= 0)
        cout << "Найден по индексу: " << ind;
    else
        cout << x << " не найден в массиве";
    end = clock();
    double duration = double(end - start);
    cout << "\nВремя выполнения: " << duration << " миллисекунд" << endl;

    delete[] array;

    return 0;
}