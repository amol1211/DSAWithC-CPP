//207. Course Schedule

#include <bits/stdc++.h>
using namespace std;

//Using BFS(kanh's algorithm)

class Solution {
public:
    // Function to check if the courses can be finished using a topological sort
    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        // Queue to manage the nodes for topological sort
        queue<int> q;
        // Counter for the number of nodes processed in the topological sort
        int count = 0;

        // Initialize the queue with nodes that have an in-degree of 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                count++;
                q.push(i);
            }
        }

        // Process the queue
        while(!q.empty()) {
            // Get the front node from the queue
            int u = q.front();
            q.pop();

            // Iterate through the neighbors of the current node (u)
            for (int &v : adj[u]) {
                // Decrease the in-degree of the neighbor node (v)
                indegree[v]--;

                // If the neighbor's in-degree is now zero, add it to the queue
                if(indegree[v] == 0) {
                    count++;
                    q.push(v);
                }
            }
        }

        // If count matches the number of courses, it means all courses can be finished
        if(count == n) 
            return true; // All nodes (courses) were visited, so we can finish all courses

        // If count doesn't match the number of courses, it means there's a cycle in the graph
        return false; // There was a cycle, so we can't complete all courses
    }

    // Function to determine if it's possible to finish all courses
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Adjacency list to represent the graph
        unordered_map<int, vector<int>> adj;
        // In-degree vector to keep track of in-degrees of each node (course)
        vector<int> indegree(numCourses, 0);

        // Fill the adjacency list and in-degree vector based on prerequisites
        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // Edge from course b to course a
            adj[b].push_back(a);
            // Increase in-degree for course a
            indegree[a]++;
        }

        // Perform topological sort check
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};


/*Time Complexity:
canFinish function:
Constructing the adjacency list and in-degree array:
Iterates through the prerequisites list (with numCourses edges), taking O(E) time, where E is the number of edges (prerequisites).
Calling topologicalSortCheck function with the adjacency list and in-degree array.
topologicalSortCheck function:
Initial setup to add all nodes with zero in-degree to the queue takes O(V), where V is the number of nodes (courses).
Processing each node in the queue:
Each node is processed once, and each edge is traversed once in the adjacency list.
This results in a total time complexity of O(V + E), where V is the number of nodes (courses) and E is the number of edges (prerequisites).
Overall Time Complexity:
The overall time complexity of the code is O(V + E).

Space Complexity:
canFinish function:
Adjacency list and in-degree array:
Adjacency list stores all edges and takes O(E) space.
In-degree array stores in-degree for each node, taking O(V) space.
Calling topologicalSortCheck function.
topologicalSortCheck function:
Queue and count variables use O(V) space in the worst case.
Overall Space Complexity:
The overall space complexity of the code is O(V) */