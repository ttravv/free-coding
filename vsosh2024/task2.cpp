#include <iostream>
using namespace std;

int64_t a, b, n;


bool canLastForDays(int64_t days) {

    int64_t tablets_for_a = (days + a - 1) / a;

    int64_t tablets_for_b = days * b;

    int64_t total_tablets = tablets_for_a + tablets_for_b;

    return total_tablets <= n;
}

int main() {
    cin >> a >> b >> n;

    int64_t left = 0, right = n, answer = 0;

    while (left <= right) {
        int64_t mid = left + (right - left) / 2;

        if (canLastForDays(mid)) {

            answer = mid;
            left = mid + 1;
        }
        else {

            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}