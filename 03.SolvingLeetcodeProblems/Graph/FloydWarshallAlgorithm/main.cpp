//Floyd Warshall Algorithm (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the shortest distances between all pairs of vertices
    void shortest_distance(vector<vector<int>>& grid) {
        
        // Get the size of the grid (number of vertices)
        int n = grid.size();
        
        //Here, when there is no edge we usually take INT_MAX (infinity) so that choosing minimum 
        //value between two values becomes easier but since problem asking to 
	    //take -1, we're simply converting it to some greater value. 
        // Convert -1 entries to a large value (here 100000) to represent infinity
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                // If there is no edge, represent it as a large value
                if(grid[i][j] == -1) 
                    grid[i][j] = 100000;
            }
        }
        
        // Applying Floyd-Warshall algorithm to find shortest distances
        for (int via = 0; via < n; via++) {
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    
                    // Update shortest distance between i and j through vertex 'via'
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }
        
        // Convert large values back to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if(grid[i][j] == 100000)
                    grid[i][j] = -1;
            }
        }
    }
};

/*Time complexity : O(N), where N is the number of vertices. The nested loops iterate over all pairs 
of vertices and for each pair, there's another loop iterating over all vertices again.

Space complexity : O(1), because the space used is not dependent on the input size; it's a constant 
space modification of the input grid.*/
