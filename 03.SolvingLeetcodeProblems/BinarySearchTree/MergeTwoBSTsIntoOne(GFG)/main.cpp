//Merge two BST 's into One (GFG)

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{   
private:
    // Helper function for inorder traversal of a binary tree
    // Time Complexity: O(n), where n is the number of nodes in the tree
    // Space Complexity: O(n), for the recursive call stack
    void inorder(Node* root, vector<int> &in) {
        if (!root) return;
        
        inorder(root->left, in); // traverse left subtree
        in.push_back(root->data); // push root data
        inorder(root->right, in); // traverse right subtree
    }
    
    // Helper function to merge two sorted arrays into one sorted array
    // Time Complexity: O(m + n), where m and n are the lengths of the input arrays
    // Space Complexity: O(m + n), where m and n are the lengths of the input arrays
    vector<int> mergeArrays(vector<int> &a, vector<int> &b) {
        vector<int> ans(a.size() + b.size()); // merged array
        
        int i = 0, j = 0;
        int k = 0;
        
        // Merge elements from both arrays in sorted order
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                ans[k++] = a[i++];
            } else {
                ans[k++] = b[j++];
            }
        }
        
        // Copy remaining elements from array a
        while (i < a.size()) {
            ans[k++] = a[i++];
        }
        
        // Copy remaining elements from array b
        while (j < b.size()) {
            ans[k++] = b[j++];
        }
        
        return ans; // return merged array
    }
    
    // Helper function to construct a balanced BST from a sorted array
    // Time Complexity: O(n), where n is the number of elements in the sorted array
    // Space Complexity: O(log n), for the recursive call stack (if the tree is balanced)
    Node* inorderToBST(int s, int e, vector<int> &in) {
        if (s > e) return nullptr; // base case
        
        int mid = (s + e) / 2;
        Node *root = new Node(in[mid]); // create root node
        
        // Recursively build left and right subtrees
        root->left = inorderToBST(s, mid - 1, in);
        root->right = inorderToBST(mid + 1, e, in);
        
        return root; // return root of the constructed BST
    }
    
public:
    // Function to merge two BSTs into a single sorted list
    // Time Complexity: O(m + n), where m and n are the number of nodes in the input BSTs
    // Space Complexity: O(m + n), where m and n are the number of nodes in the input BSTs
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> bst1, bst2;
       
       // Perform inorder traversal of both BSTs to get sorted lists
       inorder(root1, bst1);
       inorder(root2, bst2);
       
       // Merge the sorted lists into one sorted list
       vector<int> mergeArray = mergeArrays(bst1, bst2);
       
       // Construct a balanced BST from the merged sorted list
       int s = 0, e = mergeArray.size() - 1;
       Node* mergedBST = inorderToBST(s, e, mergeArray);
       
       vector<int> result;
       
       // Perform inorder traversal of the merged BST to get the final sorted list
       inorder(mergedBST, result);
       
       return result; // return the final sorted list
    }
};
