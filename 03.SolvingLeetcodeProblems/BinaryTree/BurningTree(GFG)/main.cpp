#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
private:
    // Create mapping from nodes to their parents and find the target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
        Node* result = nullptr;

        // Use a queue for level-order traversal
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] == nullptr;  // Fix: Use '=' instead of '=='

        // Perform level-order traversal
        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            // Check if the current node is the target node
            if (front->data == target) {
                result = front;
            }

            // Process left child
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            // Process right child
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }

        return result;  // Return the target node found during traversal
    }

    // Burn the tree and find minimum time
    int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {
        map<Node*, bool> visited;

        queue<Node*> q;

        q.push(root);
        visited[root] = 1;  // Fix: Use '1' instead of 'true'

        int ans = 0;

        // Perform level-order traversal
        while (!q.empty()) {
            bool flag = 0;

            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                // Process left child
                if (front->left && !visited[front->left]) {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }

                // Process right child
                if (front->right && !visited[front->right]) {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }

                // Process parent node
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }

            if (flag == 1) {
                ans++;
            }
        }

        return ans;  // Return the minimum time to burn the tree
    }

public:
    // Main function to find minimum time to burn the tree
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;

        Node* targetNode = createParentMapping(root, target, nodeToParent);

        // Check if the target node is not found in the tree
        if (targetNode == nullptr) {
            return -1;
        }

        int ans = burnTree(targetNode, nodeToParent);

        return ans;
    }
};
