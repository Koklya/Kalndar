#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


//Функция для проверки високосного года
bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

//Функция для определения количества дней в месяце
int daysInMonth(int month, int year) {
    return month == 2 ? (isLeapYear(year) ? 29 : 28) : 31 - (month - 1) % 7 % 2;
}

//Функция для вычисления первого дня месяца
int calculateFirstDayOfMonth(int month, int year) {
    int totalDays = 0;
    for (int y = 1919; y < year; ++y)
        totalDays += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < month; ++m)
        totalDays += daysInMonth(m, year);
    return (totalDays + 2) % 7;
}

//Функция для вывода календаря
void printCalendar(int month, int year) {
    vector<string> months = { "ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ", "МАЙ", "ИЮНЬ", "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ", "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ" };
    cout << months[month - 1] << " " << year << endl;
    vector<string> days = { "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС" };
    for (const auto& day : days) cout << day << " ";
    cout << endl;
    int firstDay = calculateFirstDayOfMonth(month, year);
    for (int i = 0; i < firstDay; ++i) cout << "   ";
    for (int day = 1; day <= daysInMonth(month, year); ++day) {
        cout << setw(2) << day << " ";
        if ((firstDay + day) % 7 == 0) cout << endl;
    }
    cout << endl;
}

//Главная функция
int main() {
    setlocale(LC_ALL, "Russian");
    int month, year;
    cout << "Введите месяц и год (например, 3 2019): " << endl;
    cin >> month >> year;
    if (month < 1 || month > 12 || year < 1919 || year > 2069) {
        cout << "Некорректный ввод. Пожалуйста, введите допустимый месяц (1-12) и год (1919-2069)." << endl;
        return 1;
    }
    printCalendar(month, year);
    return 0;
}