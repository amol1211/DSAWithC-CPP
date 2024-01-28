//Insert a node in a BST (GFG)

#include <iostream>
using namespace std;

   struct Node {
       int data;
       Node* left;
       Node* right;

       Node(int val) {
           data = val;
           left = right = nullptr;
       }
   };

class Solution
{
public:
    // Function to check if a node with a specific data value is present in the tree
    bool nodePresent(Node* root, int data) {
        if (root == nullptr) return false;

        if (root->data == data) return true;
        else if (data > root->data) {
            nodePresent(root->right, data);
        } else {
            nodePresent(root->left, data);
        }
    }

    // Function to insert a node with a specific data value into the tree
    void insertNode(Node* root, int data) {
        if (data < root->data) {
            if (root->left == nullptr) {
                root->left = new Node(data);
                return;
            }
            insertNode(root->left, data);
        } else if (data > root->data) {
            if (root->right == nullptr) {
                root->right = new Node(data);
                return;
            }
            insertNode(root->right, data);
        }
    }

    // Wrapper function to insert a node with a specific data value into the tree
    Node* insert(Node* node, int data) {
        // Check if the node with the given data value is already present in the tree
        if (nodePresent(node, data)) {
            return node;
        } else {
            // If not present, insert the node into the tree
            insertNode(node, data);
            return node;
        }
    }
};

/*Time Complexity:

The time complexity for checking if a node is present or inserting a node is O(h), where h is 
the height of the binary search tree.

Space Complexity:

The space complexity is O(h), where h is the height of the binary search tree. This is due to the 
recursive nature of the insert and nodePresent functions, which use the call stack. In the worst case 
(skewed tree), the space complexity can be O(n), where n is the number of nodes in the tree.

*/