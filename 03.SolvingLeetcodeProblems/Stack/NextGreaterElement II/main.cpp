//503. Next Greater Element II

#include <iostream>
#include <stack>
using namespace std;

// 1.Brute force appraoch

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  // Initialize the result vector with -1 values

        for (int i = 0; i < n; i++) {  // Loop through the elements in nums
            for (int j = 1; j < n; j++) {  // Search for the next greater element in a circular manner
                int nextIdx = (i + j) % n;  // Calculate the circular index

                if (nums[nextIdx] > nums[i]) {
                    ans[i] = nums[nextIdx];
                    break;  // We found the next greater element, so break the loop
                }
            }
        }

        return ans;
    }
};

//Time complexity : O(n^2)
//Space complexity : O(n)

/*------------------------------------------------------------------------------------*/

