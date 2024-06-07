//https://leetcode.com/problems/contains-duplicate-ii/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i) {

        if (mp.count(nums[i])) {
            if (abs(i - mp[nums[i]]) <= k)
                return true;
        }

        mp[nums[i]] = i;
    }
    return false;
}

int main() {
    vector<int> nums = { 1,2,3, 1 };
    int k = 3;
    cout << containsNearbyDuplicate(nums, k);

    return 0;
}