// Implement Trie (Coding NINJA)

#include <iostream>
#include <cstring>
using namespace std;
// TrieNode class represents a node in the Trie.
class TrieNode {
public:
    char data;               // The character stored in the node.
    TrieNode* children[26];  // Array to store children nodes for each alphabet.
    bool isTerminal;         // Flag indicating if the node represents the end of a word.

    // Constructor to initialize the TrieNode.
    TrieNode(char ch) {
        this->data = ch;
        this->isTerminal = false;

        // Initialize children array with nullptr.
        for (int i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
    }
};

// Trie class represents a Trie data structure.
class Trie {
    TrieNode* root;  // Root of the Trie.

public:
    // Constructor to initialize the Trie.
    Trie() {
        root = new TrieNode('\0');  // '\0' represents the root node.
    }

    // Utility function to insert a word into the Trie.
    void insertUtil(TrieNode* root, string word) {
        // Base case: If the word is empty, mark the current node as a terminal node.
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assumption: Words are in uppercase. Calculate the index for the current character.
        int index = word[0] - 'A';
        TrieNode* child;

        // If the current character's node is already present, use it. Otherwise, create a new node.
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursively insert the remaining characters.
        insertUtil(child, word.substr(1));
    }

    // Function to insert a word into the Trie.
    void insert(string word) {
        insertUtil(root, word);
    }

    // Utility function to search for a word in the Trie.
    bool searchUtil(TrieNode* root, string word) {
        // Base case: If the word is empty, check if the current node is a terminal node.
        if (word.length() == 0) {
            return root->isTerminal;
        }

        // Calculate the index for the current character.
        int index = word[0] - 'A';
        TrieNode* child;

        // If the current character's node is present, use it. Otherwise, the word is not in the Trie.
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }

        // Recursively search for the remaining characters.
        return searchUtil(child, word.substr(1));
    }

    // Function to check if a word is present in the Trie.
    bool search(string word) {
        return searchUtil(root, word);
    }

    // Utility function to check if there is any word in the Trie that starts with the given prefix.
    bool prefixUtil(TrieNode* root, string word) {
        // Base case: If the prefix is empty, return true.
        if (word.length() == 0) {
            return true;
        }

        // Calculate the index for the current character.
        int index = word[0] - 'A';
        TrieNode* child;

        // If the current character's node is present, use it. Otherwise, there is no word with the prefix.
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }

        // Recursively check the remaining characters in the prefix.
        return prefixUtil(child, word.substr(1));
    }

    // Function to check if there is any word in the Trie that starts with the given prefix.
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};


/*Time Complexity:

The time complexity for each operation (insert, search, startsWith) is O(L), 
where L is the length of the input word or prefix.

Space Complexity:

The space complexity is O(N * M), where N is the number of words inserted into 
the Trie, and M is the average length of the words. This complexity arises from 
the space required to store the Trie nodes.*/