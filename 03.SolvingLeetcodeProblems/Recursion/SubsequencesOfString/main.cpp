//Subsequences of String (Coding ninja)
#include <bits/stdc++.h>

using namespace std;

// Helper function to generate subsequences recursively
void solve(string str, string output, int index, vector<string> &ans) {
    // Base case: If index is beyond the length of 'str', add the current 'output' to 'ans' and return
    if (index == str.length()) {
        if (output.length() > 0) {
            //If we don't want to add empty string as subsequence
            ans.push_back(output);
        }
        return;
    }

    // Exclude the current character at 'index'
    solve(str, output, index + 1, ans);

    // Include the current character at 'index'
    char element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, ans);

    // Note: In the original code, there was a missing return statement here.
}

// Function to generate all subsequences and return the result
vector<string> subsequences(string str) {
    // Result vector to store all subsequences
    vector<string> ans;
    // Initial output string (empty)
    string output = "";
    // Start the recursive process from index 0
    int index = 0;
    solve(str, output, index, ans);

    // Return the final result containing all subsequences
    return ans;
}

//Time complexity : O(2^N)
//Space complexity : O(2^N)