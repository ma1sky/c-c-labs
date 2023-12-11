#include <iostream>
#include <iomanip>
#include <clocale>
#include <time.h>

using namespace std;

void initArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
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
    }
}

int main() {
    clock_t start, end;

    setlocale(LC_ALL, "Rus");
    int size;
    cout << "Размер массива: ";
    cin >> size;

    int* array = new int[size];

    initArr(array, size);

    start = clock();
    
    selectionSort(array, size);

    end = clock();

    cout << "Отсортированный массив:\n";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }

    double duration = double(end - start);
    cout << "\nВремя выполнения: " << duration << " миллисекунд" << endl;

    delete[] array;

    return 0;
}
