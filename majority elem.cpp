//https://leetcode.com/problems/majority-element/description/

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int current = 0, count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (count > nums.size() / 2) {
            break;
        }
        if (count == 0) {
            current = nums[i];
            count++;
        }
        else {
              if (current == nums[i]) {
                  count++;
              }
              else {
                  count--;
              }
        }
    }
    return current; 
}

int main() {
  vector<int> nums = {3, 2, 3}; //3
  cout << majorityElement(nums);

}