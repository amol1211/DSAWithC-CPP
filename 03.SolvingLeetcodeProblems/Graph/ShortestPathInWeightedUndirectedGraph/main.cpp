//Shortest Path in Weighted undirected graph (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the shortest path in a graph
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        // Adjacency list representation of the graph
        unordered_map<int, vector<pair<int, int>>> adj;
        
        // Constructing the adjacency list
        for (auto &vec : edges) {
            int u = vec[0]; // Source vertex of the edge
            int v = vec[1]; // Destination vertex of the edge
            int wt = vec[2]; // Weight of the edge
            adj[u].push_back({v, wt}); // Adding edge (u, v) to the adjacency list
            adj[v].push_back({u, wt}); // Adding edge (v, u) to the adjacency list (undirected graph)
        }
        
        // Min-heap to store vertices based on their distance from the source
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Array to store the shortest distance from the source to each vertex
        vector<int> result(n + 1, INT_MAX);
        
        // Array to store the parent of each vertex in the shortest path tree
        vector<int> parent(n + 1);
        
        // Initialize parent array
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        // Distance from source to itself is 0
        result[1] = 0;
        pq.push({0, 1}); // Pushing source vertex into the priority queue with distance 0
        
        // Dijkstra's algorithm to find shortest paths
        while (!pq.empty()) {
            int d = pq.top().first; // Current distance from the source
            int node = pq.top().second; // Current node
            pq.pop(); // Remove the current node from the priority queue
            
            // Traverse all neighbors of the current node
            for (auto &it : adj[node]) {
                int adjNode = it.first; // Neighbor vertex
                int distance = it.second; // Distance from current node to neighbor
                
                // If a shorter path is found to the neighbor, update its distance and parent
                if (d + distance < result[adjNode]) {
                    result[adjNode] = d + distance;
                    pq.push({d + distance, adjNode}); // Push the updated distance and vertex into the priority queue
                    parent[adjNode] = node; // Update parent of the neighbor
                }
            }
        }
        
        // Reconstruct the shortest path from source to destination
        int destinationNode = n; // Destination vertex
        vector<int> path; // Vector to store the shortest path
        
        // If destination is unreachable, return {-1}
        if (result[destinationNode] == INT_MAX)
            return {-1};
            
        // Traverse from destination to source to reconstruct the path
        while (parent[destinationNode] != destinationNode) {
            path.push_back(destinationNode); // Add current vertex to the path
            destinationNode = parent[destinationNode]; // Move to the parent
        }
        
        path.push_back(1); // Add the source vertex to the path
        reverse(begin(path), end(path)); // Reverse the path to get source to destination order
        
        // Return the shortest path
        return path;
    }
};

/*Time Complexity:

Constructing the adjacency list: O(m), where m is the number of edges.
Dijkstra's algorithm: O((n + m) * log(n)), where n is the number of vertices and m is the number 
of edges. This is because each edge is relaxed at most once, and each relaxation takes O(log(n)) 
time with the priority queue implementation.
Reconstructing the shortest path: O(n), where n is the number of vertices.
Overall time complexity: O((n + m) * log(n))

Space Complexity:

Adjacency list: O(n + m), where n is the number of vertices and m is the number of edges.
Priority queue: O(n), to store vertices.
Other arrays: O(n), for result, parent, and path vectors.
Overall space complexity: O(n + m)*/
