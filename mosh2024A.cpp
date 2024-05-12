#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4) == 0 && year % 100 != 0);
}

int mosh(int day, int month, int year, int day2, int month2, int year2) {
    map<int, int> monthDays{
        {1, 31}, {2, 28}, {3, 31}, {4, 30},  {5, 31},  {6, 30},
        {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31},
    };
    int ans = 0;
    // int counterYear = year2 - year;
    for (int i = year + 1; i < year2; ++i) {
        if (isLeapYear(i)) {
            ans += 366;
        }
        else
            ans += 365;
    }

    int daysOver = 0;
    int daysBegin = 0;
    if (month == month2 && year == year2) {
        return day2 - day;
    }
    if (year == year2) {
        for (int l = month; l <= month2; ++l) {
            if (l == month) {
                ans += monthDays[month] - day;
            }
            else if (l == month2) {
                ans += day2;
            }
            else {
                ans += monthDays[l];
            }
            if (l == 2 && isLeapYear(year)) {
                ans += 1;
            }
        }

    }
    else {
        for (int i = month; i <= 12; i++) {
            if (i == month) {
                daysOver += monthDays[month] - day;
            }
            else {
                daysOver += monthDays[i];
            }
            if (i == 2 && isLeapYear(year)) {
                daysOver += 1;
            }
        }
        for (int j = 1; j <= month2; j++) {
            if (j == month2) {
                daysBegin += day2;
            }
            else {
                daysBegin += monthDays[j];
            }
            if (j == 2 && isLeapYear(year)) {
                daysBegin += 1;
            }
        }
    }
    
    return daysBegin + daysOver + ans;
}



int main() {
    int day, month, year, day2, month2, year2;
    char tmp;
    for (int i = 0; i < 1; ++i) {
        cin >> day >> tmp >> month >> tmp >> year >> day2 >> tmp >> month2 >> tmp >>
            year2;
    }
    cout << mosh(day, month, year, day2, month2, year2);
}
