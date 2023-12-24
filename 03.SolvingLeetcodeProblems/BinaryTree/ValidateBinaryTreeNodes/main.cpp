//1361. Validate Binary Tree Nodes

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

//Approach 1: Using Adjacency List and Parent Tracking

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // Adjacency list to track adjacent nodes
        unordered_map<int, vector<int>> adj;
        // Map to track parent-child relationships
        unordered_map<int, int> child_to_parent;

        // Iterate through nodes
        for (int i = 0; i < n; i++) {
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            // Add left child to adjacency list
            if (leftC != -1) {
                adj[node].push_back(leftC);
                // Check for multiple parents
                if (child_to_parent.find(leftC) != child_to_parent.end()) {
                    return false;
                }
                child_to_parent[leftC] = node;
            }

            // Add right child to adjacency list
            if (rightC != -1) {
                adj[node].push_back(rightC);
                // Check for multiple parents
                if (child_to_parent.find(rightC) != child_to_parent.end()) {
                    return false;
                }
                child_to_parent[rightC] = node;
            }
        }

        int root = -1;

        // Find the root node (a node with no parent)
        for (int i = 0; i < n; i++) {
            if (child_to_parent.find(i) == child_to_parent.end()) {
                if (root != -1)
                    return false;
                root = i;
            }
        }

        if (root == -1)
            return false;

        // Perform BFS to check if the tree is connected
        int count = 0;
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(root);
        count = 1;
        visited[root] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Explore adjacent nodes
            for (int &v: adj[node]) {
                if (!visited[v]) {
                    visited[v] = true;
                    count++;
                    q.push(v);
                }
            }
        }

        // Check if all nodes are visited
        return count == n;
    }
};

//Time Complexity: O(N + E), where N is the number of nodes, and E is the number of edges.
//Space Complexity: O(N) for the adjacency list, parent-child mapping, queue, and visited array.

/*---------------------------------------------------------------------------------------------------*/

// Approach 2: Using In-Degree and Depth-First Traversal

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // In-degree array to track incoming edges for each node
        vector<int> inDegree(n, 0);

        // Calculate in-degrees for each node and check for multiple incoming edges
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                if (inDegree[leftChild[i]] > 1) {
                    return false; // More than one incoming edge to a node
                }
            }
            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                if (inDegree[rightChild[i]] > 1) {
                    return false; // More than one incoming edge to a node
                }
            }
        }

        int rootNode = -1;

        // Find the root node (a node with in-degree 0)
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (rootNode != -1) {
                    return false; // More than one root node
                }
                rootNode = i;
            }
        }

        if (rootNode == -1) {
            return false; // No root node found
        }

        // Perform DFS to check if the tree is connected and has no cycles
        vector<bool> visited(n, false);
        stack<int> dfs;
        dfs.push(rootNode);

        while (!dfs.empty()) {
            int node = dfs.top();
            dfs.pop();

            if (visited[node]) {
                return false; // Cycle detected
            }

            visited[node] = true;

            // Explore child nodes
            if (leftChild[node] != -1) {
                dfs.push(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                dfs.push(rightChild[node]);
            }
        }

        // Check if all nodes are visited
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false; // Some nodes are not reachable
            }
        }

        return true;
    }
};

//Time Complexity: O(N + E), where N is the number of nodes, and E is the number of edges.
//Space Complexity: O(N) for the in-degree array, visited array, and stack.