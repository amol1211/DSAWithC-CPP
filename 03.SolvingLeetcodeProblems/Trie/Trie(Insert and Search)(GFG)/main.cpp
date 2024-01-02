//GFG Trie | (Insert and Search)

#include <iostream>
#include <string>
using namespace std;

// trie node

struct TrieNode {
    struct TrieNode *children[26];
    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};


// Function to create a new TrieNode(Constructor)
struct TrieNode* getNode() {
    struct TrieNode* newNode = new TrieNode;
    newNode->isLeaf = false;
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = nullptr;
    }
    return newNode;
}



// Function to insert string into TRIE.
void insert(struct TrieNode *root, string key) {
    // Base case: if the key is empty, mark the current node as a leaf node
    if (key.length() == 0) {
        root->isLeaf = true;
        return;
    }

    // Calculate the index for the current character in the key
    int index = key[0] - 'a';
    struct TrieNode* child;

    // Check if the child node for the current character is already present
    if (root->children[index] != nullptr) {
        // If present, use the existing node
        child = root->children[index];
    } else {
        // If absent, create a new node and link it to the current node
        child = getNode();
        root->children[index] = child;
    }

    // Recursively insert the rest of the key into the Trie
    insert(child, key.substr(1));
}

// Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) {
    // Base case: if the key is empty, check if the current node is marked as a leaf
    if (key.length() == 0) {
        return root->isLeaf;
    }

    // Calculate the index for the current character in the key
    int index = key[0] - 'a';
    struct TrieNode* child;

    // Check if the child node for the current character is present
    if (root->children[index] != nullptr) {
        // If present, use the existing node
        child = root->children[index];
    } else {
        // If absent, the key is not present in the Trie
        return false;
    }

    // Recursively search the rest of the key in the Trie
    return search(child, key.substr(1));
}

/*Time Complexity:

The time complexity for both insert and search operations is O(L), 
where L is the length of the input string. This is because in each step, 
we are processing one character of the string.

Space Complexity:

The space complexity is O(ALPHABET_SIZE * L * N), where ALPHABET_SIZE is 
the size of the alphabet (26 for lowercase English letters), L is the average 
length of the strings, and N is the number of strings inserted into the Trie. 
This complexity arises from the space required to store the Trie nodes.*/