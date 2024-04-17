//Detect cycle in a directed graph using BFS (Using kanh's algo) (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph using a topological sort approach
    bool isCyclic(int V, vector<int> adj[]) {
        // Initialize a queue for managing vertices with in-degree 0
        queue<int> q;
        
        // Initialize an array to track the in-degree of each vertex
        vector<int> inDegree(V, 0);
        
        // Populate in-degree of all the vertices
        for (int u = 0; u < V; u++) {
            // Iterate through each neighbor (v) of the current vertex (u)
            for (int &v : adj[u]) {
                // Increment the in-degree of neighbor (v)
                inDegree[v]++;
            }
        }
        
        // Initialize a counter to track the number of processed vertices
        int count = 0;
        
        // 2. Fill queue with vertices whose in-degree is 0
        for (int i = 0; i < V; i++) {
            // If the vertex has in-degree 0, enqueue it
            if (inDegree[i] == 0) {
                q.push(i);
                // Increment the counter for processed vertices
                count++;
            }
        }
        
        // 3. Perform a BFS-like traversal
        while (!q.empty()) {
            // Get the vertex (u) from the front of the queue
            int u = q.front();
            q.pop();
            
            // Iterate through each neighbor (v) of the current vertex (u)
            for (int &v : adj[u]) {
                // Decrement the in-degree of neighbor (v)
                inDegree[v]--;
                
                // If neighbor (v) now has in-degree 0, enqueue it and increment the counter
                if (inDegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }
        
        // If we visited all nodes, there is no cycle
        if (count == V) {
            return false;
        }
        
        // If we did not visit all nodes, a cycle was found
        return true;
    }
};

/*Time Complexity:
The time complexity of the isCyclic function is O(V + E), where V is the number of vertices and E 
is the number of edges. This is because the function calculates the in-degree of each vertex and then 
performs a BFS-like traversal to detect cycles.

Space Complexity:
The space complexity is O(V) due to the inDegree array, which keeps track of the in-degree of each vertex, 
and the queue used in the BFS-like traversal, which can hold a list of vertices to process. Additionally, 
some space is needed for the adjacency list representation of the graph.*/
