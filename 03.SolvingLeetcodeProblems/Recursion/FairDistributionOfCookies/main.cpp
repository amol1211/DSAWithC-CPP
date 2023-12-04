//2305. Fair Distribution of Cookies

#include <iostream>
#include <vector>
#include <climits>
#include "../../../../../../../MinGW/lib/gcc/mingw32/6.3.0/include/c++/bits/algorithmfwd.h"
using namespace std;

class Solution {
private:
    // Variable to store the minimum unfairness value, initialized to the maximum possible integer value
    int result = INT_MAX;
    
    // Variable to store the length of the 'cookies' vector
    int n;

    // Recursive helper function to distribute cookies among children and minimize unfairness
    void solve(int index, vector<int>& cookies, vector<int> &children, int k) {

        // Base case: if all cookies are distributed, calculate the unfairness and update the result
        if (index >= n) {

            // Calculate the unfairness as the maximum value in the 'children' vector
            int unfairness = *max_element(begin(children), end(children));
            
            // Update the result with the minimum unfairness value
            result = min(result, unfairness);

            return;
        }

        // Get the current cookie
        int cookie = cookies[index];

        // Try distributing the current cookie to each child and recursively explore possibilities
        for (int i = 0; i < k; i++) {

            // Distribute the current cookie to the i-th child
            children[i] += cookie;
            
            // Recursively call the function with the updated state
            solve(index + 1, cookies, children, k);

            // Backtrack: undo the distribution of the current cookie to explore other possibilities
            children[i] -= cookie;
        }
    }    
public:

    int distributeCookies(vector<int>& cookies, int k) {
        // Set the length of the 'cookies' vector
        n = cookies.size();

        // Vector to keep track of the current number of cookies each child has
        vector<int> children(k, 0);

        // Start the recursive backtracking process
        solve(0, cookies, children, k);

        // Return the final result
        return result;
    }
};

//Time complexity : O(k^n)
//Space complexity : O(k) 