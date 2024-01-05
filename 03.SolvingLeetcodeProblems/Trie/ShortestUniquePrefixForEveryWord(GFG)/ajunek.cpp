#include <iostream>
#include <vector>
#include <string>

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int count;

    TrieNode(char ch) {
        data = ch;
        count = 1;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }      
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(string word) {
        for (char ch : word) {
            TrieNode* current = root;
            int index = ch - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode(ch);
            }
            else {
                current->children[index]->count++;
            }
            current = current->children[index];
        }
    }

    string findPrefix(string word) {
        TrieNode* current = root;

        string prefix = "";

        for (char ch : word) {
            int index = ch - 'a';
            prefix.push_back(ch);

            if (current->children[index]->count == 1) {
            break;
        }

        current = current->children[index];
        }

        return prefix; 
    }
};

class Solution {
public:
     vector<string> findPrefixes(string arr[], int n) {

        Trie trie;
        vector<string> result;

        for (int i = 0; i < n; i++) {
            trie.insertWord(arr[i]);
            }

        for (int i = 0; i < n; i++) {
            string prefix = trie.findPrefix(arr[i]);
            result.push_back(prefix);
            }
            return result;
    }
};