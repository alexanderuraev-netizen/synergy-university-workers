#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WORKER {
private:
    string fullName;
    string position;
    double salary;
    int startYear;

public:
    WORKER() : fullName("Неизвестно"), position("Не указана"), salary(0.0), startYear(2024) {}
    WORKER(string name, string pos, double sal, int year) : fullName(name), position(pos), salary(sal), startYear(year) {}
    
    string getFullName() const { return fullName; }
    int getStartYear() const { return startYear; }
    int calculateExperience(int currentYear) const { return currentYear - startYear; }
    void display() const {
        cout << "ФИО: " << fullName << " | Должность: " << position << " | Зарплата: " << salary << " руб." << endl;
    }
};

int main() {
    cout << "=== Система учета сотрудников Университета 'Синергия' ===" << endl;
    
    vector<WORKER> workers;
    int count;
    
    cout << "Введите количество сотрудников: ";
    cin >> count;
    
    for (int i = 0; i < count; i++) {
        cout << "--- Сотрудник " << i + 1 << " ---" << endl;
        
        string name, position;
        double salary;
        int year;
        
        cin.ignore();
        cout << "Фамилия и инициалы: ";
        getline(cin, name);
        cout << "Должность: ";
        getline(cin, position);
        cout << "Зарплата: ";
        cin >> salary;
        cout << "Год поступления: ";
        cin >> year;
        
        workers.push_back(WORKER(name, position, salary, year));
        cout << endl;
    }
    
    int currentYear, minExperience;
    cout << "Введите текущий год: ";
    cin >> currentYear;
    cout << "Введите требуемый стаж: ";
    cin >> minExperience;
    
    cout << "\nСотрудники со стажем более " << minExperience << " лет:" << endl;
    bool found = false;
    for (const auto& worker : workers) {
        if (worker.calculateExperience(currentYear) > minExperience) {
            cout << worker.getFullName() << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Таких сотрудников нет." << endl;
    }
    
    cout << "\nВсе сотрудники:" << endl;
    for (const auto& worker : workers) {
        worker.display();
    }
    
    return 0;
}