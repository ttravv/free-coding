#include <iostream>

int daysInMonth(int month) {
    if (month == 9 || month == 11)
        return 30;
    else
        return 31;
}

int main() {
    int startMonth, startDay;
    std::cin >> startMonth >> startDay;
    std::cout << startMonth << " " << startDay << std::endl;
    int startWeekday = (startDay - 1) % 7 + 1;

    int currentMonth = startMonth;
    int currentDay = startDay;

    for (int month = startMonth; month <= 12; month++) {
      
        int days = daysInMonth(month);

        for (int day = currentDay + 7; day <= days; day += 7) {
   
            std::cout << month << " " << day << std::endl;
        }
        currentMonth = month + 1;
        currentDay = (startWeekday - (startDay % 7) + days) % days + 1;
        startWeekday = (startWeekday + days - (startDay % 7)) % 7 + 1;
    }

    return 0;
}
