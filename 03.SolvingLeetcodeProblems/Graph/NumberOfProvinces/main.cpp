//547. Number of Provinces

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : DFS

class Solution {
private:
    // Depth-first search function to traverse the graph
    void dfs(vector<vector<int>> &isConnected, int u, vector<bool> &visited) {
        // Mark the current node (u) as visited
        visited[u] = true;

        // Iterate through all possible neighbors of u
        for (int v = 0; v < n; v++) {
            // If the neighbor (v) has not been visited and there is a direct connection between u and v
            if (!visited[v] && isConnected[u][v] == 1) {
                // Recursively perform DFS from the neighbor (v)
                dfs(isConnected, v, visited);
            }
        }
    }

public:
    // Number of nodes in the graph (also representing provinces)
    int n;
    
    // Function to find the number of provinces (connected components)
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Initialize the number of nodes (n)
        n = isConnected.size();
        
        // Create a visited array to keep track of visited nodes
        vector<bool> visited(n, false);
        
        // Initialize count for the number of provinces (connected components)
        int count = 0;
        
        // Iterate through each node (representing a city)
        for (int i = 0; i < n; i++) {
            // If the node (i) has not been visited
            if (!visited[i]) {
                // Increment the province count (new connected component found)
                count++;
                // Perform DFS starting from the node (i)
                dfs(isConnected, i, visited);
            }
        }
        
        // Return the count of provinces (connected components)
        return count;
    }
};

/*Time Complexity:
O(V + E)

Space Complexity:
The space complexity is O(V). This is due to the visited vector, which keeps track of the visited nodes, and the recursive stack during the DFS traversal.*/

/*----------------------------------------------------------------------*/

//Approach 2 : BFS

class Solution {
public:
    // Number of nodes (provinces) in the graph
    int n;

    // Breadth-first search function to traverse the graph
    void bfs(vector<vector<int>>& isConnected, int u, vector<bool>& visited) {
        // Create a queue to manage the BFS traversal
        queue<int> q;

        // Start BFS with the current node (u)
        q.push(u);
        // Mark the current node as visited
        visited[u] = true;

        // Process the queue until it's empty
        while (!q.empty()) {
            // Get the front node from the queue
            int curr = q.front();
            q.pop();

            // Iterate through all possible neighbors of the current node
            for (int v = 0; v < n; v++) {
                // If the neighbor (v) has not been visited and there is a direct 
                //connection between current node and neighbor
                if (!visited[v] && isConnected[curr][v] == 1) {
                    // Mark the neighbor as visited
                    visited[v] = true;
                    // Add the neighbor to the queue for further processing
                    q.push(v);
                }
            }
        }
    }

    // Function to find the number of provinces (connected components)
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Initialize the number of nodes (provinces) in the graph
        n = isConnected.size();

        // Create a visited array to keep track of visited nodes
        vector<bool> visited(n, false);

        // Initialize count for the number of provinces (connected components)
        int count = 0;

        // Iterate through each node (representing a city)
        for (int i = 0; i < n; i++) {
            // If the node (i) has not been visited
            if (!visited[i]) {
                // Perform BFS starting from the node (i)
                bfs(isConnected, i, visited);
                // Increment the province count (new connected component found)
                count++;
            }
        }

        // Return the count of provinces (connected components)
        return count;
    }
};

/*Time Complexity:
O(V + E)

Space Complexity:
The space complexity is O(V). This is due to the visited vector, which keeps track of the visited nodes, and the recursive stack during the DFS traversal.*/