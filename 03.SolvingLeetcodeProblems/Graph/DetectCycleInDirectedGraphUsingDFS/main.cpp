//Detect Cycle In Directed Graph Using DFS (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to detect a cycle in a directed graph using DFS
    bool isCycleDFS(vector<int> adj[], int u, vector<bool>& visited, vector<bool>& inRecursion) {
        // Mark the current node (u) as visited
        visited[u] = true;
        // Mark the current node (u) as part of the current recursion stack
        inRecursion[u] = true;
        
        // Iterate through each neighbor (v) of the current node (u)
        for (int &v : adj[u]) {
            // If the neighbor (v) is not visited, perform DFS from the neighbor and check for a cycle
            if (!visited[v] && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            // If the neighbor is in the recursion stack, cycle detected
            else if (inRecursion[v] == true)
                return true;
        }
        
        // Remove the current node (u) from the recursion stack
        inRecursion[u] = false;
        return false;
    }

    // Function to detect cycle in a directed graph
    bool isCyclic(int V, vector<int> adj[]) {
        // Initialize a visited list to keep track of visited nodes
        vector<bool> visited(V, false);
        // Initialize a recursion stack list to keep track of nodes in the current recursion
        vector<bool> inRecursion(V, false);
        
        // Iterate through each node in the graph
        for (int i = 0; i < V; i++) {
            // If the node (i) has not been visited, start a DFS search from it
            if (!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                // If a cycle is detected, return true
                return true;
        }
        
        // If no cycle is detected, return false
        return false;
    }
};

/*Time Complexity:
The time complexity of the isCyclic function is O(V + E), where V is the number of vertices 
and E is the number of edges. This is because the function iterates through each node and performs 
a DFS, which has a complexity of O(V + E).

Space Complexity:
The space complexity is O(V) due to the visited and inRecursion vectors, which keep track of visited 
nodes and nodes in the current recursion stack, respectively. Additionally, the recursive DFS function 
uses stack space that could potentially grow up to the number of vertices in the worst-case scenario.*/