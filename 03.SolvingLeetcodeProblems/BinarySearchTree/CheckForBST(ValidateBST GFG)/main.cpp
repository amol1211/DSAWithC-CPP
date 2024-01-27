//Check for BST (GFG)

#include <iostream>
#include <climits> // Required for INT_MIN and INT_MAX
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;

  Node(int data)  
    {this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    }
};


class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    // Parameters: Node pointer to the current root, minimum and maximum allowed values.
    bool validateBST(Node* root, int min, int max) {
        // Base case: If the current node is null, the subtree is a valid BST.
        if (root == nullptr) {
            return true;
        }

        // Check if the current node's value is within the valid range.
        if (root->data > min && root->data < max) {
            // Recursively check the left and right subtrees with updated constraints.
            bool left = validateBST(root->left, min, root->data);
            bool right = validateBST(root->right, root->data, max);
            // Return true only if both left and right subtrees are valid BSTs.
            return left && right;
        } else {
            // If the current node's value is not within the valid range, it's not a BST.
            return false;
        }
    }

    // Wrapper function to check if a Binary Tree is a BST.
    // Calls the validateBST function with initial constraints for the root.
    bool isBST(Node* root) {
        return validateBST(root, INT_MIN, INT_MAX);
    }
};

// Time Complexity:
// The time complexity of this algorithm is O(n), where 'n' is the number of nodes in the binary tree.
// This is because the algorithm visits each node exactly once.

// Space Complexity:
// The space complexity is O(h), where 'h' is the height of the binary tree.
// In the worst case (skewed tree), the space complexity approaches O(n), but in a balanced tree, it is O(log n).
