//Coding ninja problem(Phone Directory)

// Define a class for a TrieNode
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    // Constructor for TrieNode
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

// Define a Trie class
class Trie {
public:
    TrieNode* root;

    // Constructor for Trie class, initializes the root with a null character
    Trie() {
        root = new TrieNode('\0');
    }

    // Utility function to recursively insert a word into the trie
    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    // Public function to insert a word into the trie
    void insertWord(string word) {
        insertUtil(root, word);
    }

    // Utility function to print suggestions for a given trie node
    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];

            if (next != nullptr) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    // Public function to get suggestions for a given query string
    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.size(); i++) {
            char last = str[i];

            prefix.push_back(last);

            // Check for the last character
            TrieNode* curr = prev->children[last - 'a'];

            // If not found, break
            if (curr == nullptr) {
                break;
            }

            // If found, get suggestions and add them to the output
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

// Function to create a phone directory using a Trie
vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    // Create a Trie
    Trie* t = new Trie();

    // Insert all contacts into the Trie
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }

    // Return the suggestions for the query string
    return t->getSuggestions(queryStr);
}

/*Time Complexity:

Inserting a word into the Trie takes O(M) time, where M is the length of the word.
Getting suggestions for a query string takes O(N * M) time, where N is the length 
of the query string and M is the average length of the words in the Trie.

Space Complexity:

The space complexity is O(N * M), where N is the number of words in the contact list, 
and M is the average length of the words.*/