//Topological sort using BFS (Kanh's algorithm) (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing vertices in topological order
    vector<int> topoSort(int V, vector<int> adj[]) {
        // Create a queue for managing vertices with in-degree 0
        queue<int> q;
        // Initialize an array to track the in-degree of each vertex
        vector<int> inDegree(V, 0);
        
        // 1. Calculate in-degrees of all vertices
        for (int u = 0; u < V; u++) {
            // Iterate through each neighbor (v) of the current vertex (u)
            for (int &v : adj[u]) {
                // Increment the in-degree of neighbor (v)
                inDegree[v]++;
            }
        }
        
        // 2. Find vertices with in-degree 0 and enqueue them
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // 3. Perform a BFS-like traversal to obtain topological order
        vector<int> result;
        while (!q.empty()) {
            // Get the vertex (u) from the front of the queue
            int u = q.front();
            q.pop();
            // Add the vertex (u) to the result
            result.push_back(u);
            
            // Iterate through each neighbor (v) of the current vertex (u)
            for (int &v : adj[u]) {
                // Decrement the in-degree of neighbor (v)
                inDegree[v]--;
                
                // If neighbor (v) now has in-degree 0, enqueue it
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Return the topological order as the result
        return result;
    }
};

/*Time Complexity:
The time complexity of the topoSort function is O(V + E), where V is the number of vertices 
and E is the number of edges. This is because the function calculates the in-degree of each 
vertex and then performs a BFS-like traversal to obtain the topological order.

Space Complexity:
The space complexity is O(V) due to the inDegree array, which keeps track of the in-degree of 
each vertex, and the queue used in the BFS-like traversal, which can hold a list of vertices to 
process. Additionally, the result vector will hold the topological order of the nodes, contributing 
further to the space complexity.*/