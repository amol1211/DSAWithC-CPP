//Detect Cycle In Undirected Graph Using BFS

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect a cycle in an undirected graph using BFS
    bool isCycleBFS(vector<int> adj[], int u, vector<bool> &visited) {
        // Create a queue to manage the BFS traversal
        queue<pair<int, int>> q;
        
        // Start BFS with the current node (u) and a parent of -1 (initial case)
        q.push({u, -1});
        // Mark the current node (u) as visited
        visited[u] = true;
        
        // Process the queue until it's empty
        while (!q.empty()) {
            // Get the front element (node and its parent) from the queue
            pair<int, int> P = q.front();
            q.pop();
            
            // Extract source node and its parent
            int source = P.first;
            int parent = P.second;
            
            // Iterate through each neighbor (v) of the source node
            for (int &v : adj[source]) {
                // If the neighbor (v) is not visited yet
                if (!visited[v]) {
                    // Mark the neighbor as visited
                    visited[v] = true;
                    // Add the neighbor and its source to the queue
                    q.push({v, source});
                } else if (v != parent) {
                    // If the neighbor is visited and is not the parent, cycle detected
                    return true;
                }
            }
        }
        
        // If no cycle is detected, return false
        return false;
    }

    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<int> adj[]) {
        // Initialize a visited list to keep track of visited nodes
        vector<bool> visited(V, false);
        
        // Iterate through each node in the graph
        for (int i = 0; i < V; i++) {
            // If the node (i) has not been visited, start a BFS search from it
            if (!visited[i] && isCycleBFS(adj, i, visited)) {
                // If a cycle is detected, return true
                return true;
            }
        }
        
        // If no cycle is detected, return false
        return false;
    }
};

/*Time Complexity:
The time complexity of the isCycle function is O(V + E), where V is the number of vertices 
and E is the number of edges. This is because the function iterates through each node and 
performs a BFS, which has a complexity of O(V + E).

Space Complexity:
The space complexity is O(V) due to the visited vector, which keeps track of visited nodes, 
and the queue used in BFS traversal, which can hold a list of nodes to process.*/