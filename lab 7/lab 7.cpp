#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const int MAX_CLIENTS = 100;

struct Date {
    int day;
    char* month;
    int year;
};

struct FIO {
    char* lastName;
    char* firstName;
};

struct Deposit {
    int accountNumber;
    FIO clientName;
    double balance;
    Date openingDate;
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
        newAccount.clientName.lastName = new char[strlen(lastName) + 1];
        strcpy(newAccount.clientName.lastName, lastName);

        cout << "Введите имя клиента: ";
        cin >> firstName;
        newAccount.clientName.firstName = new char[strlen(firstName) + 1];
        strcpy(newAccount.clientName.firstName, firstName);

        cout << "Введите сумму на счете: ";
        cin >> newAccount.balance;

        cout << "Введите дату открытия счета (день месяц год): ";
        cin >> newAccount.openingDate.day >> newAccount.openingDate.month >> newAccount.openingDate.year;

        accounts[count++] = newAccount;
    }
    else {
        cout << "Достигнуто максимальное количество клиентов." << endl;
    }
}

void printAccounts(const Deposit accounts[], int count) {
    cout << "Номер счета\tФамилия\t\tИмя\t\tСумма на счете\tДата открытия" << endl;
    for (int i = 0; i < count; ++i) {
        cout << accounts[i].accountNumber << "\t\t"
            << accounts[i].clientName.lastName << "\t\t"
            << accounts[i].clientName.firstName << "\t\t"
            << accounts[i].balance << "\t\t"
            << accounts[i].openingDate.day << " "
            << accounts[i].openingDate.month << " "
            << accounts[i].openingDate.year << endl;
    }
}

void findAccountsByBalance(const Deposit accounts[], int count, double threshold) {
    cout << "Счета с суммой больше " << threshold << ":" << endl;
    for (int i = 0; i < count; ++i) {
        if (accounts[i].balance > threshold) {
            cout << accounts[i].accountNumber << "\t\t"
                << accounts[i].clientName.lastName << "\t\t"
                << accounts[i].clientName.firstName << "\t\t"
                << accounts[i].balance << "\t\t"
                << accounts[i].openingDate.day << " "
                << accounts[i].openingDate.month << " "
                << accounts[i].openingDate.year << endl;
        }
    }
}

void findAccountsByClient(const Deposit accounts[], int count, const char* lastName, const char* firstName) {
    cout << "Счета клиента " << firstName << " " << lastName << ":" << endl;
    for (int i = 0; i < count; ++i) {
        if (strcmp(accounts[i].clientName.lastName, lastName) == 0 && strcmp(accounts[i].clientName.firstName, firstName) == 0) {
            cout << accounts[i].accountNumber << "\t\t"
                << accounts[i].clientName.lastName << "\t\t"
                << accounts[i].clientName.firstName << "\t\t"
                << accounts[i].balance << "\t\t"
                << accounts[i].openingDate.day << " "
                << accounts[i].openingDate.month << " "
                << accounts[i].openingDate.year << endl;
        }
    }
}

void findAccountsOpenedAfterDate(const Deposit accounts[], int count, const Date& date) {
    cout << "Счета, открытые после " << date.day << " " << date.month << " " << date.year << ":" << endl;
    for (int i = 0; i < count; ++i) {
        if (accounts[i].openingDate.year > date.year ||
            (accounts[i].openingDate.year == date.year && strcmp(accounts[i].openingDate.month, date.month) > 0) ||
            (accounts[i].openingDate.year == date.year && strcmp(accounts[i].openingDate.month, date.month) == 0 && accounts[i].openingDate.day > date.day)) {
            cout << accounts[i].accountNumber << "\t\t"
                << accounts[i].clientName.lastName << "\t\t"
                << accounts[i].clientName.firstName << "\t\t"
                << accounts[i].balance << "\t\t"
                << accounts[i].openingDate.day << " "
                << accounts[i].openingDate.month << " "
                << accounts[i].openingDate.year << endl;
        }
    }
}

void saveDataToFile(const Deposit accounts[], int count) {
    ofstream file("bank_data.txt");
    if (file.is_open()) {
        for (int i = 0; i < count; ++i) {
            file << accounts[i].accountNumber << " "
                << accounts[i].clientName.lastName << " "
                << accounts[i].clientName.firstName << " "
                << accounts[i].balance << " "
                << accounts[i].openingDate.day << " "
                << accounts[i].openingDate.month << " "
                << accounts[i].openingDate.year << endl;
        }
        file.close();
        cout << "Данные сохранены на диск." << endl;
    }
    else {
        cout << "Ошибка сохранения данных на диск." << endl;
    }
}

void loadDataFromFile(Deposit accounts[], int& count) {
    ifstream file("bank_data.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            Deposit newAccount;
            file >> newAccount.accountNumber;

            char lastName[50];
            char firstName[50];

            file >> lastName;
            newAccount.clientName.lastName = new char[strlen(lastName) + 1];
            strcpy(newAccount.clientName.lastName, lastName);

            file >> firstName;
            newAccount.clientName.firstName = new char[strlen(firstName) + 1];
            strcpy(newAccount.clientName.firstName, firstName);

            file >> newAccount.balance;
            file >> newAccount.openingDate.day >> newAccount.openingDate.month >> newAccount.openingDate.year;

            accounts[count++] = newAccount;
        }
        file.close();
        cout << "Данные загружены с диска." << endl;
    }
    else {
        cout << "Файл данных не найден. Создан новый файл для сохранения данных." << endl;
    }
}

int main() {
    Deposit bankClients[MAX_CLIENTS];
    int clientCount = 0;
    int choice;
    double threshold;
    char lastName[50];
    char firstName[50];
    Date date;

    loadDataFromFile(bankClients, clientCount);

    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Добавить новый счет\n";
        cout << "2. Распечатать информацию о счетах\n";
        cout << "3. Найти счета с суммой больше заданной\n";
        cout << "4. Найти счета заданного клиента\n";
        cout << "5. Найти счета, открытые после определенной даты\n";
        cout << "6. Сохранить данные на диск\n";
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
        case 5:
            cout << "Введите дату (день месяц год): ";
            cin >> date.day >> date.month >> date.year;
            findAccountsOpenedAfterDate(bankClients, clientCount, date);
            break;
        case 6:
            saveDataToFile(bankClients, clientCount);
            break;
        case 0:
            saveDataToFile(bankClients, clientCount);
            cout << "До свидания!\n";
            break;
        default:
            cout << "Некорректный ввод. Пожалуйста, выберите действие из списка.\n";
        }
    } while (choice != 0);

    for (int i = 0; i < clientCount; ++i) {
        delete[] bankClients[i].clientName.lastName;
        delete[] bankClients[i].clientName.firstName;
    }

    return 0;
}
