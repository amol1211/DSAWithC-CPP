#include <iostream>
#include <queue>
using namespace std;

//Children Sum Parent(GFG)

class Solution {
public:
    // Function to check whether all nodes of a tree have the value 
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        // Check if the tree is empty.
        if (!root)
            return 1; // If the tree is empty, the property holds.

        // Using a queue for level order traversal.
        queue<Node*> q;
        q.push(root);

        // Traverse the tree level by level.
        while (!q.empty()) {
            // Get the front node from the queue.
            Node* temp = q.front();
            q.pop();

            // Variable to store the sum of values in child nodes.
            int childrenSum = 0;

            // Check if the left child exists.
            if (temp->left) {
                // Add the left child's data to the sum.
                q.push(temp->left);
                childrenSum += temp->left->data;
            }

            // Check if the right child exists.
            if (temp->right) {
                // Add the right child's data to the sum.
                q.push(temp->right);
                childrenSum += temp->right->data;
            }

            // Check if the current node is a leaf node.
            if (temp->left == nullptr && temp->right == nullptr) {
                // If it's a leaf, there are no child nodes to consider.
                // Continue to the next iteration.
                continue;
            }

            // Check if the sum property is violated.
            if (temp->data != childrenSum) {
                return 0;  // Return 0 if the property is violated.
            }
        }

        // If the traversal completes without finding a violation,
        // return 1 indicating that the sum property holds for the entire tree.
        return 1;
    }
};

//Time Complexity: The time complexity of this solution is O(N), where N is the number 
//of nodes in the tree. This is because each node is processed once during the level order traversal.

//Space Complexity: The space complexity is O(W), where W is the maximum width 
//(number of nodes at any level) of the tree. In the worst case, the queue can store 
//all nodes at a particular level.