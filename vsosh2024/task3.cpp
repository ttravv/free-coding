#include <iostream>
#include <algorithm>
using namespace std;

int64_t a, b, c;

bool can_organize(int64_t max_width) {
    int64_t boys_in_first_row = min(a, max_width);
    int64_t boys_in_fourth_row = min(a - boys_in_first_row, c);
    int64_t girls_in_second_row = min(b, c - boys_in_fourth_row);
    int64_t girls_in_third_row = b - girls_in_second_row;

    return boys_in_first_row <= max_width &&
        boys_in_fourth_row <= max_width &&
        girls_in_second_row <= max_width &&
        girls_in_third_row <= max_width;
}

int main() {
    cin >> a >> b >> c;

    int64_t left = 1, right = max(a, b), answer = right;

    while (left <= right) {
        int64_t mid = left + (right - left) / 2;
        if (can_organize(mid)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}