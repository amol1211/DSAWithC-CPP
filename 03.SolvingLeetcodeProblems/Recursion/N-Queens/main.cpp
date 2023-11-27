//51. N-Queens

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. Backtracking approach

class Solution {
private:
    // Function to add a valid solution to the result
    void addSolution(vector<vector<string>> &ans, vector<vector<string>> &board, int n) {
        vector<string> temp;
        // Convert the board to the required format
        for (int i = 0; i < n; i++) {
            string row = "";
            // Concatenate each cell in the row to form a string
            for (int j = 0; j < n; j++) {
                row += board[i][j];
            }
            // Push the formatted row to the temporary vector
            temp.push_back(row);
        }
        // Push the valid solution to the result vector
        ans.push_back(temp);
    }

    // Function to check if placing a queen at a given position is safe
    bool isSafe(int row, int col, vector<vector<string>> &board, int n) {
        int x = row;
        int y = col;

        // Check for the same row
        while (y >= 0) {
            // Check if there is a queen in the same row
            if (board[x][y] == "Q")
                return false;
            y--;
        }

        x = row;
        y = col;
        // Check for diagonal (upper-left to lower-right)
        while (x >= 0 && y >= 0) {
            // Check if there is a queen in the diagonal
            if (board[x][y] == "Q")
                return false;
            y--;
            x--;
        }

        x = row;
        y = col;
        // Check for diagonal (lower-left to upper-right)
        while (x < n && y >= 0) {
            // Check if there is a queen in the diagonal
            if (board[x][y] == "Q")
                return false;
            y--;
            x++;
        }

        // If no conflicts, it is safe to place the queen at the given position
        return true;
    }

    // Recursive function to solve the N-Queens problem
    void solve(int col, vector<vector<string>> &ans, vector<vector<string>> &board, int n) {
        // Base case: If all queens are placed, add the solution to the result
        if (col == n) {
            addSolution(ans, board, n);
            return;
        }

        // Solve one case, and recursion will take care of the rest
        for (int row = 0; row < n; row++) {
            // Check if placing a queen at the current position is safe
            if (isSafe(row, col, board, n)) {
                // If placing queen is safe, mark the position and move to the next column
                board[row][col] = "Q";
                solve(col + 1, ans, board, n);
                // Backtrack: restore the original value before exploring other possibilities
                board[row][col] = ".";
            }
        }
    }

public:
    // Main function to solve the N-Queens problem and return all solutions
    vector<vector<string>> solveNQueens(int n) {
        // Initialize the chessboard with empty spaces
        vector<vector<string>> board(n, vector<string>(n, "."));
        // Vector to store all valid solutions
        vector<vector<string>> ans;

        // Start solving the problem from the first column
        solve(0, ans, board, n);

        return ans;
    }
};

//Time complexity : O(N!)
//Space complexity : O(N^2)

