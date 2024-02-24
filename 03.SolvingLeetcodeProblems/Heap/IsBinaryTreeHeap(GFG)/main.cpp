//Is Binary Tree Heap (GFG)
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; // Definition of the Node structure

class Solution {
private:
    // Function to count the total number of nodes in the binary tree
    int countNodes(struct Node* root) {
        if (!root) return 0;
        
        // Recursively count nodes in left and right subtrees and add 1 for the current node
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    
    // Function to check if the binary tree is a complete binary tree
    bool isCBT(struct Node* root, int index, int cnt) {
        if (!root) return true;
        
        // If the current index is greater than or equal to the total count of nodes, it's not a complete binary tree
        if (index >= cnt) {
            return false;
        }
        else {
            // Recursively check left and right subtrees
            bool left = isCBT(root->left, 2 * index + 1, cnt);
            bool right = isCBT(root->right, 2 * index + 2, cnt);
            return (left && right);
        }
        
    }
    
    // Function to check if the binary tree follows the max-heap property
    bool isMaxOrder(struct Node* root) {
        // Base case: if the node has no children, it satisfies the max-heap property
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        
        // If the node has only a left child, check if it's greater than the parent
        if (root->right == nullptr) {
            return (root->data > root->left->data);
        }
        else {
            // Recursively check if the parent node is greater than both children and both subtrees satisfy the max-heap property
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return (left && right && 
            (root->data > root->left->data && root->data > root->right->data) );
        }
    }
    
public:
    // Function to check if the given binary tree is a max-heap
    bool isHeap(struct Node* tree) {
        int index = 0;
        // Count total number of nodes in the tree
        int totalCount = countNodes(tree);
        // Check if the tree is a complete binary tree and follows the max-heap property
        if (isCBT(tree, index, totalCount) && isMaxOrder(tree)) {
            return true; // Tree is a max-heap
        }
        else {
            return false; // Tree is not a max-heap
        }
    }
};

/*Time Complexity Analysis:

Counting the total number of nodes in the binary tree requires traversing all nodes once, leading to a time complexity 
of O(n), where n is the number of nodes.
Checking if the binary tree is a complete binary tree also requires traversing all nodes once, leading to a time complexity 
of O(n).
Checking if the binary tree follows the max-heap property requires traversing all nodes once, leading to a time 
complexity of O(n).
Overall, the time complexity of the isHeap function is O(n).

Space Complexity Analysis:

The space complexity is O(h) for recursive function calls, where h is the height of the binary tree. In the worst case, the tree could be skewed, leading to a space complexity of O(n).
Additionally, there's some auxiliary space used for variables and recursive stack, but it doesn't exceed O(n).*/