//Distance from the Source (Bellman-Ford Algorithm) (GFG)

#include <bits/stdc++.h>
using namespace std;

//Here, we used 1e8 instead of INT_MAX as mentioned in the problem

class Solution {
public:
    // Function to implement Bellman Ford
    // edges: vector of vectors which represents the graph
    // S: source vertex to start traversing graph with
    // V: number of vertices
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        // Initialize a vector to store the shortest distances from source to all vertices
        vector<int> result(V, 1e8); // Initializing all distances as infinity
        result[S] = 0; // Distance from source to itself is 0
        
        // Relax edges repeatedly V-1 times
        for (int count = 1; count <= V - 1; count++) {
            
            // Iterate through all edges
            for (auto &edge : edges) {
                
                // Extracting edge information: source, destination, and weight
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                // Relax the edge if there is a shorter path found
                if (result[u] != 1e8 && result[u] + w < result[v]) {
                    result[v] = result[u] + w; // Update shortest distance to destination
                }
            }
        }
        
        // Detecting negative weight cycles
        for (auto &edge : edges) {
                
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
                
            // If a shorter path is found even after V-1 iterations, there is a negative weight cycle
            if (result[u] != 1e8 && result[u] + w < result[v]) {
                return {-1}; // Return -1 to indicate presence of negative cycle
            }
        }
        
        // Return the shortest distances from source to all vertices
        return result;
        
    }
};

/*Time Complexity: 
O(V×E), where V is the number of vertices and E is the number of edges.
Space Complexity: O(V), where V is the number of vertices, for storing the 
shortest distances from the source vertex.*/
