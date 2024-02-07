//Find a pair with given target in BST(GFG two sum)

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

class Solution{
  private:
    // Helper function to perform in-order traversal of the BST and store values in a vector
    void inOrder(struct Node* root, vector<int> &in) {
        if (!root) return; // If root is null, return
        
        // Traverse left subtree
        inOrder(root->left, in);
        
        // Store the value of current node
        in.push_back(root->data);
        
        // Traverse right subtree
        inOrder(root->right, in);
    }
  public:
    // Function to check if there exists a pair of nodes in the BST whose sum equals the target
    // Returns 1 if such a pair exists, 0 otherwise
    int isPairPresent(struct Node *root, int target)
    {
     vector<int> inOrderVal; // Vector to store in-order traversal values
     inOrder(root, inOrderVal); // Perform in-order traversal and store values
     
     int i = 0, j = inOrderVal.size() - 1; // Initialize two pointers for two-sum approach
     
     // Iterate until pointers meet
     while (i < j) {
         int sum = inOrderVal[i] + inOrderVal[j]; // Calculate sum of values at current pointers
         
         // If sum equals target, return 1 (indicating pair found)
         if (sum == target) 
             return 1;
         
         // If sum is greater than target, decrement j (move towards smaller elements)
         else if (sum > target) 
             j--;
         
         // If sum is less than target, increment i (move towards larger elements)
         else 
             i++;
         
     }
     return 0; // Return 0 if no such pair found
    }
};

/*Time Complexity: O(n) - where n is the number of nodes in the BST, as we perform an in-order 
traversal of the BST to populate the vector, and then iterate through the vector using two pointers.

Space Complexity: O(n) - where n is the number of nodes in the BST, as we store the values of all 
nodes in the vector during the in-order traversal.*/
