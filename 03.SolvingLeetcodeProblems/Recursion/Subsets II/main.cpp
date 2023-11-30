// 90. Subsets II

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Backtracking approach

class Solution {
private:
    // Recursive function to generate subsets with duplicates
    void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
        // Add the current subset to the result
        ans.push_back(output);

        // Iterate through numbers starting from the current index
        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicates to avoid duplicate subsets
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // Include the current number in the subset
            output.push_back(nums[i]);
            // Recursive call to explore subsets with the current number
            solve(nums, output, i + 1, ans);
            // Backtrack: remove the last added number for the next iteration
            output.pop_back();
        }
    }

public:
    // Main function to get subsets with duplicates
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Vector to store the final subsets
        vector<vector<int>> ans;
        // Vector to store the current subset during the recursion
        vector<int> output;
        // Sort the input array to handle duplicates efficiently
        sort(nums.begin(), nums.end());
        // Start the recursive process from the beginning of the array
        int index = 0;
        solve(nums, output, index, ans);

        // Return the final result containing subsets with duplicates
        return ans;
    }
};

//Time complexity : O(2^n)
//Space complexity : O(n⋅2 ^n) 