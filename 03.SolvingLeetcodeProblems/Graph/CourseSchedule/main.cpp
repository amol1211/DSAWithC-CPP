//207. Course Schedule

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : Using BFS(kanh's algorithm)

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

/*------------------------------------------------------------------------------------------------------------------------*/

//Approach 2 : Using DFS

class Solution {
private:
    // Helper function that performs DFS to check for cycles
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecursion) {
        // Mark the current node as visited
        visited[u] = true;
        // Mark the current node as being in recursion stack
        inRecursion[u] = true;

        // Iterate through each neighbor of the current node
        for (int &v : adj[u]) {
            // If the neighbor has not been visited and there is a cycle in the DFS path
            if (!visited[v] && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            // If the neighbor is already in recursion stack, a cycle is detected
            else if (inRecursion[v] == true)
                return true;    
        }

        // Remove the current node from recursion stack
        inRecursion[u] = false;

        // Return false if no cycle is detected
        return false;
    }    
public:
    // Function to check if all courses can be finished
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Create an adjacency list to represent the graph
        unordered_map<int, vector<int>> adj;

        // Vector to track visited nodes
        vector<bool> visited(numCourses, false);

        // Vector to track nodes in recursion stack
        vector<bool> inRecursion(numCourses, false);

        // Populate the adjacency list based on the prerequisites
        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // Add a directed edge from `b` to `a` in the graph
            adj[b].push_back(a);
        }

        // Iterate through each course
        for (int i = 0; i < numCourses; i++) {
            // If the course is not visited and a cycle is found, return false
            if (!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return false; // Cannot complete all courses if there's a cycle
        }

        // If no cycles are found, all courses can be completed
        return true; // Can complete all the courses
    }
};

// Time Complexity: O(E + V)
// - Where E represents the number of edges (prerequisites) and V represents the number of vertices (courses).
// - The time complexity comes from traversing all the nodes (V) and edges (E) in the graph.

// Space Complexity: O(V + E)
// - V represents the number of vertices (courses) and E represents the number of edges (prerequisites).
// - This accounts for the space used by the adjacency list (`adj`), the visited vector (`visited`), and 
//the recursion stack vector (`inRecursion`).
