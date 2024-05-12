#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


pair<int, int> twoSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        if (arr[left] + arr[right] == target)
            return { left, right };
        else if (arr[left] + arr[right] < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return { -1, -1 };
}


int main() {
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    auto ans = twoSum(arr, target);
    cout << ans.first << ' ' << ans.second;
    return 0;
}
