//1631. Path With Minimum Effort

#include <bits/stdc++.h>
using namespace std;

//Using Dijkstra algorithm

class Solution {
public:
    // Define a pair to hold the effort difference and the coordinates of a cell
    typedef pair<int, pair<int, int>> P; // Define a pair (P) consisting of an integer and a pair of integers

    // Define directions for movement: up, down, left, right
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Define the directions for movement: up, down, left, right

    // Function to find the minimum effort path
    int minimumEffortPath(vector<vector<int>>& heights) { // Define a function to find the minimum effort path, taking a 2D vector of integers (heights) as input
        
        // Get the number of rows and columns in the grid
        int m = heights.size(); // Get the number of rows in the grid
        int n = heights[0].size(); // Get the number of columns in the grid

        // Initialize a 2D vector to store the minimum effort for each cell
        vector<vector<int>> result(m, vector<int>(n, INT_MAX)); // Initialize a 2D vector (result) with dimensions m x n and fill it with INT_MAX
        
        // Initialize a min-heap priority queue to store cells with their respective effort differences
        priority_queue<P, vector<P>, greater<P>> pq; // Initialize a priority queue (pq) using a min-heap, with elements of type P (pair) sorted in ascending order

        // Lambda function to check if a cell is within bounds of the grid
        auto isSafe = [&](int x, int y) { // Define a lambda function (isSafe) to check if a cell with coordinates (x, y) is within the grid
            return x >= 0 && x < m && y >= 0 && y < n; // Return true if (x, y) is within the grid boundaries, otherwise return false
        };

        // Set the effort difference of the starting cell (0,0) to 0
        result[0][0] = 0; // Set the effort difference of the starting cell (0, 0) to 0
        // Push the starting cell into the priority queue
        pq.push({0, {0, 0}}); // Push the starting cell coordinates (0, 0) along with its effort difference (0) into the priority queue

        // Loop until the priority queue is empty
        while (!pq.empty()) { // Start a loop that continues until the priority queue is empty

            // Extract the top element from the priority queue
            int diff = pq.top().first; // Get the effort difference of the top element in the priority queue
            auto coordinates = pq.top().second; // Get the coordinates of the top element in the priority queue
            pq.pop(); // Remove the top element from the priority queue
            int x = coordinates.first; // Extract the x-coordinate from the pair of coordinates
            int y = coordinates.second; // Extract the y-coordinate from the pair of coordinates
            
            //Every entry after this will be bigger since we are using min heap and 
            //mininum diff will always be on top
            // If the current cell is the destination, return the effort difference
            if (x == m - 1 && y == n - 1) // Check if the current cell is the destination (bottom-right corner of the grid)
                return diff; // If so, return the effort difference

            // Explore the neighboring cells
            for (auto &dir : directions) { // Start a loop to iterate over each direction for movement
                
                int x_ = x + dir[0]; // Calculate the x-coordinate of the neighboring cell in the current direction
                int y_ = y + dir[1]; // Calculate the y-coordinate of the neighboring cell in the current direction

                // If the neighboring cell is within bounds
                if (isSafe(x_, y_)) { // Check if the neighboring cell is within the grid boundaries

                    // Calculate the absolute difference in heights between the current cell and its neighbor
                    int absDiff = abs(heights[x][y] - heights[x_][y_]); // Calculate the absolute difference in heights between the current cell and its neighbor
                    // Update the maximum effort difference encountered so far
                    int maxDiff = max(diff, absDiff); // Calculate the maximum effort difference encountered so far
                    
                    // If the new maximum effort difference is less than the previously recorded effort for the neighbor
                    if (result[x_][y_] > maxDiff) { // Check if the new maximum effort difference is less than the previously recorded effort for the neighbor
                        
                        // Update the effort for the neighbor and push it into the priority queue
                        result[x_][y_] = maxDiff; // Update the effort for the neighboring cell with the new maximum effort difference
                        pq.push({maxDiff, {x_, y_}}); // Push the neighboring cell coordinates along with its effort difference into the priority queue
                    }
                }
            }
        }

        // Return the minimum effort required to reach the destination
        return result[m - 1][n - 1]; // Return the effort required to reach the destination cell (bottom-right corner of the grid)
    }
}; 

/*Time Complexity: O(m * n * log(m * n)), where m is the number of rows and n is the number of columns in the grid.

Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
*/

