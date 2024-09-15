// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {

        vector<int> prefixSum(arr.size());
        int ans = 0;
        prefixSum[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i)
        {
            prefixSum[i] = arr[i] + prefixSum[i - 1];
        }
        ans += prefixSum[arr.size() - 1];

        if (arr.size() % 2 != 0 && arr.size() != 1)
            ans += prefixSum[arr.size() - 1];

        for (int size = 3; size < arr.size(); size += 2)
        {
            for (int r = size - 1; r < arr.size(); r++)
            {
                int l = r - size + 1;
                if (l == 0)
                {
                    ans += prefixSum[r];
                }
                else
                {
                    ans += prefixSum[r] - prefixSum[l - 1];
                }
            }
        }
        return ans;
    }
};