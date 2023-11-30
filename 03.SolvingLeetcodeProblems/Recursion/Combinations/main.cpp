//77. Combinations

#include <iostream>
using namespace std;

// 1. Backtracking approach

class Solution {
public:
    // Vector to store the final combinations
    vector<vector<int>> result;

    // Recursive function to generate combinations
    void solve(int start, int &n, int k, vector<int> &temp) {
        // Base case: If k becomes 0, add the current combination to the result
        if (k == 0) {
            result.push_back(temp);
            return;
        }

        // Optimization: If 'start' exceeds n, stop the recursion
        if (start > n)
            return;

        // Include the current number in the combination
        temp.push_back(start);
        solve(start + 1, n, k - 1, temp);

        // Exclude the current number from the combination
        temp.pop_back();
        solve(start + 1, n, k, temp);
    }

    // Main function to get combinations of size k from 1 to n
    vector<vector<int>> combine(int n, int k) {
        // Vector to store the current combination during the recursion
        vector<int> temp;

        // Start the recursive process from the first number
        solve(1, n, k, temp);

        // Return the final result containing all combinations
        return result;
    }
};

/*----------------------------------------------------------------------------*/

//2. Same backtracking approach with the loop

class Solution {
public:
    // Vector to store the final combinations
    vector<vector<int>> result;

    // Recursive function to generate combinations
    void solve(int start, int &n, int k, vector<int> &temp) {
        // Base case: If k becomes 0, add the current combination to the result
        if (k == 0) {
            result.push_back(temp);
            return;
        }

        // Iterate through all possible numbers from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            // Include the current number in the combination
            temp.push_back(i);
            solve(i + 1, n, k - 1, temp);
            // Exclude the current number from the combination (backtrack)
            temp.pop_back();
        }
    }

    // Main function to get combinations of size k from 1 to n
    vector<vector<int>> combine(int n, int k) {
        // Vector to store the current combination during the recursion
        vector<int> temp;

        // Start the recursive process from the first number
        solve(1, n, k, temp);

        // Return the final result containing all combinations
        return result;
    }
};

//Time complexity : O( C(n, k) )
//Space complexity : O(k)