//1047. Remove All Adjacent Duplicates In String

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 1. Brute force appraoch

class Solution {
public:
    string removeDuplicates(string s) {
        string ans; // Initialize an empty string to store the result

        for (char c : s) { // Loop through the input string
            if (!ans.empty() && ans.back() == c) { // Check if the result string is not empty and the last character is the same as the current character
                ans.pop_back(); // Remove the last character from the result string
            } else {
                ans.push_back(c); // Append the current character to the result string
            }
        }

        return ans; // Return the result string
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*--------------------------------------------------------------------------*/

// 2. Stack approach

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st; // Initialize a stack to store characters

        for (char c : s) { // Loop through each character in the input string
            if (!st.empty() && st.top() == c) { // If the stack is not empty and the current character is the same as the character at the top of the stack (i.e., it's a duplicate)
                st.pop(); // Remove the character from the stack to eliminate the duplicate
            } else {
                st.push(c); // Push the current character onto the stack
            }
        }

        string ans = ""; // Initialize an empty string to store the result

        while (!st.empty()) { // While the stack is not empty
            ans = st.top() + ans; // Prepend the character at the top of the stack to the result string (this maintains the order of non-duplicate characters)
            st.pop(); // Remove the character from the stack
        }

        return ans; // Return the result string with duplicates removed
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*-----------------------------------------------------------------*/

//Different variant of stack approach

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length(); // Get the length of the input string
        stack<char> st; // Initialize a stack to store characters
        string ans = ""; // Initialize an empty string to store the result

        for (int i = 0; i < n; i++) { // Loop through the input string
            if (st.empty() || st.top() != s[i]) { // If the stack is empty or the current character is different from the character at the top of the stack (not a duplicate)
                st.push(s[i]); // Push the current character onto the stack
            }
            else { // If the current character is the same as the character at the top of the stack (a duplicate)
                st.pop(); // Remove the character from the stack to eliminate the duplicate
            }
        }

        while (!st.empty()) { // While the stack is not empty
            ans.push_back(st.top()); // Append the character at the top of the stack to the result string
            st.pop(); // Remove the character from the stack
        }

        reverse(ans.begin(), ans.end()); // Reverse the result string to maintain the original order
        return ans; // Return the result string with duplicates removed
    }
};

//Time complexity : O(n)
//Space complexity : O(n)