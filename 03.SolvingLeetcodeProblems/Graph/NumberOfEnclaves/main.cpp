//1020. Number of Enclaves

#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    // Helper function to perform Depth-First Search (DFS) on the grid
    void dfs(vector<vector<int>>& grid, int i, int j) {
        // Base cases: if the current cell is out of grid bounds or is water (0), return
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) 
            return;

        // Mark the current cell as visited by setting it to 0
        grid[i][j] = 0;      

        // Recursively call DFS for all four neighboring cells (right, left, down, up)
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j); 
    }    
public:
    int m, n; // Variables to store the number of rows and columns in the grid

    // Function to count the number of land cells that are enclaves
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();      // Initialize number of rows
        n = grid[0].size();   // Initialize number of columns

        // Perform DFS on the first and last columns for each row
        for (int row = 0; row < m; row++) {
            // If the cell in the first column is land (1), perform DFS
            if (grid[row][0] == 1) {
                dfs(grid, row, 0);
            }
            // If the cell in the last column is land (1), perform DFS
            if (grid[row][n - 1] == 1) {
                dfs(grid, row, n - 1);
            }
        }

        // Perform DFS on the first and last rows for each column
        for (int col = 0; col < n; col++) {
            // If the cell in the first row is land (1), perform DFS
            if (grid[0][col] == 1) {
                dfs(grid, 0, col);
            }
            // If the cell in the last row is land (1), perform DFS
            if (grid[m - 1][col] == 1) {
                dfs(grid, m - 1, col);
            }
        }

        int count = 0; // Variable to count the number of enclaves

        // Traverse the grid to count remaining land cells (1s)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++; // Increment count if the cell is land (1)
                }
            }
        }

        return count; // Return the number of enclaves
    }
};

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns. 
// This is because each cell is visited once during the DFS traversal.

// Space Complexity: O(m * n) in the worst case due to the recursion stack in the DFS.
