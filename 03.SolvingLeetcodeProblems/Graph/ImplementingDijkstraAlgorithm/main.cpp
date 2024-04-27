//Implementing Dijkstra Algorithm (GFG)

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : Using priority queue/Min-Heap

class Solution
{
    public:
        // Function to find the shortest distance of all the vertices
        // from the source vertex S.
        vector<int> dijkstra(int V, vector<vector<int>> adj[], int source)
        {
            // Priority queue to store pairs of (distance, node) in ascending order of distance.
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
            
            // Vector to store the shortest distances from the source to all vertices.
            vector<int> result(V, INT_MAX);
            
            // The distance from the source vertex to itself is 0.
            result[source] = 0;
            
            // Pushing the source vertex with distance 0 to the priority queue.
            pq.push({0, source});
            
            // Loop until the priority queue is empty.
            while (!pq.empty()) {
                
                // Extracting the minimum distance node from the priority queue.
                int distance = pq.top().first;
                int node = pq.top().second;
                
                // Removing the extracted node from the priority queue.
                pq.pop();
                
                // Iterating through all adjacent nodes of the current node.
                for (auto &vec: adj[node]) {
                    
                    // Extracting adjacent node and its weight from the adjacency list.
                    int adjNode = vec[0];
                    int wt = vec[1];
                    
                    // If the distance to the adjacent node through the current node is shorter than
                    // the previously calculated distance, update the distance and push it to the priority queue.
                    if (distance + wt < result[adjNode]) {
                        result[adjNode] = distance + wt;
                        pq.push({distance + wt, adjNode});
                    }
                }
            }
            
            // Returning the vector containing the shortest distances from the source vertex.
            return result;
        }
};

/*Time Complexity: The time complexity of Dijkstra's algorithm depends on the data structure 
used for the priority queue. In this implementation, it's using a priority queue which can have 
a time complexity of O((V+E)logV), where V is the number of vertices and E is the number of 
edges in the graph.

Space Complexity: The space complexity of this implementation is O(V + E), where V is the number 
of vertices and E is the number of edges in the graph. This is because it uses a priority queue and 
a vector to store the shortest distances from the source vertex.*/

/*-------------------------------------------------------------------------------------------------------------*/

//Approach 2 : Using set

class Solution
{
    public:
        // Function to find the shortest distance of all the vertices
        // from the source vertex S.
        vector<int> dijkstra(int V, vector<vector<int>> adj[], int source)
        {
            // Creating a set to store pairs of (distance, node).
            set<pair<int, int>> st;
            
            // Vector to store the shortest distances from the source vertex.
            vector<int> result(V, INT_MAX);
            
            // Setting the distance from the source to itself as 0.
            result[source] = 0;
            
            // Inserting the source vertex with distance 0 into the set.
            st.insert({0, source});
            
            // Loop until all nodes have been processed.
            while (!st.empty()) {
                
                // Extracting the minimum distance node from the set.
                auto &it = *st.begin();
                int distance = it.first;
                int node = it.second;
                
                // Removing the extracted node from the set.
                st.erase(it);
                
                // Iterating through all adjacent nodes of the current node.
                for (auto &vec : adj[node]) {
                    
                    // Extracting adjacent node and its weight from the adjacency list.
                    int adjNode = vec[0];
                    int wt = vec[1];
                    
                    // If the distance to the adjacent node through the current node is shorter than
                    // the previously calculated distance, update the distance and update the set.
                    if (distance + wt < result[adjNode]) {
                        
                    // If the adjacent node was already processed and has a distance
                    // greater than the new distance through the current node, remove it from the set.   
                        if (result[adjNode] != INT_MAX) {
                            st.erase({result[adjNode], adjNode});
                        }
                        
                        // Update the distance and insert the updated node into the set.
                        result[adjNode] = distance + wt;
                        st.insert({result[adjNode], adjNode});
                    }
                }
            }
            
            // Returning the vector containing the shortest distances from the source vertex.
            return result;
        }
};

/*Time Complexity: The time complexity of this Dijkstra's algorithm implementation is O((V + E) log V), 
where V is the number of vertices and E is the number of edges in the graph. This is because of the 
usage of a set for maintaining the minimum distance nodes, which has a time complexity of O(log V) 
for insertion and deletion, and the algorithm iterates through all edges once.

Space Complexity: The space complexity of this implementation is O(V), where V is the number of vertices 
in the graph. This is due to the vectors used to store the shortest distances and the set used for 
maintaining the minimum distance nodes.*/