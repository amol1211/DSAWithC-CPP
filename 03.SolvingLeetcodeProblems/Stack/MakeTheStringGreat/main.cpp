//1544. Make The String Great

#include <bits/stdc++.h>
using namespace std;

// This function takes a string as input and removes adjacent characters that are the same letter but different cases.
// It iterates through the string, checking each character against the last character in the result string.
// If the characters are the same letter but different cases (e.g., 'a' and 'A'), it removes both from the result string.
// Otherwise, it appends the character to the result string.
// Time Complexity: O(n) where n is the length of the input string.
// Space Complexity: O(n) for the result string.

//Appraoch 1 : Adjacent Character Elimination Approach

class Solution {
public:
    string makeGood(string s) {
        string result = ""; // Initialize an empty string to store the result

        // Iterate through each character in the input string
        for (char &ch : s) {
            // If the result is not empty and the current character matches the last character of the result in different cases
            if (!result.empty() && (result.back() + 32 == ch || result.back() - 32 == ch)) {
                result.pop_back(); // Remove the last character from the result
            }
            else {
                result.push_back(ch); // Append the current character to the result
            }
        }

        return result; // Return the final result string
    }
};

/***********************-------------------------------------------------------*/

// This function takes a string as input and removes adjacent characters that are the same letter but different cases.
// It uses a stack to keep track of characters to be included in the result.
// It iterates through the input string, pushing characters onto the stack if they don't form pairs with the top of the stack.
// If the current character forms a pair with the top of the stack (i.e., they are the same letter but different cases), the character at the top of the stack is removed.
// After processing the input string, the function constructs the result string by popping characters from the stack.
// Time Complexity: O(n) where n is the length of the input string.
// Space Complexity: O(n) for the stack and the result string.

// Approach 2 : Stack based approach

class Solution {
public:
    string makeGood(string s) {
        stack<char> stack; // Initialize a stack to store characters to be included in the result

        // Iterate through each character in the input string
        for (char c : s) {
            // If the stack is not empty and the current character forms a pair with the top of the stack
            if (!stack.empty() && std::abs(c - stack.top()) == 32) {
                stack.pop(); // Remove the character at the top of the stack
            } else {
                stack.push(c); // Push the current character onto the stack
            }
        }

        string result; // Initialize an empty string to store the result

        // Construct the result string by popping characters from the stack
        while (!stack.empty()) {
            result = stack.top() + result; // Append the character at the top of the stack to the result string
            stack.pop(); // Remove the character from the stack
        }

        return result; // Return the final result string
    }
};
