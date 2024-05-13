//Flood fill Algorithm (GFG)

#include <bits/stdc++.h>
using namespace std;

// This class provides a solution for the flood fill problem using Depth-First Search (DFS) algorithm.

class Solution {
private:
    // DFS function to recursively fill the neighboring cells with new color
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, 
             int newColor, int directionRow[], int directionCol[], int initialColor) {
        
        ans[row][col] = newColor; // Fill the current cell with the new color
        
        int n = image.size(); // Number of rows in the image
        int m = image[0].size(); // Number of columns in the image
        
        // Iterate through the 4 directions (up, right, down, left)
        for (int i = 0; i < 4; i++) {
            int neighbourRow = row + directionRow[i]; // Compute the neighbor row index
            int neighbourCol = col + directionCol[i]; // Compute the neighbor column index
            
            // Check if the neighbor cell is within the bounds of the image,
            // has the same initial color as the starting cell, and has not been visited yet
            if (neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m &&
                image[neighbourRow][neighbourCol] == initialColor && ans[neighbourRow][neighbourCol] != newColor) {
                
                // Recursively call DFS for the neighbor cell
                dfs(neighbourRow, neighbourCol, ans, image, newColor, directionRow, directionCol, initialColor);
            }
        }
    }
public:
    // Main function to perform flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor = image[sr][sc]; // Store the initial color of the starting cell
        vector<vector<int>> ans = image; // Copy the original image
        
        // Define directions: up, right, down, left
        int directionRow[] = {-1, 0, 1, 0};
        int directionCol[] = {0, 1, 0, -1};
        
        // Call DFS to fill the image with new color starting from the given cell
        dfs(sr, sc, ans, image, newColor, directionRow, directionCol, initialColor);
        
        return ans; // Return the filled image
    }
};

// Time Complexity: O(N * M), where N is the number of rows and M is the number of columns in the image.
//                  The DFS algorithm visits each cell at most once, resulting in linear time complexity.
// Space Complexity: O(N * M), where N is the number of rows and M is the number of columns in the image.
//                   The space is used to store the recursive call stack during DFS traversal.

