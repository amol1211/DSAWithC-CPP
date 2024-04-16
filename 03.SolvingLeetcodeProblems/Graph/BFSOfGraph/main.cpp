//BFS of graph (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Breadth-first search function to traverse the graph
    void bfs(vector<int> adj[], int u, vector<bool> &visited, vector<int> &result) {
        // Create a queue to manage the BFS traversal
        queue<int> q;
        
        // Start BFS with the current node (u)
        q.push(u);
        // Mark the current node as visited
        visited[u] = true;
        // Add the current node to the result list
        result.push_back(u);
        
        // Process the queue until it's empty
        while (!q.empty()) {
            // Get the front node from the queue
            int u = q.front();
            q.pop();
            
            // Iterate through each neighbor (v) of the current node (u)
            for (int &v : adj[u]) {
                // If the neighbor (v) is not visited yet
                if (!visited[v]) {
                    // Add the neighbor to the queue for further processing
                    q.push(v);
                    // Mark the neighbor as visited
                    visited[v] = true;
                    // Add the neighbor to the result list
                    result.push_back(v);
                }
            }
        }
    }
    
    // Function to return Breadth First Traversal of the given graph
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Initialize a visited list to keep track of visited nodes
        vector<bool> visited(V, false);
        // Initialize a result list to store the BFS traversal
        vector<int> result;
        
        // Perform BFS starting from node 0
        bfs(adj, 0, visited, result);
        
        // Return the result list containing the BFS traversal
        return result;
    }
};

/*Time Complexity:
The time complexity of the bfsOfGraph function is O(V + E), where V is the number of 
vertices and E is the number of edges. This is because the breadth-first search (BFS) 
traverses each node once and explores each edge exactly once.

Space Complexity:
The space complexity is O(V) due to the visited vector, which keeps track of visited nodes. 
Additionally, the function uses a result vector to store the traversal, and a queue to manage 
the BFS process, both of which contribute to the space complexity.*/