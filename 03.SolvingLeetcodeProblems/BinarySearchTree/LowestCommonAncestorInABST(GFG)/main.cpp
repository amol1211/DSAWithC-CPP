//Lowest Common Ancestor in a BST(GFG)

#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

//Approach 1 : Iterative 

class Solution {
public:
    // Function to find Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree (BST)
    Node* LCA(Node *root, int n1, int n2) {
        // If the root is null, return null (no LCA in an empty tree)
        if (root == nullptr) return nullptr;
        
        // Traverse the tree until the LCA is found
        while (root != nullptr) {
            // If both nodes are smaller than the current root, LCA must be in the left subtree
            if (root->data > n1 && root->data > n2) 
                root = root->left;
            // If both nodes are greater than the current root, LCA must be in the right subtree
            else if (root->data < n1 && root->data < n2) 
                root = root->right;
            // If one node is smaller and the other is greater, current root is the LCA
            else 
                return root;
        }
        // If no LCA is found (shouldn't reach here in a valid BST)
        return nullptr;
    }
};


/*Time Complexity:

O(h), where h is the height of the Binary Search Tree (BST). In the worst case, it's O(n) for a skewed tree.
Space Complexity:

O(1), constant space. There is no recursion, and only a single variable is used.*/

/*-------------------------------------------------------------------------------------------------------------*/

//Approach 2 : Recursive
class Solution {
public:
    // Recursive function to find Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree (BST)
    Node* LCA(Node *root, int n1, int n2) {
        // If the root is null, return null (no LCA in an empty tree)
        if (root == nullptr) return nullptr;

        // If both nodes are smaller than the current root, LCA must be in the left subtree
        if (root->data > n1 && root->data > n2) {
            return LCA(root->left, n1, n2);
        }
        // If both nodes are greater than the current root, LCA must be in the right subtree
        if (root->data < n1 && root->data < n2) {
            return LCA(root->right, n1, n2);
        }
        // If one node is smaller and the other is greater, current root is the LCA
        return root;
    }
};

/*Time Complexity:

O(h), where h is the height of the Binary Search Tree (BST). In the worst case, it's O(n) for a skewed tree.
Space Complexity:

O(h), where h is the height of the Binary Search Tree (BST). The space complexity is determined by the 
maximum depth of the recursion stack. In the worst case, it's O(n) for a skewed tree.*/