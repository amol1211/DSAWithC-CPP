//980. Unique Paths III

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // Variables to store the dimensions of the grid and the final result
    int m, n, result;
    
    // Variable to store the count of non-obstacle cells
    int nonObstacles;
    
    // Directions for movement: right, left, up, down
    vector<vector<int>> directions{{1,0}, {-1, 0}, {0, -1}, {0, 1}};
    
    // Backtracking function to explore all possible paths
    void backtrack(vector<vector<int>>& grid, int count, int i, int j) {
        
        // Base case: if the current position is out of bounds or an obstacle
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) 
            return;

        // Base case: if the destination is reached
        if(grid[i][j] == 2) {
            // If all non-obstacle cells are visited, increment the result
            if(count == nonObstacles)
                result++;
            return;    
        } 

        // Mark the current cell as visited
        grid[i][j] = -1;

        // Explore all possible directions
        for (vector<int> & dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            // Recursively call the function for the next position
            backtrack(grid, count + 1, new_i, new_j);
        }

        // Backtrack: mark the current cell as unvisited
        grid[i][j] = 0;
    }
public:
    // Main function to find the number of unique paths
    int uniquePathsIII(vector<vector<int>>& grid) {
        // Set the dimensions of the grid
        m = grid.size();
        n = grid[0].size();

        // Initialize result and nonObstacles
        result = 0; 
        nonObstacles = 0;

        // Variables to store the starting position
        int start_x = 0, start_y = 0;

        // Count the number of non-obstacle cells and find the starting position
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                     nonObstacles++;

                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }     
            }
        }
        
        // Increment nonObstacles for the starting cell
        nonObstacles += 1;

        // Variable to store the count of visited cells
        int count = 0;

        // Start the backtracking process
        backtrack(grid, count, start_x, start_y);

        // Return the final result
        return result;
    }
};

//Time complexity : O(4^(mn))
//Space complexity : O(m*n) 