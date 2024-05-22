#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

void task(vector<int>& arr, vector<int>& arr2, vector<int>& arr3) {
    unordered_map<int, int> map;
    set<int> unique;
    set<int> unique2;
    set<int> unique3;
    for (int i = 0; i < arr.size(); ++i) {
        unique.insert(arr[i]);
    }
    for (int j = 0; j < arr2.size(); ++j) {
        unique2.insert(arr2[j]);

    }
    for (int h = 0; h < arr3.size(); ++h) {
        unique3.insert(arr3[h]);
    }
    for (int i : unique) {
        map[i] += 1;
    }
    for (int i : unique2) {
        map[i] += 1;
    }
    for (int i : unique3) {
        map[i] += 1;
    }
    for (auto v : map) {
        if (v.second >= 2) {
            cout << v.first;
        }
    }
}


int main() {
    int n;

    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> n;

    vector<int> arr2;
    for (int h = 0; h < n; ++h) {
        int temp;
        cin >> temp;
        arr2.push_back(temp);
    }
    cin >> n;
    vector<int> arr3;
    for (int j = 0; j < n; ++j) {
        int temp;
        cin >> temp;
        arr3.push_back(temp);
    }
    task(arr, arr2, arr3);
    return 0;
}
