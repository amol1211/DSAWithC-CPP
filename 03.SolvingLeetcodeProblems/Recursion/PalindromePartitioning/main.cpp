//131. Palindrome Partitioning

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. Backtracking approach

class Solution {
private:
    // Variable to store the length of the input string
    int n;

    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string &s, int l, int r) {
        // Check if the characters at the given indices are equal
        while (l < r) {
            if (s[l] != s[r]) 
                return false;
            // Move towards the center of the substring
            l++;
            r--;     
        }
        // If the loop completes, the substring is a palindrome
        return true;
    } 

    // Backtracking function to find all possible palindromic partitions
    void backtrack(string &s, int index, vector<string> curr, vector<vector<string>> &result) {
        // If we have reached the end of the string, add the current partition to the result
        if (index == n) {
            result.push_back(curr);
            return;
        }

        // Explore all possible partitions starting from the current index
        for (int i = index; i < n; i++) {
            // If the substring is a palindrome, add it to the current partition
            if (isPalindrome(s, index, i)) {
                curr.push_back(s.substr(index, i - index + 1));
                // Recursively move to the next index
                backtrack(s, i + 1, curr, result);
                // Backtrack: remove the last added substring to explore other possibilities
                curr.pop_back();
            }
        }
    } 

public:
    // Main function to get all palindromic partitions of a string
    vector<vector<string>> partition(string s) {
        // Initialize the length of the string
        n = s.length();
        // Vector to store the final result
        vector<vector<string>> result;
        // Vector to store the current partition during the backtracking process
        vector<string> curr;

        // Start the backtracking process from the beginning of the string
        backtrack(s, 0, curr, result);

        // Return the final result containing all palindromic partitions
        return result;
    }
};


//Time complexity is exponential, O(2^n), where n is the length of the input string. 
//Space complexity : O(n)