//1382. Balance a Binary Search Tree/ Normal BST to Balanced BST

#include <iostream>
#include <vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  }; 
class Solution {
private:
    // Function to perform in-order traversal of the binary search tree
    // and store the values in the given vector
    void inOrder(TreeNode* root, vector<int> &in) {
        if (!root) return; // Base case: if root is null, return

        inOrder(root->left, in); // Traverse left subtree
        in.push_back(root->val); // Store current node's value
        inOrder(root->right, in); // Traverse right subtree
    }    

    // Function to construct a balanced binary search tree from the sorted vector
    TreeNode* inorderToBST(int s, int e, vector<int> &in) {

        if (s > e) return nullptr; // Base case: if start index is greater than end index, return null

        int mid = (s + e)/ 2; // Calculate mid index

        TreeNode* root = new TreeNode(in[mid]); // Create new node with value from mid index
        root->left = inorderToBST(s, mid - 1, in); // Recursively construct left subtree
        root->right = inorderToBST(mid + 1, e, in); // Recursively construct right subtree

        return root; // Return the root of the constructed binary search tree
    }
public:
    // Function to balance a given binary search tree
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrderVal; // Vector to store in-order traversal values
        inOrder(root, inOrderVal); // Perform in-order traversal and store values

        // Construct balanced binary search tree from sorted in-order traversal values
        return inorderToBST(0, inOrderVal.size() - 1, inOrderVal);
    }
}; 

/*Time Complexity:

The time complexity of this algorithm is O(n), where n is the number of nodes in the binary search tree. 
This is because we perform an in-order traversal of the tree to collect the node values, and constructing 
the balanced binary search tree also takes linear time.

Space Complexity:

The space complexity is O(n), where n is the number of nodes in the binary search tree. This is due to the 
additional space required for the vector used to store in-order traversal values during the traversal. 
Additionally, the recursive calls for constructing the balanced binary search tree also contribute to 
the space complexity.*/