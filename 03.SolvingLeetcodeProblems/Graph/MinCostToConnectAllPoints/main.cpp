//1584. Min Cost to Connect All Points

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P; // Pair of integers, representing weight and node

    // Function to implement Prim's algorithm
    int primsAlgo(vector<vector<P>> &adj, int V) {

        priority_queue<P, vector<P>, greater<P>> pq; // Priority queue to store pairs of weight and node, sorted by weight

        pq.push({0, 0}); // Start with node 0 and weight 0
        vector<bool> inMST(V, false); // Visited array to check whether node is added in MST or not
        int sum = 0; // Initialize sum of weights
        
        // Loop until priority queue is not empty
        while (!pq.empty()) {

            auto p = pq.top(); // Get the pair with minimum weight
            pq.pop();

            int wt = p.first; // Weight of edge
            int node = p.second; // Node

            if (inMST[node] == true) // If node is already in MST, skip it
                continue;

            inMST[node] = true; // Mark node as added in MST 
            sum += wt; // Add weight to total sum

            // Loop through adjacent nodes
            for (auto &temp : adj[node]) {

                int neighbour = temp.first; // Get neighbour node
                int neighbour_wt = temp.second; // Get weight of edge to neighbour

                // If neighbour is not in MST, add its edge to priority queue
                if (inMST[neighbour] == false) {
                    pq.push({neighbour_wt, neighbour});
                }
            }    
        }

        return sum; // Return total sum of weights of MST edges
    }

    // Function to find minimum cost to connect all points
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size(); // Get number of points

        vector<vector<P>> adj(V); // Create adjacency list to store edges and their weights

        // Construct adjacency list
        for (int i = 0; i < V; i++) {
            
            for (int j = i + 1; j < V; j++) {

                int x1 = points[i][0]; // x-coordinate of point i
                int y1 = points[i][1]; // y-coordinate of point i

                int x2 = points[j][0]; // x-coordinate of point j
                int y2 = points[j][1]; // y-coordinate of point j

                int cost = abs(x1 - x2) + abs(y1 - y2); // Calculate Manhattan distance between points i and j

                adj[i].push_back({j, cost}); // Add edge from point i to point j with weight 'cost'
                adj[j].push_back({i, cost}); // Add edge from point j to point i with weight 'cost'
            }
        }

        return primsAlgo(adj, V); // Call Prim's algorithm to find minimum spanning tree and return its total weight
    }
};


/*The time complexity of this algorithm is : O(V^2) because we're constructing the complete graph with V vertices and then running Prim's algorithm, which takes O(V*log(V)) time. 

The space complexity is O(V^2) for storing the adjacency list.*/