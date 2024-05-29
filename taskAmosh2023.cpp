//https://mos.olimpiada.ru/upload/files/Archive_tasks_2013-.../2023-24/iikt/tasks-iikt-9-otbor-23-24.pdf

#include <iostream>
using namespace std;

long long probka(int countMachines, int green, int machines, int red) {
    long long ans = 0;
    long long seconds = 0;
    long long oneGreen = machines * green;

    if (oneGreen >= countMachines + 1) {
        seconds = countMachines / machines + ((countMachines % machines) == 0 ? 0 : 1);
    }
    else {

        while ((countMachines + 1 - oneGreen) > 0) {
            countMachines -= oneGreen;
            seconds += oneGreen + red;
        }

        seconds += (countMachines + 1) / machines + ((countMachines % machines) == 0 ? 0 : 1);
    }
    ans += seconds;
    return ans;
}



int main() {
    int countMachines, green, machines, red;
    cin >> countMachines;
    cin >> green >> machines >> red;
    cout << probka(countMachines, green, machines, red);

    return 0;
}