//94. Binary Tree Inorder Traversal

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 //Approach 1: Iterative Approach using Stack

 class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Iterative approach using stack
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> s;
        TreeNode* current = root;

        // Traverse the tree in-order iteratively
        while (current != nullptr || !s.empty()) {
            // Push all left nodes onto the stack
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            // Process the current node
            current = s.top();
            s.pop();
            result.push_back(current->val);

            // Move to the right subtree
            current = current->right;
        }

        return result;
    }
};

//Time Complexity: O(N), where N is the number of nodes in the tree. Each node is visited once.
//Space Complexity: O(H), where H is the height of the tree, representing the maximum depth of the stack.

/*------------------------------------------------------------------------------------------------------------*/

//Approach 2: Recursive Approach

class Solution {
private:
    void inorderRecursive(TreeNode* root, vector<int> &result) {
        // Recursive helper function for in-order traversal
        if (root == nullptr) return;
        
        // Traverse left subtree
        inorderRecursive(root->left, result);
        
        // Process the current node
        result.push_back(root->val);
        
        // Traverse right subtree
        inorderRecursive(root->right, result);
    }    

public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Recursive approach
        vector<int> result;
        
        // Call the recursive helper function
        inorderRecursive(root, result);
        
        return result;
    }
};

//Time Complexity: O(N), where N is the number of nodes in the tree. Each node is visited once.
//Space Complexity: O(H), where H is the height of the tree, representing the maximum depth of the stack.

/*-----------------------------------------------------------------------------------------------------*/

//Approach 3: Morris Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Morris Traversal
        TreeNode* current, *prev;
       
        vector<int> result;
        if (root == nullptr) return result;

        current = root;
        while (current != nullptr) {
            if (current->left == nullptr) {
                // If no left child, process current node and move to the right
                result.push_back(current->val);
                current = current->right;
            }
            else {
                // Find the rightmost node in the left subtree
                prev = current->left;
                while (prev->right != nullptr && prev->right != current)
                    prev = prev->right;

                if (prev->right == nullptr) {
                    // Set the right pointer to current and move to the left subtree
                    prev->right = current;
                    current = current->left;
                }
                else {
                    // Revert the right pointer and process the current node, then move to the right subtree
                    prev->right = nullptr;
                    result.push_back(current->val);
                    current = current->right;
                }      
            }
        }

        return result;
    }
};

//Time Complexity: O(N), where N is the number of nodes in the tree. Each node is visited once.
//Space Complexity: O(1), as Morris Traversal uses only constant extra space.