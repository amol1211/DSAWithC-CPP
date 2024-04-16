//Detect cycle in an undirected graph using DFS(GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to detect a cycle in an undirected graph using DFS
    bool isCycleDFS(vector<int> adj[], int u, vector<bool> &visited, int parent) {
        // Mark the current node (u) as visited
        visited[u] = true;
        
        // Iterate through each neighbor (v) of the current node (u)
        for (int &v : adj[u]) {
            // Skip the parent node to avoid immediately backtracking
            if (v == parent) continue;
            
            // If the neighbor (v) is already visited, it indicates a cycle
            if (visited[v])
                return true;
                
            // Recursively call DFS from the neighbor (v) and check for a cycle
            if (isCycleDFS(adj, v, visited, u)) {
                return true;
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
            // If the node (i) has not been visited, start a DFS search from it
            if (!visited[i] && isCycleDFS(adj, i, visited, -1)) {
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
performs a DFS, which has a complexity of O(V + E).

Space Complexity:
The space complexity is O(V) due to the visited vector, which keeps track of visited nodes. 
Additionally, the recursive DFS function uses a stack space that could potentially grow up to 
the number of vertices in the worst-case scenario.*/
