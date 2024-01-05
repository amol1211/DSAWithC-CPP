//Shortest Unique prefix for every word (GFG)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Node structure for Trie
class TrieNode {
public:
    char data;               // Character stored in the node
    TrieNode* children[26];  // Array to store children nodes for each alphabet
    int count;               // Count of how many times the node is encountered during insertion

    TrieNode(char ch) {
        data = ch;
        count = 1;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;  // Initialize children to null
        }
    }
};

// Trie data structure
class Trie {
public:
    TrieNode* root;  // Root node of the Trie

    Trie() {
        root = new TrieNode('\0');  // Initialize the Trie with an empty character
    }

    // Function to insert a word into the Trie
    void insertWord(string word) {
        TrieNode* current = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode(ch);  // Create a new node if it doesn't exist
            } else {
                current->children[index]->count++;  // Increment count if the node already exists
            }
            current = current->children[index];
        }
    }

    // Function to find the shortest unique prefix for a given word
    string findPrefix(string word) {
        TrieNode* current = root;
        string prefix = "";

        for (char ch : word) {
            int index = ch - 'a';
            prefix.push_back(ch);

            // Check if the prefix is unique by examining the count at each node
            if (current->children[index]->count == 1) {
                break;
            }
            current = current->children[index];
        }

        return prefix;
    }
};

// Main class
class Solution {
public:
    // Function to find the shortest unique prefix for each word in the array
    vector<string> findPrefixes(string arr[], int n) {
        Trie trie;  // Create a Trie instance
        vector<string> result;  // Vector to store the result

        // Insert all words into the Trie
        for (int i = 0; i < n; i++) {
            trie.insertWord(arr[i]);
        }

        // Find the shortest unique prefix for each word
        for (int i = 0; i < n; i++) {
            string prefix = trie.findPrefix(arr[i]);
            result.push_back(prefix);
        }

        return result;
    }
};

// Time Complexity: O(N * length of each word)
// Space Complexity: O(N * length of each word)

