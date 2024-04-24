//1319. Number of Operations to Make Network Connected

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Vector to store parent of each node
    vector<int> parent;
    // Vector to store rank of each node
    vector<int> rank;

    // Function to find the parent of a node with path compression
    int find(int x) {
        // If the node is its own parent, return itself
        if (x == parent[x]) 
            return x;
        
        // Path compression: Set the parent of x to its grandparent
        return parent[x] = find(parent[x]);
    }

    // Function to union two sets with union by rank
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        // If they belong to the same set, do nothing
        if (x_parent == y_parent) 
            return;

        // Union by rank: Attach smaller rank tree under root of higher rank tree
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            // If ranks are equal, attach one under the other and increment rank
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
       
    // Function to make the minimum number of connections to make all nodes connected
    int makeConnected(int n, vector<vector<int>>& connections) {
        // If the number of edges is less than n - 1, it's impossible to connect all nodes
        if (connections.size() < n - 1)
            return -1;

        // Initialize parent and rank vectors
        parent.resize(n);
        rank.resize(n, 0);

        // Initially each node is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Counter for connected components
        int components = n;

        // Iterate through connections
        for (auto &vec : connections) {
            // If the two nodes are not in the same set, union them
            if (find(vec[0]) != find(vec[1])) {
                Union(vec[0], vec[1]);
                // Decrement components counter
                components--;
            }
        }    
       
        // The minimum number of connections needed is components - 1
        return components - 1;
    }
};

/*Time complexity:

Time complexity: O(V + E)
Space complexity: O(V)

*/