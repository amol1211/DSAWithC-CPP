//Bipartite Graph (GFG)

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : DFS approach

class Solution {
private:
    // Function to check if the graph is bipartite using DFS
    bool checkBipartiteDFS(vector<int> adj[], int curr, vector<int>& color, int currColor) {
        color[curr] = currColor; // color current node

        // Now will go to adjacent nodes
        for (int &v : adj[curr]) {
            // If adjacent node has same color as current node, not bipartite
            if (color[v] == color[curr])
                return false;

            // If adjacent node is not colored yet (never visited)
            if (color[v] == -1) {
                int colorOfV = 1 - currColor;
                // Recursively check bipartiteness of adjacent node
                if (checkBipartiteDFS(adj, v, color, colorOfV) == false)
                    return false;
            }
        }

        return true;
    }

public:
    // Main function to check if the graph is bipartite
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1); // No color in the beginning

        // Red = 1, Green = 0
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                // If current component is not bipartite, return false
                if (checkBipartiteDFS(adj, i, color, 1) == false)
                    return false;
            }
        }

        return true;
    }
};

/*Time Complexity: In the worst-case scenario, where we have to visit every node and edge once, 
the time complexity is O(V + E), where V is the number of vertices and E is the number of edges in the graph.

Space Complexity: The space complexity is O(V), where V is the number of vertices, due to the color 
array storing colors for each vertex.*/

/*--------------------------------------------------------------------------------------------------------------*/

//Approach 2 : BFS approach

class Solution {
private:
    // Function to check if the graph is bipartite using BFS
    bool checkBipartiteBFS(vector<int> adj[], int currNode, vector<int>& color, int currColor) {
        queue<int> q;
        q.push(currNode);
        color[currNode] = currColor;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int &v : adj[u]) {
                // If adjacent node has same color as current node, not bipartite
                if (color[v] == color[u])
                    return false;
                // If adjacent node is not colored yet (never visited)
                else if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }

        return true;
    }

public:
    // Main function to check if the graph is bipartite
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);

        // Red = 1, Green = 0
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                // If current component is not bipartite, return false
                if (checkBipartiteBFS(adj, i, color, 1) == false)
                    return false;
            }
        }

        return true;
    }
};

/*Time Complexity: Similar to the DFS approach, the time complexity is O(V + E), where V is 
the number of vertices and E is the number of edges in the graph.

Space Complexity: The space complexity is O(V), where V is the number of vertices, due to the 
color array storing colors for each vertex, and the queue storing at most all vertices in the worst case.*/