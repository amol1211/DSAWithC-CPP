#include <iostream>
using namespace std;

class TrieNode {
public:
     char data;
     TrieNode* children[26];
     bool isTerminal;

     //Constructor
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
        //Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        //Assumption, word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        //If char(letter) is present
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            //If child is absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //Recursion
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
        else {
            //Absent
            return false;
        }

        //Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    bool deleteUtil(TrieNode* root, string word) {
        //Base case
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

        //Present
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            //Absent
            return false;
        }
      
        bool ans = deleteUtil(child, word.substr(1));
        delete child;
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