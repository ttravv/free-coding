//https://leetcode.com/problems/intersection-of-two-arrays/description/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ans;
	vector<pair<int, int>> mapForNumsOne;
	vector<pair<int, int>> mapForNumsTwo;
	for (int i = 0; i < nums1.size(); ++i) {
		
	}

	return ans;
}



int main() {
	vector<int> nums1 = { 1, 2, 2, 1 };
	vector<int> nums2 = { 2,2 };
	vector<int> ans = intersection(nums1, nums2);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
	}
	

	return 0;
}