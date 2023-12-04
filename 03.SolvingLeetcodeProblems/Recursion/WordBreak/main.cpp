//139. Word Break

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_set>
using namespace std;

class Solution {
private: 
    // Set to store words for quick lookup
    unordered_set<string> st;
    
    // Length of the input string
    int n;
    
    // Memoization array to store intermediate results
    int t[301];

    // Recursive helper function to check if a string can be broken into words
    bool solve(int index, string &s) {

        // Base case: if we have reached the end of the string, it's a valid break
        if (index >= n) return true;
        
        // Check if the result for this index is already calculated
        if (t[index] != -1)
            return t[index];

        // Check if the substring from the current index is in the word set
        if (st.find(s) != st.end())
            return true;

        // Iterate over possible lengths of words starting from the current index
        for (int l = 1; l <= n; l++) {
            // Extract the substring
            string temp = s.substr(index, l);
            
            // If the substring is in the word set and the rest of the string can be broken,
            // mark this index as true and return true
            if (st.find(temp) != st.end() && solve(index + l, s)) {
                return t[index] = true;
            }
        }
        // Mark this index as false if no valid break is found
        return t[index] = false;    
    }    

public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        // Set the length of the input string
        n = s.length();
        
        // Initialize the memoization array with -1
        memset(t, -1, sizeof(t));
        
        // Populate the set with words from the dictionary for quick lookup
        for (string &word : wordDict) {
            st.insert(word);
        }

        // Call the recursive helper function starting from index 0
        return solve(0, s);
    }
};

//Time complexity : O(2^n)
//Space complexity : O(n) due to the memoization array t, which is used to store intermediate 
//results and avoid redundant calculations.