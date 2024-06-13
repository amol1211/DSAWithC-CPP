//542. 01 Matrix

#include <bits/stdc++.h>
using namespace std;

//Using BFS from from 0s 
//NOTE : (BFS from each 1 to their nearest 0 solution is O(m * n) * O(m * n) which is expensive 
//solution that's why we use BFS From 0s to 1.
/* Pitch {0, 1, 1}, {1, 1, 1}, {1, 1, 1} matrix to interviewer */

class Solution {
public:
    int m, n; // Dimensions of the matrix
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Possible directions to move: right, left, down, up

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size(); // Number of rows in the matrix
        n = mat[0].size(); // Number of columns in the matrix

        queue<pair<int, int>> q; // Queue to perform BFS

        vector<vector<int>> result(m, vector<int>(n, -1)); // Result matrix initialized with -1

        // Initialize the result matrix and enqueue all 0's positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) { // If the current cell is 0
                    result[i][j] = 0; // Distance to the nearest 0 is 0
                    q.push({i, j}); // Enqueue the position of the 0
                }
            }
        }

        // Perform BFS to update the distances
        while (!q.empty()) {
            pair<int, int> p = q.front(); // Get the front element in the queue
            q.pop(); // Remove the front element from the queue

            int i = p.first; // Row index
            int j = p.second; // Column index

            // Explore all four possible directions
            for (auto &dir : directions) {
                int new_i = i + dir[0]; // Calculate the new row index
                int new_j = j + dir[1]; // Calculate the new column index

                // Check if the new position is within bounds and has not been visited yet
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && result[new_i][new_j] == -1) {
                    result[new_i][new_j] = result[i][j] + 1; // Update the distance
                    q.push({new_i, new_j}); // Enqueue the new position
                }
            }
        }

        return result; // Return the result matrix
    }
};

/* Time Complexity: O(m * n)

Each cell is processed at most once. In the worst case, all cells are visited, 
leading to a time complexity proportional to the number of cells in the matrix.

Space Complexity: O(m * n)

The space complexity is also proportional to the number of cells due to the 
result matrix and the queue, which can hold up to O(m * n) elements in the worst case.

This approach efficiently computes the shortest distance to the nearest 0 for each cell in 
the matrix using BFS, ensuring optimal time and space usage. */