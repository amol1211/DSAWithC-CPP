//3243. Shortest Distance After Road Addition Queries I

//Approach 1 : BFS

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // This function performs a Breadth-First Search (BFS) to find the shortest path from node 0 to node n-1.
    int bfs(int n, unordered_map<int, vector<int>>& adj) {
        queue<int> que;              // Queue to store nodes for BFS traversal.
        que.push(0);                 // Push the source node (0) into the queue.
        vector<bool> visited(n, false); // Keeps track of visited nodes.
        visited[0] = true;           // Mark the source node as visited.

        int level = 0;               // `level` represents the current distance from the source node.
        while (!que.empty()) {       // Continue BFS until the queue is empty.
            int size = que.size();   // Number of nodes at the current level.
            while (size--) {         // Process all nodes at the current level.
                int node = que.front(); // Get the front node in the queue.
                que.pop();           // Remove it from the queue.

                if (node == n - 1) { // If the destination node is reached, return the level (distance).
                    return level;
                }

                for (int& nbr : adj[node]) { // Traverse all neighbors of the current node.
                    if (!visited[nbr]) {    // If the neighbor hasn't been visited:
                        que.push(nbr);      // Add it to the queue for future exploration.
                        visited[nbr] = true; // Mark it as visited.
                    }
                }
            }
            level++; // Increase the level after processing all nodes at the current level.
        }

        return -1; // If the destination node can't be reached, return -1.
    }

    // This function calculates the shortest distance after each query modifies the graph.
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj; // Adjacency list to represent the graph.

        // Initialize the graph with default edges: each node points to the next node.
        for (int i = 0; i <= n - 2; i++) {
            adj[i].push_back(i + 1);
        }

        int q = queries.size();      // Total number of queries.
        vector<int> answer;          // Stores the results for each query.

        for (auto& query : queries) { // Process each query:
            int u = query[0];        // Extract the source node.
            int v = query[1];        // Extract the destination node.

            adj[u].push_back(v);     // Add the new edge (u -> v) to the graph.

            int distance = bfs(n, adj); // Calculate the shortest distance using BFS.
            answer.push_back(distance); // Append the result to the answer.
        }

        return answer;               // Return the results of all queries.
    }
};

/*Time Complexity: O(Q ⋅ V log V)  
Space Complexity: O(V)
*/

/*-------------------------------------------*/

//Approach 2  - Dijkstra

class Solution {
public:
#define P pair<int, int> // Define a pair type alias for better readability

    // Function to perform Dijkstra's algorithm
    int dijkstra(int n, unordered_map<int, vector<P>>& adj) {
        vector<int> result(n, INT_MAX); // Stores shortest distances to each node
        result[0] = 0; // Source node distance to itself is 0

        priority_queue<P, vector<P>, greater<P>> pq; // Min-heap to process nodes
        pq.push({0, 0}); // Push source node with distance 0

        while (!pq.empty()) {
            int distance = pq.top().first; // Current distance
            int currentNode = pq.top().second; // Current node
            pq.pop();

            // If we reach the target node (n-1), return its distance
            if (currentNode == n - 1) {
                return result[n - 1];
            }

            // Traverse all adjacent nodes
            for (auto& p : adj[currentNode]) {
                int adjNode = p.first; // Neighbor node
                int edgeWeight = p.second; // Weight of the edge to the neighbor

                // Update the shortest distance if a better path is found
                if (distance + edgeWeight < result[adjNode]) {
                    result[adjNode] = distance + edgeWeight; 
                    pq.push({distance + edgeWeight, adjNode}); // Add updated distance and node to the heap
                }
            }
        }

        return result[n - 1]; // Return the shortest distance to node n-1
    }

    // Main function to find shortest distances after processing queries
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<P>> adj; // Adjacency list to represent the graph

        // Initialize the graph with edges of weight 1 between consecutive nodes
        for (int i = 0; i <= n - 2; i++) {
            adj[i].push_back({i + 1, 1});
        }

        vector<int> answer; // Store results for each query

        // Process each query
        for (auto& query : queries) {
            int u = query[0]; // Start of the edge
            int v = query[1]; // End of the edge

            adj[u].push_back({v, 1}); // Add the new edge to the graph

            // Compute shortest distance from 0 to n-1 after adding the edge
            int distance = dijkstra(n, adj);
            answer.push_back(distance); // Append the result
        }

        return answer; // Return all results
    }
};

/*Time Complexity: O(Q ⋅ V log V)  
Space Complexity: O(V + E)
*/