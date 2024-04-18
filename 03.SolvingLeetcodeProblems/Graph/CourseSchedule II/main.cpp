//210. Course Schedule II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to perform topological sort on the given adjacency list, `adj`, with `n` nodes and `indegree` vector
    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        // Create a queue to hold nodes with an in-degree of zero
        queue<int> q;

        // Vector to hold the topological sort result
        vector<int> result;

        // Variable to track the number of nodes visited
        int count = 0;

        // Iterate through each node
        for (int i = 0; i < n; i++) {
            // If the in-degree of the node is zero, it can be visited
            if (indegree[i] == 0) {
                // Add the node to the result list
                result.push_back(i);
                // Increment the count of nodes visited
                count++;
                // Add the node to the queue for further processing
                q.push(i);
            }
        }

        // Process each node in the queue
        while (!q.empty()) {
            // Dequeue the next node to process
            int u = q.front();
            q.pop();

            // Iterate through each neighbor of the node `u`
            for (int &v : adj[u]) {
                // Decrease the in-degree of the neighbor node `v`
                indegree[v]--;

                // If the in-degree of the neighbor becomes zero, it can be visited
                if (indegree[v] == 0) {
                    // Add the neighbor node to the result list
                    result.push_back(v);
                    // Increment the count of nodes visited
                    count++;
                    // Add the neighbor node to the queue for further processing
                    q.push(v);
                }
            }
        }
        
        // If the number of nodes visited equals the total number of nodes, the sort was successful
        if (count == n)
            return result; // Return the result list if topological sort is successful

        // If there is a cycle (count is less than `n`), return an empty list
        return {}; // Indicates that a cycle was detected and topological sort failed
    }

    // Function to find the order of courses given the number of courses and prerequisites
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Adjacency list to represent the graph, mapping each course to its prerequisites
        unordered_map<int, vector<int>> adj;

        // Vector to track the in-degree of each course
        vector<int> indegree(numCourses, 0);

        // Iterate through each prerequisite pair
        for (auto &vec : prerequisites) {
            int a = vec[0]; // Course that needs to be taken
            int b = vec[1]; // Course that is a prerequisite for course `a`

            // In the prerequisite pair {a, b}, course `b` must be visited before course `a`
            // Add course `a` as a neighbor of course `b` in the adjacency list
            adj[b].push_back(a);

            // Increment the in-degree of course `a` since it has a prerequisite
            indegree[a]++;
        }

        // Perform topological sort and return the order of courses
        return topologicalSort(adj, numCourses, indegree);
    }
};


/*

**Time Complexity**:
- The time complexity of the `findOrder` function is O(E + V), where:
    - E represents the number of edges (prerequisites).
    - V represents the number of vertices (courses).
- The `topologicalSort` function also has a time complexity of O(E + V) since each node (course) is processed once and each edge (prerequisite) is considered once during the topological sort.

**Space Complexity**:
- The space complexity is O(V + E):
    - V represents the number of vertices (courses).
    - E represents the number of edges (prerequisites).
- This complexity accounts for the storage of the adjacency list (`adj`), the in-degree vector (`indegree`), and the result vector (`result`).
- The adjacency list (`adj`) stores the edges, which requires O(E) space.
- The in-degree vector (`indegree`) and result vector (`result`) each require O(V) space.

*/