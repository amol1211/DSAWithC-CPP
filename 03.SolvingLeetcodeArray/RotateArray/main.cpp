// 189. Rotate Array

#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Calculate actual number of steps to rotate
        k = k % n;
        
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements separately
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the remaining elements separately
        reverse(nums.begin() + k, nums.end());
    }
};
