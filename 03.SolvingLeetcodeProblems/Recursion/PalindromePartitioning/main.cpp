//131. Palindrome Partitioning

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. Backtracking approach

class Solution {
private:
    // Declare a variable to store the length of the input string
    int n;

    // Function to check if a substring is a palindrome
    bool isPalindrome(string &s, int l, int r) {
        // Check if the substring is a palindrome using two pointers
        while (l < r) {
            if (s[l] != s[r]) 
                return false;
            l++;
            r--;     
        }
        // Return true if the substring is a palindrome
        return true;
    } 

    // Backtracking function to generate all possible palindrome partitions
    void backtrack(string &s, int index, vector<string> curr, vector<vector<string>> &result) {
        // If we have reached the end of the string, add the current partition to the result
        if (index == n) {
            result.push_back(curr);
            return;
        }

        // Iterate through the string and generate partitions
        for (int i = index; i < n; i++) {
            // If the substring from index to i is a palindrome
            if (isPalindrome(s, index, i)) {
                // Add the palindrome substring to the current partition
                curr.push_back(s.substr(index, i - index + 1));
                // Recursively generate partitions for the remaining substring
                backtrack(s, i + 1, curr, result);
                // Backtrack: Remove the last added substring for the next iteration
                curr.pop_back();
            }
        }
    } 

public:
    // Main function to generate all possible palindrome partitions for the input string
    vector<vector<string>> partition(string s) {
        // Set the length of the input string
        n = s.length();
        // Initialize vectors to store the result and the current partition
        vector<vector<string>> result;
        vector<string> curr;

        // Start backtracking from index 0
        backtrack(s, 0, curr, result);

        // Return the final result containing all palindrome partitions
        return result;
    }
};

//Time complexity is exponential, O(2^n), where n is the length of the input string. 
//Space complexity : O(n)