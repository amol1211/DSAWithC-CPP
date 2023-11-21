//78. Subsets

#include <iostream>
#include <vector>
using namespace std;

// 1. Iterative brute force approach

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Create a vector to store the subsets
        vector<vector<int>> result;

        // Start with an empty subset (an empty vector)
        result.push_back(vector<int>());

        // Iterate through each element in the input vector 'nums'
        for (int n : nums) {
            // Get the current size of the 'result' vector
            int size = result.size();

            // Iterate through each subset in the 'result' vector
            for (int i = 0; i < size; i++) {
                // Create a copy of the current subset
                vector<int> subset = result[i];

                // Add the current element 'n' to the subset
                subset.push_back(n);

                // Add the modified subset to the 'result' vector
                result.push_back(subset);
            }
        }

        // Return the final vector of subsets
        return result;
    }
};

//Time complexity : O(N * 2^N)
//Space complexity : O(2^N)

/*----------------------------------------------------------*/

// 2. Recursive approach 

#include <vector>

class Solution {
private:
    // Helper function to generate subsets recursively
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans) {
        // Base case: If index is beyond the size of 'nums', add the current 'output' to 'ans' and return
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Exclude the current element at 'index'
        solve(nums, output, index + 1, ans);

        // Include the current element at 'index'
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
    }

public:
    // Main function to generate all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        // Result vector to store all subsets
        vector<vector<int>> ans;
        // Temporary vector to store the current subset being generated
        vector<int> output;
        // Start the recursive process from index 0
        int index = 0;
        solve(nums, output, index, ans);

        // Return the final result containing all subsets
        return ans;
    }
};

//Time complexity : O(2^N)
//Space complexity : O(2^N)
