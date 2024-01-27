//k-th smallest element in BST

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

//Approach 1 : Iterative approach using stack

class Solution {
public:
    // Function to find Kth smallest element using iterative in-order traversal with a stack
    int KthSmallestUtil(Node* root, int &k) {
        stack<Node*> st;
        
        // Iterate until either the current node is null or the stack is empty
        while (root != nullptr || !st.empty()) {
            // Traverse to the leftmost node and push all encountered nodes onto the stack
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            
            // Pop the top node from the stack
            root = st.top();
            st.pop();
            
            // Process the current node
            k--;
            if (k == 0) {
                return root->data;
            }
            
            // Move to the right subtree
            root = root->right;
        }
        
        return -1; // Kth smallest element not found
    }

    // Wrapper function to call the utility function
    int KthSmallestElement(Node *root, int K) {
        return KthSmallestUtil(root, K);
    }
};

/*Time Complexity: O(N)
In the worst case, all nodes of the BST are visited once.
Space Complexity: O(H)
In the worst case, where the BST is skewed, the space required 
for the stack is O(H), where H is the height of the BST.*/

/*-------------------------------------------------------------------------------------*/

////Approach 2 : Recursive approach

class Solution {
public:
    // Helper function for recursive in-order traversal to find Kth smallest element
    void KthSmallestUtil(Node* root, int &k, int &result) {
        // Base case: if the current node is null or K is already found, return
        if (root == nullptr || k == 0) return;
        
        // Traverse left subtree
        KthSmallestUtil(root->left, k, result);
        
        // Process the current node
        k--;
        if (k == 0) {
            result = root->data;
            return;
        }
        
        // Traverse right subtree
        KthSmallestUtil(root->right, k, result);
    }
    
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int result = -1;
        KthSmallestUtil(root, K, result);
        return result;
    }
};

/*Time Complexity: O(N)
In the worst case, all nodes of the BST are visited once.
Space Complexity: O(H)
In the worst case, the maximum recursion stack height is H, 
where H is the height of the BST.*/
