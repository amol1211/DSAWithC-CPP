//1091. Shortest Path in Binary Matrix

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : Using Breadth-First Search (BFS) algorithm

class Solution {
public:
    // Define directions for movement: diagonals, horizontal, and vertical
    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    // Function to find the shortest path in a binary matrix
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        // Get the number of rows and columns in the grid
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns

        // Check if the grid is empty or the starting cell is blocked
        if (m == 0 || n == 0 || grid[0][0] != 0)
            return -1; // If grid is empty or starting cell is blocked, return -1 indicating no valid path

        // Lambda function to check if a cell is within bounds of the grid
        auto isSafe = [&](int x, int y) { // Lambda function to check if a cell is safe to explore
            return x >= 0 && x < m && y >= 0 && y < n; // Return true if cell is within grid bounds, false otherwise
        };    

        // Initialize a queue for BFS and mark the starting cell as visited
        queue<pair<int, int>> q; // Queue to store cells to be explored
        q.push({0, 0}); // Push the starting cell (0, 0) into the queue
        grid[0][0] = 1; // Mark the starting cell as visited by setting its value to 1

        int level = 0; // Initialize the level (distance from the starting cell)

        // Loop until the queue is empty
        while (!q.empty()) { // While there are cells to explore in the queue

            int N = q.size(); // Get the number of cells at the current level

            while (N--) { // Process all cells at the current level

                auto current = q.front(); // Get the front cell from the queue
                q.pop(); // Remove the front cell from the queue

                int x = current.first; // Extract the row index of the current cell
                int y = current.second; // Extract the column index of the current cell

                // If the current cell is the destination, return the level (shortest path found)
                if(x == m - 1 && y == n - 1) // Check if the current cell is the destination
                   return level + 1; // Return the shortest path found (level + 1)

                // Explore all neighboring cells
                for (auto dir : directions) { // Iterate over all possible directions
                    
                    int x_ = x + dir[0]; // Calculate the row index of the neighboring cell
                    int y_ = y + dir[1]; // Calculate the column index of the neighboring cell

                    // If the neighboring cell is within bounds and not visited
                    if (isSafe(x_, y_) && grid[x_][y_] == 0) { // Check if the neighboring cell is safe to explore and unvisited
                        q.push({x_, y_}); // Push the neighboring cell into the queue
                        grid[x_][y_] = 1; // Mark the neighboring cell as visited by setting its value to 1
                    }
                }
            }
            level++; // Increment the level (distance from the starting cell) after exploring all cells at the current level
        }

        return -1; // Return -1 if no valid path exists
    }
};


/*Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in 
the grid. In the worst case, each cell of the grid is visited once.

Space Complexity: O(min(m, n)), where m is the number of rows and n is the number of columns 
in the grid. The space complexity is dominated by the queue used for BFS. In the worst case, 
the queue can contain all cells in one of the dimensions, either rows or columns.
*/

/*-----------------------------------------------------------------------------------------------------*/

//Approach 2 : Using Dijkstra and min-heap

class Solution {
public:
    // Define a pair to hold the distance, row, and column indices of a cell
    typedef pair<int, pair<int, int>> P;
    // Define directions for movement: diagonals, horizontal, and vertical
    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
    
    // Function to find the shortest path in a binary matrix
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        // Get the number of rows and columns in the grid
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns

        // Check if the grid is empty or the starting cell is blocked
        if (m == 0 || n == 0 || grid[0][0] != 0)
            return -1; // If grid is empty or starting cell is blocked, return -1 indicating no valid path

        // Lambda function to check if a cell is within bounds of the grid
        auto isSafe = [&](int x, int y) { // Lambda function to check if a cell is safe to explore
            return x >= 0 && x < m && y >= 0 && y < n; // Return true if cell is within grid bounds, false otherwise
        };    

        // Initialize a 2D vector to store the shortest distance from the starting cell to each cell
        vector<vector<int>> result(m, vector<int>(n, INT_MAX)); // Initialize result matrix with all distances set to infinity

        // Initialize a min-heap priority queue to store cells with their respective distances
        priority_queue<P, vector<P>, greater<P>> pq; // Min-heap priority queue to get minimum distance cell efficiently

        // Push the starting cell into the priority queue with distance 0
        pq.push({0, {0, 0}}); // Push the starting cell coordinates (0, 0) along with distance 0 into the priority queue
        result[0][0] = 0; // Set the distance of the starting cell to 0

