#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


vector<int> func(vector<int>& arr) {
    vector<int> new_arr;
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int powr = pow(arr[right], 2);
        int powl = pow(arr[left], 2);
        if (powr > powl) {
            right--;
            new_arr.push_back(powr);
        }
        else {
            left++;
            new_arr.push_back(powl);
        }
    }
    return new_arr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    auto ans = func(arr);
    for (auto x : ans) {
        cout << x << ' ';
    }
    return 0;
}
