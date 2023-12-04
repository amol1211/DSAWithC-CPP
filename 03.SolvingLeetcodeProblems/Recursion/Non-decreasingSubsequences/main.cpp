//491. Non-decreasing Subsequences

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    // Variable to store the length of the input vector
    int n;

    // Backtracking helper function to find increasing subsequences
    void backtrack(vector<int> &nums, int index, vector<int> &curr, vector<vector<int>> &result) {
        // Base case: if the current subsequence has at least two elements, add it to the result
        if (curr.size() >= 2) {
            result.push_back(curr);
        }

        // Set to keep track of elements to avoid duplicates in the same level of recursion
        unordered_set<int> st;

        // Iterate over the remaining elements in the vector
        for (int i = index; i < n; i++) {
            // Check if the current element is greater than or equal to the last element in the subsequence
            // and if it is not a duplicate element in the same level of recursion
            if ((curr.empty() || nums[i] >= curr.back()) && (st.find(nums[i]) == st.end())) {

                // Include the current element in the subsequence
                curr.push_back(nums[i]);

                // Recursively call the function with the updated subsequence
                backtrack(nums, i + 1, curr, result);

                // Backtrack: remove the last element to explore other possibilities
                curr.pop_back();

                // Add the current element to the set to avoid duplicates at the same level of recursion
                st.insert(nums[i]);
            }
        }
    }

public:
    // Main function to find all increasing subsequences
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // Set the length of the input vector
        n = nums.size();

        // Vector to store the result
        vector<vector<int>> result;

        // Vector to store the current subsequence
        vector<int> curr;

        // Start the backtracking process
        backtrack(nums, 0, curr, result);

        // Return the final result
        return result;
    }
};

//Time complexity : O(2^n)
//Space complexity : O(n) 