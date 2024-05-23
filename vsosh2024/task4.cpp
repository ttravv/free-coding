#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    deque<int> left, right;


    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            left.push_back(i + 1);
        }
    }


    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            right.push_back(i + 1);
        }
    }

    vector<int> result;

    while (k--) {

        int left_place = left.front();
        int right_place = right.front();

        int left_distance = left_place - 1;
        int right_distance = n - right_place;


        if (left_distance < right_distance || (left_distance == right_distance && left_place < right_place)) {
            result.push_back(left_place);
            left.pop_front();
        }
        else {
            result.push_back(right_place);
            right.pop_front();
        }
    }


    for (int place : result) {
        cout << place << " ";
    }
    cout << endl;

    return 0;
}