//Predecessor and Successor (GFG)

#include <iostream>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

class Solution
{
private:
    // Helper function to find the node with the maximum key in the BST
    Node *findMax(Node *root)
    {
        // Traverse right until the rightmost node is reached
        while (root->right != nullptr)
        {
            root = root->right;
        }
        return root;
    }

    // Helper function to find the node with the minimum key in the BST
    Node *findMin(Node *root)
    {
        // Traverse left until the leftmost node is reached
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }

    // Recursive helper function to find the predecessor and successor of a given key
    void findPreSucHelper(Node *root, Node *&pre, Node *&suc, int &key)
    {
        // Base case: if the root is null, return
        if (root == nullptr)
        {
            return;
        }

        // If the current node's key is equal to the target key
        if (root->key == key)
        {
            // If there is a left subtree, update 'pre' to the maximum key in the left subtree
            if (root->left != nullptr)
            {
                pre = findMax(root->left);
            }

            // If there is a right subtree, update 'suc' to the minimum key in the right subtree
            if (root->right != nullptr)
            {
                suc = findMin(root->right);
            }

            return; // Exit the function
        }

        // If the key to be searched is smaller, update 'suc' and continue searching in the left subtree
        if (root->key > key)
        {
            suc = root;
            findPreSucHelper(root->left, pre, suc, key);
        }
        else // If the key to be searched is larger, update 'pre' and continue searching in the right subtree
        {
            pre = root;
            findPreSucHelper(root->right, pre, suc, key);
        }
    }

public:
    // Main function to find predecessor and successor of a given key in a BST
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        pre = nullptr; // Initialize 'pre' to null
        suc = nullptr; // Initialize 'suc' to null
        findPreSucHelper(root, pre, suc, key); // Call the recursive helper function
    }
};

/*Time Complexity:

The time complexity of the given code is O(h), where h is the height of the binary search tree (BST). 
In the worst case, when the BST is skewed, the height h is equal to the number of nodes in the tree, 
making the time complexity O(n).

Space Complexity:

The space complexity is O(h), where h is the height of the binary search tree (BST). This space complexity 
is due to the maximum depth of the function call stack during the recursive calls. In the worst case, when 
the BST is skewed, the height h is equal to the number of nodes in the tree, making the space complexity O(n).*/