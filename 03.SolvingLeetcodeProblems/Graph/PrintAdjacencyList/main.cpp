//Print adjacency list (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {
        // Initialize an adjacency list with V vertices
        vector<vector<int>> ans(V);
        
        // Iterate over each edge in the edges list
        for (auto &i: edges) {
            // Retrieve the two vertices (u and v) connected by the current edge
            int u = i.first;
            int v = i.second;
            
            // Add vertex v to the adjacency list of vertex u
            ans[u].push_back(v);
            // Add vertex u to the adjacency list of vertex v
            ans[v].push_back(u);
        }
        
        // Return the adjacency list representation of the graph
        return ans;
    }
};

/*------------------------------------------------*/

class Solution {
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {
        // Initialize an adjacency list with V vertices
        vector<vector<int>> ans(V);
        
        // Iterate through each edge in the edges list using a loop
        for (int i = 0; i < edges.size(); i++) {
            // Retrieve the pair of vertices for the current edge
            pair<int, int> p = edges[i];
            
            int u = p.first;
            int v = p.second;
            
            // Add vertex v to the adjacency list of vertex u
            ans[u].push_back(v);
            // Add vertex u to the adjacency list of vertex v
            ans[v].push_back(u);
        }
        
        // Return the adjacency list representation of the graph
        return ans;
    }
};

/*Time Complexity:
The time complexity of this function is O(E), where E is the number of edges. 
The loop goes through each edge in the list and performs a constant-time operation for each edge.

Space Complexity:
The space complexity is O(V + E). The adjacency list takes up V lists (for each vertex) and the 
total number of elements in these lists is equal to twice the number of edges (since the graph is 
undirected and each edge is stored twice).*/
