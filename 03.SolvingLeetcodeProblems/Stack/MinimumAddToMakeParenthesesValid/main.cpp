// 921. Minimum Add to Make Parentheses Valid

#include <iostream>
#include <stack>
using namespace std;

// Approach 1 : Brute force
class Solution {
    int minAddToMakeValid(string s) {

        int openCount = 0;  // Count of open parentheses encountered
        int closeCount = 0; // Count of closing parentheses without a match

        for (char c : s) {
            if (c == '(') {
                openCount++; // Increment open count for each open parenthesis
            }
            else {
                if (openCount > 0) {
                    openCount--; // Match a closing parenthesis with an open one
                } 
                else {
                    closeCount++; // No matching open parenthesis, so increment close count
                }
            }
        }

        // The result is the sum of remaining open and unmatched close parentheses
        return openCount + closeCount;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(1)

/*-------------------------------------------------------------------------------------------------*/

//Approach 2 : 

int minAddToMakeValid(string s) {
    stack<char> st; // Use a stack to keep track of open parentheses
    int extraOpen = 0; // Count of open parentheses needed

    for (char c : s) {
        if (c == '(') {
            st.push(c); // Push open parenthesis onto the stack
        } else {
            if (!st.empty() && st.top() == '(') {
                st.pop(); // Match a closing parenthesis with an open one
            } else {
                extraOpen++; // No matching open parenthesis, so increment count
            }
        }
    }

    // The result is the sum of unmatched open parentheses and remaining elements in the stack
    return extraOpen + st.size();
}

//Time Complexity: O(N)
//Space Complexity: O(N)