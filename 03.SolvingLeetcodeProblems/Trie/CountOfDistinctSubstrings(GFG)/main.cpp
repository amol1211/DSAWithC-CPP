//Count of distinct substrings (GFG)
#include <iostream>
#include <string>
using namespace std;

// TrieNode class representing each node in the trie
class TrieNode {
public:
    TrieNode* children[26];  // Array to represent child nodes for each character
    bool isTerminal;         // Flag to indicate whether a node marks the end of a substring

    // Constructor to initialize the node
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

// Function to insert suffixes of a string into the trie
void insertSuffixes(TrieNode* root, const string& s) {
    TrieNode* current = root;

    // Iterate through each character in the suffix
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';

        // If the child node for the character doesn't exist, create a new node
        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }
        // Move to the child node
        current = current->children[index];
        // Mark the node as the end of a substring
        current->isTerminal = true;
    }
}

// Function to count distinct nodes in the trie
int countDistinctNodes(TrieNode* root) {
    int result = 0;

    // If the current node marks the end of a substring, increment the result
    if (root->isTerminal) {
        result += 1;
    }

    // Recursively count distinct nodes for each child node
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != nullptr) {
            result += countDistinctNodes(root->children[i]);
        }
    }

    return result;
}

// Main function to count distinct substrings of a given string using a trie
int countDistinctSubstring(string s) {
    TrieNode* root = new TrieNode();

    // Include the empty string as a distinct substring
    root->isTerminal = true;

    // Insert all suffixes of the string into the trie
    for (int i = 0; i < s.length(); i++) {
        insertSuffixes(root, s.substr(i));
    }

    // Count distinct substrings using the trie
    int result = countDistinctNodes(root);

    return result;
}

/*
Time Complexity:

The time complexity for creating the trie (inserting suffixes) is O(N^2), where N is the length 
of the input string.The time complexity for counting distinct nodes in the trie is O(N^2) as well.

Space Complexity:

The space complexity is O(N^2) due to the storage of each character in the trie. This is because, 
in the worst case, each character in the input string may lead to creating a new node in the trie.
*/

/*---------------------------------------------------------------------------------------------------*/

// Appraoch 2 :

// TrieNode class representing each node in the trie
class TrieNode {
public:
    TrieNode* children[26];  // Array to represent child nodes for each character
    bool isTerminal;         // Flag to indicate whether a node marks the end of a substring

    // Constructor to initialize the node
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

// Function to insert suffixes of a string into the trie and count distinct substrings
void insertSuffixes(TrieNode* root, const string& s, int& result) {
    TrieNode* current = root;

    // Iterate through each character in the suffix
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';

        // If the child node for the character doesn't exist, create a new node
        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
            result++;  // Increment result only when a new node is created
        }

        // Move to the child node
        current = current->children[index];

        // Mark the node as the end of a substring
        current->isTerminal = true;
    }
}

// Main function to count distinct substrings of a given string using a trie
int countDistinctSubstring(const string& s) {
    TrieNode* root = new TrieNode();
    int result = 1;  // Include the empty string

    // Insert all suffixes of the string into the trie and count distinct substrings
    for (int i = 0; i < s.length(); i++) {
        insertSuffixes(root, s.substr(i), result);
    }

    // Clean up the trie
    delete root;

    return result;
}

/*
Time Complexity:

The time complexity is O(N), where N is the length of the input string. This is because we process 
each character of the string only once during the insertion of suffixes.

Space Complexity:

The space complexity is O(N), where N is the length of the input string. This is due to the storage 
of each character in the trie. The trie is created and deleted within the countDistinctSubstring function.
*/