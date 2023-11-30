//216. Combination Sum III

#include <iostream>
#include <vector>
using namespace std;

// 1. Backtracking approach

class Solution {
public:
    // Recursive function to find combinations with a specific sum and size
    void solve(int k, int &n, int currentSum, int currentIndex, vector<int> &temp, vector<vector<int>> &result) {
        // Base case: If the current sum exceeds the target or the combination size exceeds k, return
        if (currentSum > n || temp.size() > k) return;

        // If the current sum equals the target and the combination size is k, add it to the result
        if (currentSum == n && temp.size() == k) {
            result.push_back(temp);
            return;
        }

        // Iterate through numbers from currentIndex to 9 (inclusive)
        for (int i = currentIndex; i <= 9; i++) {
            // Skip duplicates to avoid duplicate combinations
            if (i > currentIndex && i == (i - 1)) continue;

            // Include the current number in the combination
            temp.push_back(i);
            currentSum += i;

            // Recursive call to explore combinations with the current number
            solve(k, n, currentSum, i + 1, temp, result);

            // Backtrack: remove the last added number for the next iteration
            temp.pop_back();
            currentSum -= i;
        }
    }

    // Main function to get combinations with a specific sum and size
    vector<vector<int>> combinationSum3(int k, int n) {
        // Vector to store the final combinations
        vector<vector<int>> result;
        // Vector to store the current combination during the recursion
        vector<int> temp;

        // Start the recursive process from the first number (1)
        solve(k, n, 0, 1, temp, result);

        // Return the final result containing combinations with the desired sum and size
        return result;
    }
};

//Time complexity : O(2^9/9) 
//Space complexity : O(k)