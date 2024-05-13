//994. Rotting Oranges

#include <bits/stdc++.h>
using namespace std;

// At each level of BFS traversal, the time is incremented by one unit, representing the passage of time for rotting.

class Solution {
public:
    // Function to calculate the minimum time required for all oranges to rot.
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows in the grid
        int n = grid[0].size(); // Number of columns in the grid

        vector<vector<int>> visited = grid; // Copying the grid for tracking visited oranges

        queue<pair<int, int>> q; // Queue to store the coordinates of oranges

        int countOfFreshOranges = 0; // Counter for fresh oranges

        // Traversing the grid to find initial rotten oranges and counting fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 2) {
                    q.push({i, j}); // Storing rotten oranges in the queue
                }
                if (visited[i][j] == 1) {
                    countOfFreshOranges++; // Counting fresh oranges
                }
            }
        }

        // If there are no fresh oranges, return 0 as they are already rotten
        if (countOfFreshOranges == 0)
            return 0;
        // If there are no rotten oranges initially, it is impossible for all oranges to rot
        if (q.empty())
            return -1;

        int time = -1; // Initializing time to -1, as the first BFS traversal starts from time 0
/* you take out current rotten oranges and add their neighbours in the queue in every iteration.By the time you've rotten all the oranges. Your queue still has last set of rotten oranges, your answer is found at this stage but the loop will run one more time to empty the queue and come out. But in this extra iteration your minutes increases by 1. Either return minutes -1 or initialize minutes to -1, to get the correct answer*/
        // Directions for moving in the grid (down, up, left, right)
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        // Performing BFS until the queue is empty
        while (!q.empty()) {
            int size = q.size(); // Current size of the queue (number of oranges in the current level)

            // Processing oranges at the current level
            while (size--) {
                auto [x, y] = q.front(); // Extracting coordinates of the current orange
                q.pop(); // Removing the processed orange from the queue

                // Checking all four directions of the current orange
                for (auto [dx, dy] : dirs) {
                    int i = x + dx; // New row index
                    int j = y + dy; // New column index

                    // Checking if the new indices are within bounds and the orange is fresh
                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2; // Marking the orange as rotten
                        countOfFreshOranges--; // Decrementing the count of fresh oranges
                        q.push({i, j}); // Adding the newly rotten orange to the queue
                    }
                }
            }
            time++; // Incrementing time after processing all oranges in the current level
        }

        // If all fresh oranges are rotten, return the time taken for all oranges to rot
        if (countOfFreshOranges == 0)
            return time;

        // If there are still fresh oranges left, it is impossible for all oranges to rot
        return -1;
    }
};


// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
//                  Each cell is visited at most once, and BFS traversal takes at most O(m * n) time.
// Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
//                   The space is used for the visited grid and the queue for BFS traversal.
