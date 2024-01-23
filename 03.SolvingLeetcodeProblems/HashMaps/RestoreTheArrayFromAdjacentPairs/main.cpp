//1743. Restore the Array From Adjacent Pairs

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// Class Solution providing a method to restore an array from its adjacent pairs.

class Solution {
public:
    // Vector to store the result of the restored array.
    vector<int> result;

    // Depth-first search (DFS) function to traverse the graph and restore the array.
    void dfs(int u, int prev, unordered_map<int, vector<int>> &adj) {
        // Add the current element to the result vector.
        result.push_back(u);

        // Traverse adjacent elements in the graph.
        for (int &v : adj[u]) {
            // If the adjacent element is not the previous one, perform DFS.
            if (v != prev) {
                dfs(v, u, adj);
            }
        }
    }

    // Function to restore the array from adjacent pairs.
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // Adjacency list to represent the graph.
        unordered_map<int, vector<int>> adj;

        // Populate the adjacency list based on the given adjacent pairs.
        for (vector<int> &vec : adjacentPairs) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Find the starting point of the array.
        int startPoint = -1;

        for (auto &it : adj) {
            if (it.second.size() == 1) {
                startPoint = it.first;
                break;
            }
        }

        // Perform DFS to restore the array.
        dfs(startPoint, INT_MIN, adj); // INT_MIN = previous element in the adjacency vector

        // Return the restored array.
        return result;
    }
};

// Time Complexity: O(N), where N is the number of elements in the array.
// Space Complexity: O(N), for the result vector and adjacency list.
