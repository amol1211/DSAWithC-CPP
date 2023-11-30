//39. Combination Sum

#include <iostream>
#include <vector>
using namespace std;

// 1. Backtracking appproach

class Solution {
private:
    // Recursive function to find combinations that sum up to the target
    void solve(vector<int>& candidates, int target, vector<int> &currentCombination, int currentSum, int currentIndex, vector<vector<int>> &result) {
        // Base case: If the current sum exceeds the target, return
        if (currentSum > target) return;

        // If the current sum equals the target, add the current combination to the result
        if (currentSum == target) {
            result.push_back(currentCombination);
            return;
        }

        // Iterate through candidates starting from the current index
        for (int i = currentIndex; i < candidates.size(); i++) {
            // Include the current candidate in the combination
            currentCombination.push_back(candidates[i]);
            currentSum += candidates[i];

            // Recursive call to explore combinations with the current candidate
            solve(candidates, target, currentCombination, currentSum, i, result);

            // Backtrack: remove the last added candidate for the next iteration
            currentCombination.pop_back();
            currentSum -= candidates[i];
        }
    }

public:
    // Main function to get combinations that sum up to the target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Vector to store the final combinations
        vector<vector<int>> result;
        // Vector to store the current combination during the recursion
        vector<int> currentCombination;

        // Start the recursive process from the beginning of the candidates
        solve(candidates, target, currentCombination, 0, 0, result);

        // Return the final result containing combinations that sum up to the target
        return result;
    }
};

//Time complexity : O(2^n/n)
// Space complexity : O(n)