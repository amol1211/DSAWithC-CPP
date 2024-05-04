//Minimum Spanning Tree using Kruskal's Algorithm

#include <bits/stdc++.h>
using namespace std;

// Declaration of Solution class
class Solution
{
	public:
	
	// Declaration of parent and rank vectors
	vector<int> parent;
    vector<int> rank;

    // Function to find the parent of a node with path compression
    // Time complexity: O(log N), Space complexity: O(N)
    int find (int x) {
        if (x == parent[x]) 
           return x;

        return parent[x] = find(parent[x]);
    }

    // Function to perform union of two sets by rank
    // Time complexity: O(1), Space complexity: O(1)
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
       }
    }
	
	// Function to implement Kruskal's algorithm
	// Time complexity: O(E * log E), Space complexity: O(E)
	int kruskalAlgo(vector<vector<int>> &vec) {
	    
	    int sum = 0;
	    //E * (4 * Alpha)
	    for (auto &temp : vec) {
	        
	        int u = temp[0];
	        int v = temp[1];
	        int wt = temp[2];
	        
	        int parent_u = find(u);
	        int parent_v = find(v);
	        
	        if (parent_u != parent_v) {
	            
	            Union(u, v);
	            sum += wt;
	        }
	    }
	    
	    return sum;
	}
	
	// Function to find sum of weights of edges of the Minimum Spanning Tree.
    // Time complexity: O(V + E * log E), Space complexity: O(V + E)
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        parent.resize(V);
        rank.resize(V, 0);
        
        // Initializing parent vector
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        
        vector<vector<int>> vec;
        //O(V + E)
        for (int u = 0; u < V; u++) {
            
            for (auto &temp : adj[u]) {
                
                int v = temp[0];
                int wt = temp[1];
                
                vec.push_back({u, v, wt});
            }
        }
        
        // Comparator function for sorting edges based on weight
        auto comparator = [&](vector<int> vec1, vector<int> vec2) {
            
            return vec1[2] < vec2[2];
        };
        
        // Sorting edges based on weight
        // Time complexity: O(E * log E)
        sort(vec.begin(), vec.end(), comparator);
        
        // Calling Kruskal's algorithm
        return kruskalAlgo(vec);
    }
}; 

/*Time Complexity:

For the spanningTree function:
Initializing parent vector: O(V)
Constructing the edge list: O(V + E)
Sorting the edge list: O(E * log E)
Calling Kruskal's algorithm: O(E * log E)
Total: O(V + E * log E)
For Kruskal's algorithm (kruskalAlgo function):
Processing each edge: O(E * log E) (with path compression and union by rank)
Total: O(E * log E)

So, the overall time complexity is O(E * log E) for both functions.

Space Complexity:

For the parent and rank vectors: O(V)
For the edge list: O(E)
Total: O(V + E)

Thus, the overall space complexity is O(V + E).*/

