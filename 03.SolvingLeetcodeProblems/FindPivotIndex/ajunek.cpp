#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class solution {
    public: 
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};

/*-------------------------------------------------------------------------*/

class Solution {
    public: 
    int pivotIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int left = accumulate(nums.begin(), nums.begin()+i,0);
            int right = accumulate(nums.begin()+i+1, nums.end(),0);

            if (left == right) 
            return i;
        }
        return -1;
    }
};
