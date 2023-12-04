//22. Generate Parentheses

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private: 
    
    void solve(string current, int open, int closed, int n, vector<string> &result) {

        // Base case: if the current combination is valid, add it to the result
        if (open == n && closed == n) {
            result.push_back(current);
            return;
        }

        // Recursively add an open parenthesis if the count is less than n
        if (open < n) {
            solve(current + '(', open + 1, closed, n, result);
        }

        // Recursively add a closed parenthesis if there are more open than closed
        if (open > closed) {
            solve(current + ')', open, closed + 1, n, result);
        }
    }

public:
    // Main function to generate all valid combinations of parentheses
    vector<string> generateParenthesis(int n) {
        // Vector to store the result
        vector<string> result;

        // Call the helper function with an empty string and counts initialized to 0
        solve("", 0, 0, n, result);

        // Return the final result
        return result;
    }
};

/* Time Complexity: The time complexity of this solution is O(4^n / sqrt(n)), where n is the given input. This is because each valid combination can have a length of 2n, and at each position, there are 2 choices (open or closed parentheses), resulting in a total of 2^(2n) combinations. The additional factor of 1/sqrt(n) is due to the Catalan number formula, which bounds the number of valid combinations.

Space Complexity: The space complexity is O(4^n / sqrt(n)) as well, considering the space required for the recursive call stack. */