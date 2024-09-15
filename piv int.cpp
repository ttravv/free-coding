//https://leetcode.com/problems/find-the-pivot-integer/description/

class Solution {
public:
    int pivotInteger(int n) { 

    int left = 0;
    int summ = 0;
    for (int i = 0; i <= n; ++i) {
        summ += i;
    }
    
    int right = summ - 1;
    
    for (int pivot = 1; pivot <= n; ++pivot) {
        if (left > right) return -1;
        if (left == right) {  
        return pivot;
        }
        left += pivot;
        right -= pivot+1;
    }


    return -1;
}
};