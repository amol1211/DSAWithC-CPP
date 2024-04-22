//Detect Cycle using DSU (GFG)

#include <bits/stdc++.h>
using namespace std;

// Define a class named Solution
class Solution
{
    // Declare public member variables
    public:
    vector<int> parent; // Store parent nodes
    vector<int> rank; // Store rank of each node
    
    // Function to find the parent node of a given node
    int find(int x) {
        // If the parent of the node is itself, return the node
        if(parent[x] == x)
            return x;
        
        // Recursively find the parent and update the parent of the current node
        return parent[x] = find(parent[x]);
    }
    
    // Function to perform Union operation on two nodes
    void Union(int x, int y) {
        // Find the parent nodes of x and y
        int x_parent = find(x);
        int y_parent = find(y);
 
        // Compare the ranks of the parent nodes
        if(rank[x_parent] > rank[y_parent]) {
            // If rank of x's parent is greater, make y's parent point to x's parent
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            // If rank of y's parent is greater, make x's parent point to y's parent
            parent[x_parent] = y_parent;
        } else {
            // If ranks are equal, make one parent point to the other and increase rank by 1
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    // Function to detect cycle using Disjoint Set Union (DSU) in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Resize parent and rank vectors to the size of vertices
	    parent.resize(V);
	    rank.resize(V);
	    
	    // Initialize parent and rank vectors
	    for (int i = 0; i < V; i++) {
	        parent[i] = i;
	        rank[i] = 1;
	    }
	    
	    // Iterate through each vertex
	    for (int u = 0; u < V; u++) {
	        // Iterate through adjacent vertices of current vertex
	        for (int &v : adj[u]) {
	            
	            // Ensure u < v to avoid considering edges twice
	            if ( u < v) {
	                // Find parent nodes of u and v
	                int parent_u = find(u);
	                int parent_v = find(v);
	                
	                // If both vertices have the same parent, cycle detected
	                if (parent_u == parent_v)
	                    return true;
	                
	                // Perform Union operation
	                Union(u, v);         
	            }
	        }
	    }
	    
	    // No cycle detected
	    return false;
	}
}; 

/*Time Complexity:

The time complexity of the find function is O(log n) on average, where n is the number of elements in the set.
The time complexity of the Union function is O(log n) on average, where n is the number of elements in the set.
In the detectCycle function, iterating through all edges of the graph takes O(V + E) time, where V is the 
number of vertices and E is the number of edges. For each edge, the find and Union operations take O(log n) 
time on average.
Thus, the overall time complexity of detectCycle is O((V + E) log n) on average.
Space Complexity:

The space complexity is O(V) to store the parent and rank arrays, where V is the number of vertices in the graph.*/
