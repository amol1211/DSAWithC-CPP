//720. Longest Word in Dictionary

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Define a Solution class
class Solution {
    // Define a TrieNode class for the Trie
    class TrieNode {
    public:
        TrieNode* children[26]; // Array to store pointers to child nodes for each letter
        bool isTerminal; // Flag indicating if the node represents the end of a word

        // Constructor to initialize the TrieNode
        TrieNode() {
            // Initialize the children array with nullptr and isTerminal to false
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isTerminal = false;
        }
    };

    // Define a Trie class
    class Trie {
    public:
        Trie() {
            root = new TrieNode(); // Initialize the Trie with a root node
        }

        // Function to insert a word into the Trie
        void insert(string& word) { 
            TrieNode* current = root; // Start at the root of the Trie
            for (char ch : word) {
                int index = ch - 'a'; // Calculate the index for the current letter
                if (current->children[index] == nullptr) {
                    current->children[index] = new TrieNode(); // Create a new node if it doesn't exist
                }
                current = current->children[index]; // Move to the next node
            }
            current->isTerminal = true; // Mark the last node as the end of a word
        }

        // Function to search for a word in the Trie
        bool search(const string& word) {
            TrieNode* current = root; // Start at the root of the Trie
            for (char ch : word) {
                int index = ch - 'a'; // Calculate the index for the current letter
                if (current->children[index] == nullptr || current->children[index]->isTerminal == false) {
                    return false; // Return false if the path doesn't exist or doesn't end with a complete word
                }
                current = current->children[index]; // Move to the next node
            }
            return true; // Return true if the entire word is found in the Trie
        }

    private:
        TrieNode* root; // Pointer to the root of the Trie
    };

public:
    // Function to find the longest word in the given list that can be built one character at a time by other words in the list
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end()); // Sort the words lexicographically
        Trie trie; // Create a Trie
        string result = ""; // Initialize the result string

        // Iterate through each word in the sorted list
        for (const string& word : words) {
            // Check if the word has length 1 or its prefix (excluding the last character) is present in the Trie
            if (word.length() == 1 || trie.search(word.substr(0, word.length() - 1))) {
                trie.insert(const_cast<string&>(word)); // Insert the word into the Trie
                if (word.length() > result.length()) {
                    result = word; // Update the result if the current word is longer
                }
            }
        }

        return result; // Return the longest word
    }
};

/*Time Complexity: O(N * M * log(M)), where N is the number of words and M is the maximum length of a word. 
The sorting step dominates the complexity.

Space Complexity: O(N * M), where N is the number of words and M is the maximum length of a word. The space 
complexity is determined by the Trie data structure.*/