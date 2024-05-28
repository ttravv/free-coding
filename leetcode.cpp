//https://leetcode.com/problems/majority-element/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> hash_map;
    for (int i = 0; i < nums.size(); ++i) {
        if (hash_map.find(nums[i]) != hash_map.end()) {
            hash_map[nums[i]] += 1;
        }
        else {
            hash_map[nums[i]] = 1;
        }
    }

    for (auto v : hash_map) {
        if (v.second > nums.size() / 2) {
            return v.first;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = { 3, 2, 3 };
    cout << majorityElement(nums) << endl;
    return 0;
}
