//212. Word Search II
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Vector to store the result words found on the board
    vector<string> result;

    // Variables to store the dimensions of the board
    int m, n;

    // TrieNode structure representing each node in the Trie
    struct TrieNode {
        bool isTerminal;   // Flag indicating if a word ends at this node
        string word;       // The word represented by the path from the root to this node
        TrieNode* children[26];  // Array to store child nodes for each letter
    };

    // Function to create a new TrieNode
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode->isTerminal = false;
        newNode->word = "";

        // Initialize child pointers to nullptr
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }

        return newNode;
    }

    // Function to insert a word into the Trie
    void insert(TrieNode* root, string& word) {
        TrieNode* current = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            // If the child node for the current character doesn't exist, create one
            if(current->children[ch - 'a'] == nullptr) {
                current->children[ch - 'a'] = getNode();
            }
            current = current->children[ch - 'a'];  // Move to the next node
        }

        current->isTerminal = true;
        current->word = word;
    }

    // Possible movement directions: down, up, right, left
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0, -1}};

    // Function to find words on the board using Trie
    void findTrieWords(vector<vector<char>>& board, int i, int j, TrieNode* root) {

        // Base cases to check if the current position is out of bounds or the character is not in the Trie
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;

        // If the current cell is already visited ('$') or the current character in the board
        // does not have a corresponding child in the Trie, return without further exploration.
        if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == nullptr)
           return;


        // Move the root to the child corresponding to the current character
        root = root->children[board[i][j] - 'a'];

        // If a word ends at this node, add it to the result vector
        if(root->isTerminal == true) {
            result.push_back(root->word);
            root->isTerminal = false;
        }

        // Mark the current cell as visited ('$')
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore in all four directions
        for (vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            findTrieWords(board, new_i, new_j, root);
        }

        // Restore the original character at the current cell
        board[i][j] = temp;
    }

    // Main function to find words on the board given a list of words
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        // Create a Trie and insert all words into it
        TrieNode* root = getNode();

        for (string &word : words) {
            insert(root, word);
        }

        // Iterate through each cell on the board and start searching for words
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];

                // If the current character is the prefix of any word in the Trie, start searching
                if (root->children[ch - 'a'] != nullptr) {
                    findTrieWords(board, i, j, root);
                }
            }
        }

        // Return the vector of found words
        return result;
    }
};

/*Time Complexity:

The time complexity of the insert function is O(L), where L is the length of the word being inserted.
The time complexity of the findTrieWords function is O(N * M * 4^L), where N and M are the dimensions 
of the board and L is the maximum length of the words.

Space Complexity:

The space complexity is O(W * L), where W is the number of words and L is the average length of the 
words. This accounts for the space used by the Trie data structure.*/


/*
dir[0] represents the change in the row index (vertical movement).
dir[1] represents the change in the column index (horizontal movement).
So, by adding dir[0] to the current row index i, and adding dir[1] to the current column 
index j, you get the new indices new_i and new_j. This allows you to move in the specified 
direction on the board.

For example:

If dir = {1, 0}, it means moving down, so new_i will be one row down, and new_j will remain the same.
If dir = {-1, 0}, it means moving up, so new_i will be one row up, and new_j will remain the same.
If dir = {0, 1}, it means moving right, so new_i will remain the same, and new_j will be one column to the right.
If dir = {0, -1}, it means moving left, so new_i will remain the same, and new_j will be one column to the left.
*/