#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>

using namespace std;

const int n = 8;
const int m = 8;

void initMat(int Mat[n][m])
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            Mat[i][j] = rand() % 100 - 19;
        }
    }
}

void printMat(int Mat[n][m])
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cout.width(4);
            cout << right << Mat[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n";
}

int findMin(int Mat[n][m], int col) 
{
    int minM;
    int rowDiv = int(m / 2);
    for (int j = rowDiv; j < m; j++) {
        
        if (Mat[j][col] >= 0) {
            minM = Mat[j][col];
        }
    }
    for (int j = rowDiv; j < m; j++) {
        if (Mat[j][col] >= 0 && Mat[j][col] < minM) {
            minM = Mat[j][col];
        }
    }
    return minM;
}

int main()
{
    time_t k;
    srand(time(&k));

    setlocale(LC_ALL, "Rus");

    int M[n][m];

    int term = 1;

    while (term) {
        if (term == 1) {
            initMat(M);
            printMat(M);

            for (int i = 0; i < m; i++) {
                cout << findMin(M, i) << ' ';
            }
            cout << '\n';
        }
        else {
            break;
        }
        cout << "Продолжить выполнение программы?" << '\n';
        cin >> term;
    }
}