// https://leetcode.com/problems/find-pivot-index/?envType=problem-list-v2&envId=prefix-sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1, 7, 3, 6, 5, 6
//      8  ^ 17
//         11 ^ 11
// 1 8 11 17 22 28

// lSum = 0, rSum = 27

int pivotIndex(vector<int> &nums)
{
    int leftSum = 0;
    int rightSum = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        rightSum += nums[i];
    }

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (leftSum == rightSum)
        {
            return i;
        }
        leftSum += nums[i];
        rightSum -= nums[i + 1];
    }
    if (leftSum == rightSum)
    {
        return nums.size() - 1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {-1, -1, 0, 1, 1, 0};
    cout << pivotIndex(nums);

    return 0;
}