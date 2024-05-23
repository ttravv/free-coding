#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef long long int64;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<int, int64> prefix_count;
    prefix_count[0] = 1;

    int zero_count = 0, one_count = 0;
    int64 harmonic_substring_count = 0;

    for (char c : s) {
        if (c == '0') {
            zero_count++;
        }
        else {
            one_count++;
        }

        int key = (zero_count % 2) * 2 + (one_count % 2);
        harmonic_substring_count += prefix_count[key];
        prefix_count[key]++;
    }

    cout << harmonic_substring_count << endl;

    return 0;
}