//Topological sort using DFS

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive function to perform a depth-first search (DFS) and fill the stack
    void DFS(vector<int> adj[], int u, vector<bool> &visited, stack<int> &st) {
        // Mark the current node (u) as visited
        visited[u] = true;
        
        // Iterate through each neighbor (v) of the current node (u)
        for (int &v : adj[u]) {
            // If the neighbor (v) has not been visited, perform DFS from it
            if (!visited[v])
                DFS(adj, v, visited, st);
        }
        
        // Push the current node (u) onto the stack after processing its children
        st.push(u);
    }
    
    // Function to return a list containing vertices in topological order
    vector<int> topoSort(int V, vector<int> adj[]) {
        // Initialize a visited list to keep track of visited nodes
        vector<bool> visited(V, false);
        // Create a stack to hold the topological order
        stack<int> st;
        
        // Perform DFS from each unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                DFS(adj, i, visited, st);
        }
        
        // Initialize a vector to store the topological order
        vector<int> result;
        
        // Pop elements from the stack to get the topological order
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        // Return the topological order
        return result;
    }
};

/*Time Complexity:
The time complexity of the topoSort function is O(V + E), where V is the number of vertices 
and E is the number of edges. This is because the function iterates through each node and performs 
a DFS, which has a complexity of O(V + E).

Space Complexity:
The space complexity is O(V) due to the visited vector, which keeps track of visited nodes, and the 
stack used in the DFS traversal, which can hold a list of nodes to process. Additionally, the result 
vector will hold the topological order of the nodes, contributing further to the space complexity.*/