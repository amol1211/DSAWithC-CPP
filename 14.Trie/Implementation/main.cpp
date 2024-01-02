#include <iostream>
using namespace std;

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
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assumption, word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // If char(letter) is present
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            // If letter is absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            // Absent
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    bool deleteUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            if (root->isTerminal) {
                root->isTerminal = false;
                return true;
            } else {
                return false;
            }
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            // Absent
            return false;
        }

        bool ans = deleteUtil(child, word.substr(1));

        // If the child node has no other references (no other words share the prefix),
        // and it is not a terminal node, then it can be safely deleted.
        if (!child->isTerminal && ans) {
            delete child;
            root->children[index] = nullptr;
        }

        return ans;
    }

    bool deleteWord(string word) {
        return deleteUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();
    t->insertWord("AMOL");

    cout << "Present or Not: " << t->searchWord("AMOL") << endl;

    // Use deleteWord instead of erase
    t->deleteWord("AMOL");

    cout << "Present or Not: " << t->searchWord("AMOL") << endl;

    return 0;
}

/*Time Complexity:
Insertion (insertWord):

Time complexity for inserting a word of length L is O(L).
Search (searchWord):

Time complexity for searching a word of length L is O(L).
Deletion (deleteWord):

The time complexity for deleting a word depends on the length of the word and 
the structure of the Trie. In the worst case, it may be O(L), but if deletion 
involves removing nodes up to the root (e.g., when a word is the only one sharing a prefix), 
it may be O(L * M), where M is the number of nodes to be deleted.

Space Complexity:
Trie Construction:

The space complexity for storing N words of average length M is O(N * M).
This is because each character in a word requires a TrieNode, and there are N words.
Function Calls:

The recursion depth for function calls (insert, search, delete) is determined by the 
length of the input word. In the worst case, the maximum recursion depth is the length 
of the longest word, so the space complexity for the function call stack is O(L).

Overall Space Complexity:
The overall space complexity is dominated by the storage of Trie nodes and is O(N * M) in the worst case.*/