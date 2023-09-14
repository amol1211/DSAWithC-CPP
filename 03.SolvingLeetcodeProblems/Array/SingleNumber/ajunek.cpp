#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {    
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            } else {
                i++;
            }
        }
        return nums[n - 1];    
    }
};
/*----------------------------------------------------*/
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
};