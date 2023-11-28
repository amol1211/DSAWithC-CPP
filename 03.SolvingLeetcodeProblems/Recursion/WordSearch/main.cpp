//79. Word Search

#include <iostream>
#include <string>
using namespace std;

// 1. Backtracking approach

class Solution {
private:
    // Declare variables to store the number of rows (m) and columns (n) in the board
    int m, n; 
    // Define possible directions to explore neighboring cells: down, up, right, and left
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    // Recursive function to find if the word can be formed starting from the given position (i, j)
    bool find(vector<vector<char>>& board, int i, int j, int index, string &word) {
        // If the entire word is found, return true
        if (index == word.length())
              return true;

        // Check if the current position is out of bounds or if the cell has been visited
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$')
               return false;

        // Check if the character at the current position matches the corresponding character in the word
        if (board[i][j] != word[index]) 
               return false;
        
        // Store the current character and mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all four directions recursively
        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            // If the word can be formed from the new position, return true
            if(find(board, new_i, new_j, index + 1, word)) 
               return true;
        }

        // Backtrack: Restore the original character and mark the cell as unvisited
        board[i][j] = temp;

        // If the word cannot be formed from the current position, return false
        return false;
    }   

public:
    // Function to check if the given word exists on the board
    bool exist(vector<vector<char>>& board, string word) {
        // Set the values of m and n based on the size of the board
        m = board.size();
        n = board[0].size();

        // Iterate through each cell on the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the starting character matches the first character of the word, initiate the search
                if (board[i][j] == word[0] && find(board, i, j, 0, word)) 
                    return true;
            }
        }

        // If the word cannot be found starting from any position on the board, return false
        return false;
    }
};

//Time complexity is O(m * n * 4^k), where k is the length of the word.
//Space complexity : O(m * n)