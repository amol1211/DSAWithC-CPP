//Strongly Connected Components (Kosaraju's Algo)

#include <bits/stdc++.h>
using namespace std;

// This class represents a solution for finding the number of strongly connected components in a graph using Kosaraju's algorithm.

class Solution
{
    public:
    
    // Function to perform depth-first search and fill the stack.
    // Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
    // Space Complexity: O(V) for the visited array and O(V) for the stack.
    void dfsFill(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
        visited[u] = true;
        for (int &v : adj[u]) {
            if (!visited[v]) {
                dfsFill(v, adj, visited, st);
            }
        }
        st.push(u);
    }
    
    // Function to perform depth-first search traversal.
    // Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
    // Space Complexity: O(V) for the visited array.
    void dfsTraversal(int u, vector<vector<int>> &adjReversed, vector<bool> &visited) {
        visited[u] = true;
        for (int &v : adjReversed[u]) {
            if (!visited[v]) {
                dfsTraversal(v, adjReversed, visited);
            }
        }
    }
    
    // Function to find the number of strongly connected components in the graph using Kosaraju's algorithm.

    int kosaraju(int V, vector<vector<int>>& adj) {
        // Step 1: Storing the order of DFS traversal in a stack (topological sort).
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }
        
        // Step 2: Creating the reversed graph.
        vector<vector<int>> adjReversed(V);
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                adjReversed[v].push_back(u);
            }
        }
        
        // Step 3: Performing DFS traversal based on the stack order to count the SCCs.
        int countScc = 0;
        visited = vector<bool>(V, false);
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                dfsTraversal(node, adjReversed, visited);
                countScc++;
            }
        }
        
        return countScc;
    }
};


/*    // Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
    // Space Complexity: O(V + E) for the stack, visited arrays, and the reversed adjacency list.*/