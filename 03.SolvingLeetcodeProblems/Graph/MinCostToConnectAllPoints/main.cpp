//1584. Min Cost to Connect All Points

#include <bits/stdc++.h>
using namespace std;

//Appraoch 1 : Using Prim's Algorithm

class Solution {
public:
    typedef pair<int, int> P; // Pair of integers, representing weight and node

    // Function to implement Prim's algorithm
    int primsAlgo(vector<vector<P>> &adj, int V) {

        priority_queue<P, vector<P>, greater<P>> pq; // Priority queue to store pairs of weight and node, sorted by weight

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

                int neighbour = temp.first; // Get neighbour node
                int neighbour_wt = temp.second; // Get weight of edge to neighbour

                // If neighbour is not in MST, add its edge to priority queue
                if (inMST[neighbour] == false) {
                    pq.push({neighbour_wt, neighbour});
                }
            }    
        }

        return sum; // Return total sum of weights of MST edges
    }

    // Function to find minimum cost to connect all points
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size(); // Get number of points

        vector<vector<P>> adj(V); // Create adjacency list to store edges and their weights

        // Construct adjacency list
        for (int i = 0; i < V; i++) {
            
            for (int j = i + 1; j < V; j++) {

                int x1 = points[i][0]; // x-coordinate of point i
                int y1 = points[i][1]; // y-coordinate of point i

                int x2 = points[j][0]; // x-coordinate of point j
                int y2 = points[j][1]; // y-coordinate of point j

                int cost = abs(x1 - x2) + abs(y1 - y2); // Calculate Manhattan distance between points i and j

                adj[i].push_back({j, cost}); // Add edge from point i to point j with weight 'cost'
                adj[j].push_back({i, cost}); // Add edge from point j to point i with weight 'cost'
            }
        }

        return primsAlgo(adj, V); // Call Prim's algorithm to find minimum spanning tree and return its total weight
    }
};


/*The time complexity of this algorithm is : O(V^2) because we're constructing the complete graph with V vertices and then running Prim's algorithm, which takes O(V*log(V)) time. 

The space complexity is O(V^2) for storing the adjacency list.*/

/*-----------------------------------------------------------------------------*/

//Approach 2 : Using Kruskal's Algorithm

class Solution {
public:
    // Vector to store the parent of each vertex
    vector<int> parent;
    // Vector to store the rank of each vertex for Union-Find
    vector<int> rank;

    // Find function for Union-Find algorithm
    int find (int x) {
        // If x is its own parent, return x
        if (x == parent[x])
            return x;

        // Path compression: Set parent of x to its root and return root
        return parent[x] = find(parent[x]);    
    }

    // Union function for Union-Find algorithm
    void Union (int x, int y) {
        // Find the parents of x and y
        int x_parent = find(x);
        int y_parent = find(y);

        // If they have the same parent, they are already in the same set
        if (x_parent == y_parent)
            return;

        // Union by rank: Attach the tree with smaller rank to the tree with larger rank
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            // If ranks are equal, attach one tree to the other and increase its rank
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }  
    }

    // Kruskal's Algorithm for finding Minimum Spanning Tree
    int kruskalAlgo(vector<vector<int>> &vec) {

        int sum = 0;
        // Iterate over the edges in increasing order of weight
        for (auto &temp : vec) {

            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            // Find the parents of u and v
            int parent_u = find(u);
            int parent_v = find(v);

            // If parents are different, adding this edge to MST won't form a cycle
            if (parent_u != parent_v) {
                Union(u, v); // Union the sets of u and v
                sum += wt; // Add weight of this edge to the total cost of MST
            }
        }

        return sum; // Return total cost of MST
    }

    // Function to find minimum cost of connecting all points
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size(); // Number of vertices

        // Initialize parent and rank vectors for Union-Find
        parent.resize(V);
        rank.resize(V, 0);

        // Initially each vertex is its own parent
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        // Vector to store edges and their weights
        vector<vector<int>> vec;

        // Calculate cost of each edge and store in vec
        for (int i = 0; i < V; i++) {

            for (int j = i + 1; j < V; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // Calculate Manhattan distance between two points
                int cost = abs(x1 - x2) + abs(y1 - y2);

                // Store edge and its weight in vec
                vec.push_back({i, j, cost});
            }
        }

        // Comparator for sorting edges based on weight
        auto comparator = [&](vector<int> &v1, vector<int> &v2) {

            return v1[2] < v2[2];
        };

        // Sort edges based on weight
        sort(vec.begin(), vec.end(), comparator);

        // Apply Kruskal's Algorithm to find Minimum Spanning Tree
        return kruskalAlgo(vec);
    }
}; 

/*Time Complexity:

The time complexity of the Union-Find operations (find and union) depends on the implementation 
of the Union-Find data structure, which uses path compression and union by rank. In this implementation, 
the time complexity of both find and union operations is nearly constant on average. Therefore, the time 
complexity of both operations can be considered approximately O(α(N)), where α(N) is the inverse Ackermann 
function, which grows extremely slowly and can be considered effectively constant for practical purposes.
Sorting the edges based on weight takes O(E log E) time, where E is the number of edges.
Applying Kruskal's algorithm involves iterating over all edges once, which takes O(E) time.

Overall, the time complexity is dominated by the sorting step, so the total time complexity is O(E log E), 
where E is the number of edges.

Space Complexity:

The space complexity is primarily determined by the parent and rank arrays used for the Union-Find data 
structure. Both arrays have a size of V, where V is the number of vertices.
Additionally, the vector vec stores all edges, which can have a maximum of O(V^2) entries.
Therefore, the space complexity is O(V) for the parent and rank arrays, and O(V^2) for the vec vector.

Overall, the space complexity is O(V^2) due to the vec vector.*/