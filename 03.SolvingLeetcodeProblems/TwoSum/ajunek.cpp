#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
/*---------------------------------------------------------------------------*/
class solution {
    public: 
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> indices(n);
        for(int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });        
        int left = 0, right = n-1;
        while(left < right) {
            int sum = nums[indices[left]], nums[indices[right]];
            if(sum == target) {
                return {indices[left], indices[right]};
            } else if(sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

