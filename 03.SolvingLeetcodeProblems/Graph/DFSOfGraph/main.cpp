//DFS of Graph (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Depth-first search function to traverse the graph
    void dfs(vector<int> adj[], int u, vector<bool> &visited, vector<int> &result) {
        // If the current node (u) is already visited, return immediately
        if (visited[u]) return;

        // Mark the current node (u) as visited
        visited[u] = true;
        // Add the current node to the result list
        result.push_back(u);

        // Iterate through each neighbor (v) of the current node (u)
        for (int &v : adj[u]) {
            // If the neighbor (v) is not visited yet
            if (!visited[v]) {
                // Recursively perform DFS from the neighbor (v)
                dfs(adj, v, visited, result);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Initialize a result list to store the DFS traversal
        vector<int> result;
        // Initialize a visited list to keep track of visited nodes
        vector<bool> visited(V, false);

        // Perform DFS starting from node 0
        dfs(adj, 0, visited, result);

        // Return the result list containing the DFS traversal
        return result;
    }
};

/*Time Complexity:
The time complexity of the dfsOfGraph function is O(V + E), where V is the number 
of vertices and E is the number of edges. This is because the depth-first search (DFS) 
traverses each node once and explores each edge exactly once.

Space Complexity:
The space complexity is O(V) due to the visited vector, which keeps track of visited nodes. 
Additionally, the function uses a result vector to store the traversal, which also contributes 
to the space complexity.*/