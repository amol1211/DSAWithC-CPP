//377. Combination Sum IV

#include <iostream>
#include <vector>
using namespace std;

// 1. Simple backtracking approach (TLE)

class Solution {
public:
    int n;
    // Recursive function to count combinations that sum up to the target
    int solve(int index, vector<int>& nums, int target) {
        // Base case: If the target is reached, return 1 (valid combination found)
        if (target == 0) return 1;

        // Base case: If index exceeds array size or target becomes negative, return 0
        if (index >= n || target < 0) return 0;

        // Recursive calls for taking and rejecting the current number
        int take_index = solve(0, nums, target - nums[index]);
        int reject_index = solve(index + 1, nums, target);

        // Return the sum of combinations
        return take_index + reject_index;
    }
    
    // Main function to get the count of combinations that sum up to the target
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();

        // Start the recursive process from the beginning of the array
        return solve(0, nums, target);
    }
};

// Time complexity : O(2^n)
// Space complexity : O(n)

/*---------------------------------------------------------------------------------------------------*/

// 2. Backtracking with memoization

class Solution {
public:
    int n;
    int t[201][1001];
    // Recursive function with memoization to count combinations that sum up to the target
    int solve(int index, vector<int>& nums, int target) {
        // Base case: If the target is reached, return 1 (valid combination found)
        if (target == 0) return 1;

        // Base case: If index exceeds array size or target becomes negative, return 0
        if (index >= n || target < 0) return 0;

        // Check if the result for the current state is already calculated
        if(t[index][target] != -1)
            return t[index][target];

        // Recursive calls for taking and rejecting the current number
        int take_index = solve(0, nums, target - nums[index]);
        int reject_index = solve(index + 1, nums, target);

        // Memoize the result and return the sum of combinations
        return t[index][target] = take_index + reject_index;
    }
    
    // Main function to get the count of combinations that sum up to the target
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        // Initialize the memoization table with -1
        memset(t, -1, sizeof(t));
        // Start the recursive process from the beginning of the array
        return solve(0, nums, target);
    }
};

//// Time complexity : O(n⋅target)
// Space complexity : O(n⋅target)

/*----------------------------------------------------------------------------*/

// 3. Same memoization approach with loop

class Solution {
public:
    int n;
    int t[201][1001];
    // Recursive function with memoization to count combinations that sum up to the target
    int solve(int index, vector<int>& nums, int target) {
        // Base case: If the target is reached, return 1 (valid combination found)
        if (target == 0) return 1;

        // Base case: If index exceeds array size or target becomes negative, return 0
        if (index >= n || target < 0) return 0;

        // Check if the result for the current state is already calculated
        if(t[index][target] != -1)
            return t[index][target];

        int result = 0;
        // Iterate through numbers starting from the current index
        for (int i = index; i < n; i++) {
            // Recursive call for taking the current number
            int take_index = solve(0, nums, target - nums[i]);
            result += take_index;
        }

        // Memoize the result and return the sum of combinations
        return t[index][target] = result;
    }
    
    // Main function to get the count of combinations that sum up to the target
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        // Initialize the memoization table with -1
        memset(t, -1, sizeof(t));
        // Start the recursive process from the beginning of the array
        return solve(0, nums, target);
    }
};

// Time complexity : O(n^2⋅target)
// Space complexity : O(n⋅target)

