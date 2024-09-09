// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            rightSum += nums[i];
        }

        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            rightSum -= nums[i];
            ans[i] += abs(leftSum - (nums[i] * i)) + abs((int)(rightSum - nums[i] * (nums.size() - i - 1)));
            leftSum += nums[i];
        }
        return ans;
    }
};