//17. Letter Combinations of a Phone Number

#include <iostream>
#include <vector>
using namespace std;

// 1. Brute force iterative approach

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Result vector to store letter combinations
        vector<string> result;

        // Check if the input string is empty
        if(digits.empty()) {
            return result;
        }

        // Mapping of digits to corresponding letters
        vector<string> digitToLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // Initialize the result with an empty string
        result.push_back("");

        // Iterate through each digit in the input string
        for(char digit : digits) {
            // Convert the character digit to an integer
            int num = digit - '0';

            // Temporary vector to store new combinations
            vector<string> temp;

            // Iterate through existing combinations and append each possible letter for the current digit
            for(const string& existing : result) {
                for(char letter : digitToLetters[num]) {
                    temp.push_back(existing + letter);
                }
            }

            // Update the result with the new combinations
            result = temp;
        }

        // Return the final result vector containing all letter combinations
        return result;
    }
};

/*Time Complexity: The time complexity of this solution is O(4^n), where n is the length of the 
input digits. This is because, for each digit, there are at most 4 letters (in the case of digits 7 and 9) 
that can be combined, and this process is repeated for each digit.

Space Complexity: The space complexity is also O(4^n) as we are storing all possible combinations 
in the result vector. The space required grows exponentially with the length of the input digits.*/

/*-----------------------------------------------------------------------------------------------------------*/

class Solution {
private:
    // Recursive function to generate letter combinations
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[]) {
        // Base case: If the index exceeds or equals the length of the input digits
        if (index >= digit.length()) {
            ans.push_back(output);  // Add the current combination to the result vector
            return;
        }

        // Get the numeric value of the current digit
        int number = digit[index] - '0';

        // Get the corresponding letters for the current digit
        string value = mapping[number];

        // Iterate through the letters and generate combinations
        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);  // Append the current letter to the output string
            solve(digit, output, index + 1, ans, mapping);  // Recursively call the function for the next digit
            output.pop_back();  // Backtrack: remove the last letter to explore other possibilities
        }
    }
        
public:
    // Main function to get letter combinations
    vector<string> letterCombinations(string digits) {
        // Result vector to store letter combinations
        vector<string> ans;

        // Check if the input string is empty
        if (digits.length() == 0)
           return ans;

        // Initializations
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // Call the recursive function to generate combinations
        solve(digits, output, index, ans, mapping);

        // Return the final result vector containing all letter combinations
        return ans;   
    }
};

//Time complexity : O(4^n)
//Space complexity : O(n)