        // Loop until the priority queue is empty
        while (!pq.empty()) {

            int distance = pq.top().first; // Get the distance of the top element in the priority queue
            pair<int, int> node = pq.top().second; // Get the coordinates of the top element in the priority queue
            int x = node.first; // Extract the row index of the top element
            int y = node.second; // Extract the column index of the top element
            pq.pop(); // Remove the top element from the priority queue
            
            // Explore all neighboring cells
            for (auto dir : directions) { // Iterate over all possible directions

                int x_ = x + dir[0]; // Calculate the row index of the neighboring cell
                int y_ = y + dir[1]; // Calculate the column index of the neighboring cell

                int dist = 1; // Set the distance to 1 for moving to a neighboring cell

                // If the neighboring cell is within bounds, unblocked, and a shorter path is found
                if (isSafe(x_, y_) && grid[x_][y_] == 0 && distance + dist < result[x_][y_]) { // Check if neighboring cell is safe to explore and a shorter path is found
                //Here we did't marked processed grid visited because we're checking - "distance + dist < result[x_][y_]" 
                //where distance will automatically increase if the grid is visited already
                    pq.push({distance + dist, {x_, y_}}); // Push the neighboring cell into the priority queue with updated distance
                    result[x_][y_] = distance + dist; // Update the distance of the neighboring cell
                }
            }
        }

        // If the destination cell distance is still infinity, no valid path exists
        if (result[m - 1][n - 1] == INT_MAX)
            return -1; // Return -1 if no valid path exists

        // Return the shortest distance to reach the destination cell + 1
        return result[m - 1][n - 1] + 1; // Return the shortest distance to reach the destination cell
    }
};

/*Time Complexity: O(m * n * log(m * n)), where m is the number of rows and n is the number of columns in the grid.

Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
*/

/*-------------------------------------------------------------------------------------------------------------------*/

//Approach 3 : Using Dijkstra and simple Queue (We can use queue because distance is constant all over which is 1)

class Solution {
public:
    // Define a pair to hold the distance, row, and column indices of a cell
    typedef pair<int, pair<int, int>> P;
    // Define directions for movement: diagonals, horizontal, and vertical
    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
    
    // Function to find the shortest path in a binary matrix
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        // Get the number of rows and columns in the grid
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns

        // Check if the grid is empty or the starting cell is blocked
        if (m == 0 || n == 0 || grid[0][0] != 0)
            return -1; // If grid is empty or starting cell is blocked, return -1 indicating no valid path

        // Lambda function to check if a cell is within bounds of the grid
        auto isSafe = [&](int x, int y) { // Lambda function to check if a cell is safe to explore
            return x >= 0 && x < m && y >= 0 && y < n; // Return true if cell is within grid bounds, false otherwise
        };    

        // Initialize a 2D vector to store the shortest distance from the starting cell to each cell
        vector<vector<int>> result(m, vector<int>(n, INT_MAX)); // Initialize result matrix with all distances set to infinity

        // Initialize a queue for BFS to store cells with their respective distances
        queue<P> pq; // Queue to store cells to be explored

        // Push the starting cell into the queue with distance 0
        pq.push({0, {0, 0}}); // Push the starting cell coordinates (0, 0) along with distance 0 into the queue
        result[0][0] = 0; // Set the distance of the starting cell to 0

        // Loop until the queue is empty
        while (!pq.empty()) {

            int distance = pq.front().first; // Get the distance of the front element in the queue
            pair<int, int> node = pq.front().second; // Get the coordinates of the front element in the queue
            int x = node.first; // Extract the row index of the front element
            int y = node.second; // Extract the column index of the front element
            pq.pop(); // Remove the front element from the queue
            
            // Explore all neighboring cells
            for (auto dir : directions) { // Iterate over all possible directions

                int x_ = x + dir[0]; // Calculate the row index of the neighboring cell
                int y_ = y + dir[1]; // Calculate the column index of the neighboring cell

                int dist = 1; // Set the distance to 1 for moving to a neighboring cell

                // If the neighboring cell is within bounds, unblocked, and a shorter path is found
                if (isSafe(x_, y_) && grid[x_][y_] == 0 && distance + dist < result[x_][y_]) { // Check if neighboring cell is safe to explore and a shorter path is found
                //Here we did't marked processed grid visited because we're checking - "distance + dist < result[x_][y_]" 
                //where distance will automatically increase if the grid is visited already
                    pq.push({distance + dist, {x_, y_}}); // Push the neighboring cell into the queue with updated distance
                    result[x_][y_] = distance + dist; // Update the distance of the neighboring cell
                }
            }
        }

        // If the destination cell distance is still infinity, no valid path exists
        if (result[m - 1][n - 1] == INT_MAX)
            return -1; // Return -1 if no valid path exists

        // Return the shortest distance to reach the destination cell + 1
        return result[m - 1][n - 1] + 1; // Return the shortest distance to reach the destination cell
    }
};

/*Time Complexity: O((m * n) * log(m * n)), where m is the number of rows and n is the number of columns in the grid.

Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
*/

