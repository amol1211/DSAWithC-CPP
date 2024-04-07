//1249. Minimum Remove to Make Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : Stack-based Approach

// This approach uses a stack to keep track of the indices of open brackets.
// It iterates through the string, pushing the index of open brackets onto the stack.
// If a closing bracket is encountered and the stack is empty, it means there's no matching opening bracket, so the closing bracket is marked for removal.
// After iterating through the string, any remaining open brackets in the stack are marked for removal.
// Then, it constructs the resulting string by skipping characters marked for removal.
// Time Complexity: O(n) where n is the length of the input string.
// Space Complexity: O(n) for the stack and unordered_set.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st; // Stack to keep track of indices of open brackets
        unordered_set<int> removeIndex; // Set to store indices of brackets to be removed

        // Iterating through the string
        for (int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i); // Push index of open bracket onto the stack
            } else if (s[i] == ')') {
                if(st.empty()) {
                    removeIndex.insert(i); // Mark index of closing bracket for removal
                } else {
                    st.pop(); // Match found, pop the corresponding open bracket index
                }
            }
        }
        
        // Handling remaining open brackets
        while (!st.empty()) {
            removeIndex.insert(st.top()); // Mark indices of remaining open brackets for removal
            st.pop();
        }

        // Constructing the resulting string
        string result = "";
        for (int i = 0; i < n; i++) {
            if (removeIndex.find(i) == removeIndex.end()) {
                result.push_back(s[i]); // Include characters not marked for removal
            }
        }

        return result;
    }
};

/*------------------------------------------------------------------*/

//Approach 2 : Two-Pass Approach with Reversal

// This approach iterates through the string from left to right.
// It keeps track of the number of open brackets encountered.
// If it encounters a closing bracket and there are open brackets available to match it, it includes the closing bracket in the result.
// After processing from left to right, it reverses the resulting string and iterates from right to left.
// It keeps track of the number of close brackets encountered.
// If it encounters an open bracket and there are close brackets available to match it, it includes the open bracket in the final result.
// Finally, it reverses the final result to obtain the correct order.
// Time Complexity: O(n) where n is the length of the input string.
// Space Complexity: O(n) for the resulting string.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        string result = "";

        int openBrackets = 0;
        // Iterating from left to right
        for (int i = 0; i < n; i++) {
            // Handling characters and brackets
            if (s[i] >= 'a' && s[i] <= 'z') {
                result.push_back(s[i]);
            } else if(s[i] == '(') {
                openBrackets++;
                result.push_back(s[i]);
            } else if (openBrackets > 0) {
                openBrackets--;
                result.push_back(s[i]);
            }
        }

        // Reversing the result and iterating from right to left
        string finalResult = "";
        int closeBrackets = 0;
        for (int i = result.length() - 1; i >= 0; i--) {
            if (result[i] >= 'a' && result[i] <= 'z') {
                finalResult.push_back(result[i]);
            } else if (result[i] == ')') {
                closeBrackets++;
                finalResult.push_back(result[i]);
            } else if (closeBrackets > 0) {
                closeBrackets--;
                finalResult.push_back(result[i]);
            }
        }
        
        reverse(finalResult.begin(), finalResult.end()); // Reversing the final result to obtain the correct order
        return finalResult;
    }
};

/*---------------------------------------------------------------------*/

//Approach 3 : Simplified Two-Pass Approach with Reversal

// This approach is similar to the previous one but simplified.
// It iterates through the string from left to right.
// It keeps track of the number of open brackets encountered.
// If it encounters a closing bracket and there are open brackets available to match it, it includes the closing bracket in the result.
// After processing from left to right, it iterates from right to left.
// If it encounters an open bracket and there are close brackets available to match it, it decrements the count of open brackets.
// Otherwise, it includes the open bracket in the final result.
// Finally, it reverses the final result to obtain the correct order.
// Time Complexity: O(n) where n is the length of the input string.
// Space Complexity: O(n) for the resulting string.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        string result = "";

        int openBrackets = 0;
        // Iterating from left to right
        for (int i = 0; i < n; i++) {
            // Handling characters and brackets
            if (s[i] >= 'a' && s[i] <= 'z') {
                result.push_back(s[i]);
            } else if(s[i] == '(') {
                openBrackets++;
                result.push_back(s[i]);
            } else if (s[i] == ')') {
                if (openBrackets > 0) {
                    openBrackets--;
                    result.push_back(s[i]);
                }
            }
        }

        // Iterating from right to left
        string finalResult = "";
        for (int i = result.length() - 1; i >= 0; i--) {
            if (result[i] == '(' && openBrackets > 0) {
                openBrackets--;
            } else {
                finalResult.push_back(result[i]); // Including characters not marked for removal
            }
        }
        
        reverse(finalResult.begin(), finalResult.end()); // Reversing the final result to obtain the correct order
        return finalResult;
    }
};
