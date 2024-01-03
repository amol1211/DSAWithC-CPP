//14. Longest Common Prefix

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

//Appraoch 1 :  Sorting and Comparing First and Last Strings

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Get the number of strings in the vector
        int n = strs.size();
        // If the vector is empty, return an empty string
        if (n == 0) return "";

        // Initialize the result string
        string ans = "";

        // Sort the strings in lexicographical order
        sort(begin(strs), end(strs));

        // Get the first and last strings after sorting
        string a = strs[0];
        string b = strs[n - 1];

        // Iterate through the characters of the first string
        for (int i = 0; i < a.size(); i++) {
            // If the character matches in both first and last strings, add it to the result
            if (a[i] == b[i]) {
                ans = ans + a[i];
            } else {
                // If a mismatch is found, break the loop
                break;
            }
        }

        // Return the longest common prefix
        return ans;
    }
};

/*Time Complexity:

The time complexity is dominated by the sorting step, which is O(m * n * log(n)), 
where m is the average length of the strings and n is the number of strings. 
The comparison of characters in the loop is O(m).

Space Complexity:

The space complexity is O(1) as the algorithm uses only a constant amount of space, 
excluding the input and output. */

/*------------------------------------------------------------------------------------*/

// Approach 2 :  Horizontal Scanning, where we take first strings and compare 
//it's ch with rest of the strings

class Solution {
public:
    // Function to find the longest common prefix among a vector of strings
    string longestCommonPrefix(vector<string>& strs) {
        // Initialize an empty string to store the result
        string ans = "";

        // Iterate through the characters of the first string
        for (int i = 0; i < strs[0].length(); i++) {
            // Get the character at the current position in the first string
            char ch = strs[0][i];

            // Assume there is a match for the current character
            bool match = true;

            // Compare the current character with the corresponding character in the rest of the strings
            for (int j = 1; j < strs.size(); j++) {
                // Check if the current string is shorter than the index or if characters don't match
                if (strs[j].size() < i  || ch != strs[j][i]) {
                    // If there is no match, set the match flag to false and break the loop
                    match = false;
                    break;
                }
            }

            // If there was a match for the current character in all strings, add it to the result
            if (match == false)
                break;
            else 
                ans.push_back(ch);    
        }

        // Return the longest common prefix
        return ans;
    }
};

/*Time Complexity:

O(m * n), where m is the average length of the strings and n is the number of strings. 

Space Complexity:

O(1), as the algorithm uses only a constant amount of space, excluding the input and output.*/

/*----------------------------------------------------------------------------------------------------------*/

//Approach 3 : Trie-based Approach

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        // Initialize TrieNode with a character
        data = ch;
        // Initialize children array to null
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        // Initialize childCount and isTerminal
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        // Initialize Trie with an empty root node
        root = new TrieNode('\0');
    }

    // Recursive utility function to insert a word into the Trie
    void insertUtil(TrieNode* root, string word) {
        // Base case: if the word is empty, mark the current node as terminal
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Get the index corresponding to the current character
        int index = word[0] - 'a'; 
        TrieNode* child;

        // Check if the child node already exists
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            // If not, create a new child node
            child = new TrieNode(word[0]);
            // Increment childCount and link the child node
            root->childCount++;
            root->children[index] = child;
        }

        // Recursively insert the rest of the word
        insertUtil(child, word.substr(1));
    }

    // Public function to insert a word into the Trie
    void insertWord(string word) {
        insertUtil(root, word);
    }

    // Function to find the longest common prefix using the Trie
    void lcp(string str, string &ans) {
        // Traverse the Trie until a mismatch or the end of the common prefix
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            // If only one child, add the character to the result and move to the child
            if (root->childCount == 1 && !root->isTerminal) {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            } else {
                // If multiple children or the current node is a terminal node, break the loop
                break;
            }

            // If the current node is a terminal node, break the loop
            if (root->isTerminal)
                break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Create a Trie
        Trie *t = new Trie();

        // Insert each word into the Trie
        for (int i = 0; i < strs.size(); i++) {
            t->insertWord(strs[i]);
        }

        // Get the first string
        string first = strs[0];
        // Initialize the result string
        string ans = "";

        // Find the longest common prefix using the Trie
        t->lcp(first, ans);
        return ans;
    }
};

/*Time Complexity:

Building the Trie: O(m * n), where m is the average length of the strings 
and n is the number of strings. Finding the Longest Common Prefix: O(m), 
where m is the length of the first string.

Space Complexity:

Trie: O(m * n), where m is the average length of the strings and n is the 
number of strings. Each node in the Trie corresponds to a character in the strings.*/