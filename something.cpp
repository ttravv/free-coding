//leetcode task

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int low_ind = 0;
    int high_ind = nums.size() - 1;
    while (low_ind <= high_ind) {
        int mid = (low_ind + high_ind) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            high_ind = mid - 1;
        }
        else {
            low_ind = mid + 1;
        }
    }
    return -1;
}

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>>  ans(2);
    for (int i = 0; i < nums1.size(); ++i) {
        if ((search(ans[0], nums1[i]) == -1) && (search(nums2, nums1[i]) == -1)) {
            ans[0].push_back(nums1[i]);
        }
    }
    for (int i = 0; i < nums2.size(); ++i) {
        if (search(ans[1], nums2[i]) == -1 && search(nums1, nums2[i]) == -1) {
            ans[1].push_back(nums2[i]);
        }
    }
    return ans;
}


int main() {
    vector<int> nums1 = { 26,48,-78,-25,42,-8,94,-68,26 };
    vector<int> nums2 = { 61,-17 }; //[[26,48,-78,-25,42,-8,94,-68,26],[61,-17]]
    auto ans = findDifference(nums1, nums2);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}