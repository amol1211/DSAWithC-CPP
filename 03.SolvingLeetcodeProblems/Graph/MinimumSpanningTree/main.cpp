//Minimum Spanning Tree (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution
{   
    typedef pair<int, int> P; // Pair of integers, representing weight and node

	public:
	// Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Priority queue to store pairs of weight and node, sorted by weight
        priority_queue<P, vector<P>, greater<P>> pq;
        //{wt, node}
        
        pq.push({0, 0}); // Start with node 0 and weight 0
        vector<bool> inMST(V, false); // Visited array to check whether node is added in MST or not
        int sum = 0; // Initialize sum of weights
        
        // Loop until priority queue is not empty
        while (!pq.empty()) {
            
            auto p = pq.top(); // Get the pair with minimum weight
            pq.pop();
            
            int wt = p.first; // Weight of edge
            int node = p.second; // Node
            
            if (inMST[node] == true) // If node is already in MST, skip it
                continue;
                
            inMST[node] = true; // Mark node as added in MST 
            sum += wt; // Add weight to total sum
            
            // Loop through adjacent nodes
            for (auto &temp : adj[node]) {
                
                int neighbour = temp[0]; // Get neighbour node
                int neighbour_wt = temp[1]; // Get weight of edge to neighbour
                
                // If neighbour is not in MST, add its edge to priority queue
                if (inMST[neighbour] == false) {
                    pq.push({neighbour_wt, neighbour});
                }
            }
        }
        
        return sum; // Return total sum of weights of MST edges
    }
}; 

/*Time complexity of this algorithm is  : O(E*log(V)), where E is the number of edges and V is the number of vertices. 

Space complexity is O(V) for the visited array and priority queue.*/

