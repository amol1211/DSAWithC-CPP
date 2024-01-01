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
        //Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

    int index = word[0] - 'A';
    TrieNode* child;

    //Present
    if (root->children[index] != nullptr) {
        child = root->children[index];
    }
    else {//Absent
        return false;
    }

    //Recursion
    return searchUtil(child, word.substr(1));
  }
    bool searchWord(string word) {
        return searchUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();
    t->insertWord("abcd");

    t->insertWord("abcd");
    cout << "Present or Not " << t->searchWord("abcd") << endl;
    return 0;
}
