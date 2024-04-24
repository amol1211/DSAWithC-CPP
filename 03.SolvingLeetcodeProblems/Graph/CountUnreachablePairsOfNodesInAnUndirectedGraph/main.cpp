//2316. Count Unreachable Pairs of Nodes in an Undirected Graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent; // Store parent of each node
    vector<int> rank;   // Store rank of each node for union-find operations

    // Function to find the parent of a node using path compression
    int find(int x) {
        if (x == parent[x]) // If the node is its own parent
            return x;

        // Path compression - updating parent of x to its root
        return parent[x] = find(parent[x]); // Recursive call to find parent    
    }

    // Function to perform union of two sets using union by rank
    void Union(int x, int y) {
        int x_parent = find(x); // Find the parent of x
        int y_parent = find(y); // Find the parent of y

        if (x_parent == y_parent) // If x and y are already in the same set
            return;

        if (rank[x_parent] > rank[y_parent]) { // If rank of x's parent is greater
            parent[y_parent] = x_parent; // Make x's parent as parent of y
        } else if (rank[x_parent] < rank[y_parent]) { // If rank of y's parent is greater
            parent[x_parent] = y_parent; // Make y's parent as parent of x
        } else { // If ranks are equal
            parent[x_parent] = y_parent; // Make y's parent as parent of x
            rank[y_parent]++; // Increase rank of y's parent
        }   
    }

    // Function to count pairs of nodes such that they belong to different connected components
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n); // Resize parent vector to n elements
        rank.resize(n, 0); // Resize rank vector to n elements, initialized to 0

        // Initialize each node as its own parent initially
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is initially its own parent
        }
        
        // Form connected components
        for (auto& vec : edges) { // Iterate through each edge
            int u = vec[0]; // First node of edge
            int v = vec[1]; // Second node of edge
            Union(u, v); // Union the sets containing u and v
        }

        // Count sizes of connected components
        unordered_map<int, int> mp; // Map to store parent of each component and their size
        for (int i = 0; i < n; i++) { // Iterate through each node
            int parent = find(i); // Find the parent of current node
            mp[parent]++; // Increment the size of the component
        }

        // Finding pairs from component sizes
        long long result = 0; // Initialize result to count pairs
        long long remainingNodes = n; // Initialize remaining nodes

        for (auto& it : mp) { // Iterate through each component
            long long size = it.second; // Get the size of the component
            result += (size) * (remainingNodes - size); // Count pairs with nodes from this component and other components
            remainingNodes -= size; // Update remaining nodes
        }

        return result; // Return the total count of pairs
     } 
};

/*Time complexity:

Time complexity: O(V + E)
Space complexity: O(V)

*/