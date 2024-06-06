//https://leetcode.com/problems/rank-transform-of-an-array/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    struct compare {
        bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first < p2.first;
        }
    };

public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) {
            return {};
        }
        vector<pair<int, int>>arr1;
        for (int i = 0; i < arr.size(); i++) {
            arr1.push_back(make_pair(arr[i], i));
        }
        sort(arr1.begin(), arr1.end(), compare());
        int rank = 1;
        for (int i = 0; i < arr1.size() - 1; i++) {
            if (arr1[i].first != arr1[i + 1].first) {
                arr[arr1[i].second] = rank;
                rank++;
            }
            else {
                arr[arr1[i].second] = rank;
            }
        }
        if (!arr1.empty()) {
            arr[arr1.back().second] = rank;
        }
        return arr;
    }
};