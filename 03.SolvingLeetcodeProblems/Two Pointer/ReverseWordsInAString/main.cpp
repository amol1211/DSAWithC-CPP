// 151. Reverse Words in a String
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Approach 1: Tokenization and Reversal using stringstream utility

class Solution {
public:
    // Function to reverse the order of words in a string
    string reverseWords(string s) {
        // Create a stringstream to tokenize the input string
        stringstream ss(s);
        string token = "";

        // Initialize an empty string to store the result
        string result = "";

        // Tokenize the string by space and reverse the order of tokens
        while (ss >> token) {
            result = token + " " + result;
        }

        // Remove the trailing space and return the result
        return result.substr(0, result.length() - 1);
    }
};

/*Time Complexity: O(n), where n is the length of the input string. The stringstream tokenization 
and reversal are both linear operations.

Space Complexity: O(n), where n is the length of the input string. The space complexity is 
dominated by the storage of the result string.*/

/*-----------------------------------------------------------------------------------------------------*/

//Approach 2: In-Place Word Reversal

class Solution {
public:
    // Function to reverse the order of words in a string
    string reverseWords(string s) {
        // Reverse the entire string
        reverse(s.begin(), s.end());

        // Initialize indices for word reversal
        int i = 0;
        int l = 0, r = 0;
        int n = s.length();

        // Traverse the string and reverse each word
        while (i < n) {
            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }
            if (l < r) {
                // Reverse the word between indices l and r
                reverse(s.begin() + l, s.begin() + r);

                // Add a space after the reversed word
                s[r] = ' ';
                r++;

                // Update the left index to the next word
                l = r;
            }
            i++;
        }

        // Remove the trailing space and return the result
        s = s.substr(0, r - 1);
        return s;
    }
};

/*Time Complexity: O(n), where n is the length of the input string. The algorithm traverses the string once, 
and the reversal of words is also linear.

Space Complexity: O(1). The algorithm uses a constant amount of extra space, and the space 
complexity does not depend on the input size.*/