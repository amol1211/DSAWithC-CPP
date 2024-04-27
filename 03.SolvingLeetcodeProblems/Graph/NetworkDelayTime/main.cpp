//743. Network Delay Time

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum time it takes for a signal to reach all nodes in the network
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency list representation of the graph
        unordered_map<int, vector<pair<int, int>>> adj;

        // Constructing the adjacency list
        for (auto &vec: times) {
            int u = vec[0]; // Source node of the edge
            int v = vec[1]; // Destination node of the edge
            int time = vec[2]; // Time taken to travel from source to destination
            adj[u].push_back({v, time}); // Adding the edge (u, v) with its time to the adjacency list
        }

        // Min-heap to store nodes based on their minimum distance from the source node
        priority_queue<pair<int,int>,  vector<pair<int, int>> , greater<pair<int, int>>> pq;

        // Array to store the minimum time it takes to reach each node from the source
        vector<int> result(n + 1, INT_MAX);

        // The time taken to reach the source node from itself is 0
        result[k] = 0;

        // Pushing the source node into the priority queue with distance 0
        pq.push({0, k});

        // Dijkstra's algorithm to find the shortest path from the source node to all other nodes
        while (!pq.empty()) {
            int distance = pq.top().first; // Current distance from the source node
            int node = pq.top().second; // Current node
            pq.pop(); // Remove the current node from the priority queue

            // Traverse all neighbors of the current node
            for (auto &vec: adj[node]) {
                int adjNode = vec.first; // Neighbor node
                int wt = vec.second; // Time taken to travel to the neighbor node

                // If a shorter path is found to the neighbor, update its time and push it into the priority queue
                if (distance + wt < result[adjNode]) {
                    result[adjNode] = distance + wt; // Update the time to reach the neighbor node
                    pq.push({distance + wt, adjNode}); // Push the updated time and neighbor node into the priority queue
                }
            }
        }

        int ans = INT_MIN;

        // Finding the maximum time taken to reach any node
        for (int i = 1; i <= n; i++) {
            ans = max(ans, result[i]); // Update ans if the time to reach node i is greater
        }

        // If there exists at least one node that cannot be reached, return -1, otherwise return the maximum time
        return ans == INT_MAX ? -1 : ans;
    }
};

/*Time Complexity:

Constructing the adjacency list: O(m), where m is the number of edges (size of the "times" vector).
Dijkstra's algorithm: O((n + m) * log(n)), where n is the number of nodes and m is the number of edges. 
This is because each edge is relaxed at most once, and each relaxation takes O(log(n)) time with the priority 
queue implementation.
Finding the maximum time: O(n), where n is the number of nodes.
Overall time complexity: O((n + m) * log(n))

Space Complexity:

Adjacency list: O(n + m), where n is the number of nodes and m is the number of edges.
Priority queue: O(n), to store nodes.
Other arrays: O(n), for result vector.
Overall space complexity: O(n + m)*/