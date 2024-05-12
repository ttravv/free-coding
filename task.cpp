#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm> 
using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 4 == 0 && year % 100 != 0) return true;
    return false;
}

// Реализовать функцию проверки на високосный год
// map, в котором будет структура (месяц - количество дней)

void yandex(int year, vector<pair<int, string>>& holidays, string dayWeek) {
    int dayFeb = isLeapYear(year) ? 29 : 28;
    vector<pair<string, int>> monthDays = {
        make_pair("January", 31),
        make_pair("February", dayFeb),
        make_pair("March", 31),
        make_pair("April", 30),
        make_pair("May", 31),
        make_pair("June", 30),
        make_pair("July", 31),
        make_pair("August", 31),
        make_pair("September", 30),
        make_pair("October", 31),
        make_pair("November", 30),
        make_pair("December", 31)
    };

    vector<string> daysWeek = { "Monday", "Tuesday",  "Wednesday", "Thursday",  "Friday",  "Saturday", "Sunday" };
    int idx = find(daysWeek.begin(), daysWeek.end(), dayWeek) - daysWeek.begin();

    unordered_map<string, int> week_days = {
    {"Monday", 0}, {"Tuesday", 0},  {"Wednesday", 0}, {"Thursday", 0}, {"Friday", 0},  {"Saturday", 0}, {"Sunday", 0}
    };
    string bestDay = "Monday", worstDay = "Monday";
    for (auto month : monthDays) {
        for (int day = 1; day <= month.second; day++) {
            if (find(holidays.begin(), holidays.end(), make_pair(day, month.first)) == holidays.end()) {
                week_days[daysWeek[idx]] += 1;
            }
            idx += 1;
            if (idx > 6) idx = 0;
        }
    }

    int min = week_days["Monday"];
    int max = week_days["Monday"];
    for (auto x : week_days) {
        cout << x.first << ' ' << x.second << '\n';
        if (x.second < min)
        {
            min = x.second;
            bestDay = x.first;
        }
        else if (x.second > max) {
            max = x.second;
            worstDay = x.first;
        }
    }

    cout << worstDay << ' ' << bestDay;

}

int main() {
    int n;
    cin >> n;
    int year;
    cin >> year;
    vector<pair<int, string>> holidays;
    for (int i = 0; i < n; ++i) {
        int day;
        string month;
        cin >> day >> month;
        holidays.push_back(make_pair(day, month));
    }
    string dayWeek;
    cin >> dayWeek;
    yandex(year, holidays, dayWeek);

    return 0;
}
