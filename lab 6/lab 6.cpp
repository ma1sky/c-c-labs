#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX_CLIENTS = 100; // Максимальное количество клиентов

struct Deposit {
    int accountNumber;
    char* lastName;
    char* firstName;
    double balance;
};

void addNewAccount(Deposit accounts[], int& count) {
    if (count < MAX_CLIENTS) {
        Deposit newAccount;
        cout << "Введите номер счета: ";
        cin >> newAccount.accountNumber;

        char lastName[50];
        char firstName[50];

        cout << "Введите фамилию клиента: ";
        cin >> lastName;
        newAccount.lastName = new char[strlen(lastName) + 1];
        strcpy(newAccount.lastName, lastName);

        cout << "Введите имя клиента: ";
        cin >> firstName;
        newAccount.firstName = new char[strlen(firstName) + 1];
        strcpy(newAccount.firstName, firstName);

        cout << "Введите сумму на счете: ";
        cin >> newAccount.balance;

        accounts[count++] = newAccount;
    }
    else {
        cout << "Достигнуто максимальное количество клиентов." << endl;
    }
}

void printAccounts(const Deposit accounts[], int count) {
    cout << "Номер счета\tФамилия\t\tИмя\t\tСумма на счете" << endl;
    for (int i = 0; i < count; ++i) {
        cout << accounts[i].accountNumber << "\t\t"
            << accounts[i].lastName << "\t\t"
            << accounts[i].firstName << "\t\t"
            << accounts[i].balance << endl;
    }
}

void findAccountsByBalance(const Deposit accounts[], int count, double threshold) {
    cout << "Счета с суммой больше " << threshold << ":" << endl;
    for (int i = 0; i < count; ++i) {
        if (accounts[i].balance > threshold) {
            cout << accounts[i].accountNumber << "\t\t"
                << accounts[i].lastName << "\t\t"
                << accounts[i].firstName << "\t\t"
                << accounts[i].balance << endl;
        }
    }
}

void findAccountsByClient(const Deposit accounts[], int count, const char* lastName, const char* firstName) {
    cout << "Счета клиента " << firstName << " " << lastName << ":" << endl;
    for (int i = 0; i < count; ++i) {
        if (strcmp(accounts[i].lastName, lastName) == 0 && strcmp(accounts[i].firstName, firstName) == 0) {
            cout << accounts[i].accountNumber << "\t\t"
                << accounts[i].lastName << "\t\t"
                << accounts[i].firstName << "\t\t"
                << accounts[i].balance << endl;
        }
    }
}

int main() {
    setlocale(0, "Russian");
    Deposit bankClients[MAX_CLIENTS];
    int clientCount = 0;
    int choice;
    double threshold;
    char lastName[50];
    char firstName[50];

    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Добавить новый счет\n";
        cout << "2. Распечатать информацию о счетах\n";
        cout << "3. Найти счета с суммой больше заданной\n";
        cout << "4. Найти счета заданного клиента\n";
        cout << "0. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addNewAccount(bankClients, clientCount);
            break;
        case 2:
            printAccounts(bankClients, clientCount);
            break;
        case 3:
            cout << "Введите пороговую сумму: ";
            cin >> threshold;
            findAccountsByBalance(bankClients, clientCount, threshold);
            break;
        case 4:
            cout << "Введите фамилию клиента: ";
            cin >> lastName;
            cout << "Введите имя клиента: ";
            cin >> firstName;
            findAccountsByClient(bankClients, clientCount, lastName, firstName);
            break;
        case 0:
            cout << "Конец\n";
            break;
        default:
            cout << "Некорректный ввод\n";
        }
    } while (choice != 0);

    for (int i = 0; i < clientCount; ++i) {
        delete[] bankClients[i].lastName;
        delete[] bankClients[i].firstName;
    }

    return 0;
}
