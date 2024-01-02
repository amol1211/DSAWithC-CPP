//208. Implement Trie (Prefix Tree)

#include <iostream>
#include <string>
using namespace std;

//Appraoch 1 : slightly lengthy approach (Trie with Private Helper Functions)

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    // Constructor
    TrieNode(char ch) {
        this->data = ch;
        this->isTerminal = false;
        for (int i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        // Provide a default character for the root node
        root = new TrieNode(' ');
    }

    void insert(string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Call the insert function on the Trie object, not the TrieNode
        insert(child, word.substr(1));
    }

    bool search(string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }

        // Call the search function on the Trie object
        return search(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        if (prefix.length() == 0) {
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }

        // Call the startsWith function on the Trie object
        return startsWith(child, prefix.substr(1));
    }

private:
    void insert(TrieNode* node, string word) {
        // Base case
        if (word.length() == 0) {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (node->children[index] != nullptr) {
            child = node->children[index];
        } else {
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }

        // Call the insert function recursively
        insert(child, word.substr(1));
    }

    bool search(TrieNode* node, string word) {
        if (word.length() == 0) {
            return node->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (node->children[index] != nullptr) {
            child = node->children[index];
        } else {
            return false;
        }

        // Call the search function recursively
        return search(child, word.substr(1));
    }

    bool startsWith(TrieNode* node, string prefix) {
        if (prefix.length() == 0) {
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode* child;

        if (node->children[index] != nullptr) {
            child = node->children[index];
        } else {
            return false;
        }

        // Call the startsWith function recursively
        return startsWith(child, prefix.substr(1));
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << "Search 'apple': " << (obj->search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (obj->search("app") ? "Found" : "Not Found") << endl;
    cout << "StartsWith 'app': " << (obj->startsWith("app") ? "Found" : "Not Found") << endl;

    delete obj; // Don't forget to free memory
    return 0;
}

/*Time Complexity:

Insertion (insert): O(N), where N is the length of the word being inserted.
Search (search): O(N), where N is the length of the word being searched.
Starts with (startsWith): O(N), where N is the length of the prefix.

Space Complexity:

Space complexity for storing the Trie: O(ALPHABET_SIZE * M), where ALPHABET_SIZE 
is the size of the alphabet (26 for lowercase English letters) and M is the total 
number of characters across all words in the Trie.*/

/*--------------------------------------------------------------------------------------------------*/

//Appraoch 2 : Simplified Trie without Private Helper Functions

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    // Constructor
    TrieNode(char ch) : data(ch), isTerminal(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        // Provide a default character for the root node
        root = new TrieNode(' ');
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                // Create a new node if the character is not present
                node->children[index] = new TrieNode(ch);
            }
            node = node->children[index];
        }
        // Mark the last node as a terminal node
        node->isTerminal = true;
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                // If any character is missing, the word is not present
                return false;
            }
            node = node->children[index];
        }
        // Check if the last node is marked as a terminal node
        return node->isTerminal;
    }

    // Check if a prefix exists in the Trie
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                // If any character is missing, the prefix is not present
                return false;
            }
            node = node->children[index];
        }
        // The prefix is present if all characters are found
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << "Search 'apple': " << (obj->search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (obj->search("app") ? "Found" : "Not Found") << endl;
    cout << "StartsWith 'app': " << (obj->startsWith("app") ? "Found" : "Not Found") << endl;

    delete obj; // Don't forget to free memory
    return 0;
}

// Time Complexity:
// - Insertion (insert): O(N), where N is the length of the word being inserted.
// - Search (search): O(N), where N is the length of the word being searched.
// - Starts with (startsWith): O(N), where N is the length of the prefix.

// Space Complexity:
// - O(ALPHABET_SIZE * M), where ALPHABET_SIZE is the size of the alphabet (26 for lowercase English letters),
//   and M is the total number of characters across all words in the Trie.
