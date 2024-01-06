//212. Word Search II
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;
    int m, n;
    
    //Node struct for trie
    struct TrieNode {
        bool isTerminal;
        string word;
        TrieNode* children[26];
    };
    
    //Get TrieNode
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode->isTerminal = false;

        newNode->word = "";

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }

        return newNode;
    }

    void insert(TrieNode* root, string &word) {
        TrieNode* current = root;
        
        //Check for each charactor of word
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (current->children[ch - 'a'] == nullptr) {
                current->children[ch - 'a'] = getNode();
            }

            current = current->children[ch - 'a'];
        }
        current->isTerminal = true;
        current->word = word;
    }

    vector<vector<int>> directions{{1,0}, {-1, 0}, {0, 1}, {0, -1}}; // down, up, right, left
        void findTrieWords(vector<vector<char>> &board, int i, int j, TrieNode* root) {
            if (i < 0 || i >= m || j < 0 || j >= n) 
                  return;

            if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == nullptr)
                  return;

            root = root->children[board[i][j] - 'a'];

            if (root->isTerminal == true) {
                result.push_back(root->word);
                root->isTerminal = false;
            }

            char temp = board[i][j];
            board[i][j] = '$'; //Marking visited


            //left, right, up, down
            for (vector<int>& dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                findTrieWords(board, new_i, new_j, root);
            }

            board[i][j] = temp; //marking unvisited now           
        }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(); // row
        n = board[0].size(); // column
        
        TrieNode* root = getNode();

        //Insert words in trie
        for (string &word : words) {
            insert(root, word);
        }

        //Traverse in the grid just once and find all the words in trie if present
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];

                if(root->children[ch - 'a']) {
                    findTrieWords(board, i, j, root);
                }
            }
        }

        return result;
    }
};