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

/*Overall, the time and space complexity of the provided code are both O(m + n), 
where m and n are the number of nodes in the input BSTs.*/

/*--------------------------------------------------------------------------------------------*/

class Solution
{   
private:
    // Function to convert a binary search tree into a sorted doubly linked list
    // Time Complexity: O(n), where n is the number of nodes in the tree.
    //                  Each node is visited exactly once.
    // Space Complexity: O(h), where h is the height of the tree.
    //                   The space used by the function call stack is proportional to the height of the tree.
    void convertIntoSortedDLL(Node* root, Node* &head) {
        // Base case
        if (root == nullptr) {
            return;
        }
        
        // Convert right subtree
        convertIntoSortedDLL(root->right, head);
        
        // Insert current node into DLL
        root->right = head;
        if (head != nullptr) {
            head->left = root;
        }
        head = root;
        
        // Convert left subtree
        convertIntoSortedDLL(root->left, head);
    }

    // Function to merge two sorted doubly linked lists
    // Time Complexity: O(n + m), where n and m are the lengths of the two lists.
    // Space Complexity: O(1)
    Node* mergeLinkedLists(Node *head1, Node *head2) {
        if (head1 == nullptr) {
            return head2;
        }
        if (head2 == nullptr) {
            return head1;
        }
        
        Node* head = nullptr;
        Node* tail = nullptr;
        
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data < head2->data) {
                if (head == nullptr) {
                    head = head1;
                    tail = head1;
                    head1 = head1->right;
                }
                else {
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1 = head1->right;
                }
            }
            else {
                if (head == nullptr) {
                    head = head2;
                    tail = head2;
                    head2 = head2->right;
                }
                else {
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2 = head2->right;
                }
            }
        }
        
        // Attach remaining nodes
        if (head1 != nullptr) {
            tail->right = head1;
            head1->left = tail;
        }
        if (head2 != nullptr) {
            tail->right = head2;
            head2->left = tail;
        }
        
        return head;
    }

public:
    // Function to return a list of integers denoting the node 
    // values of both the BST in a sorted order.
    // Time Complexity: O(n + m), where n and m are the number of nodes in the two trees.
    // Space Complexity: O(n + m), for storing the sorted doubly linked list.
    vector<int> merge(Node *root1, Node *root2)
    {
        // Step 1: Convert BST into sorted DLL in-place
        Node* head1 = nullptr;
        convertIntoSortedDLL(root1, head1);
        
        Node* head2 = nullptr;
        convertIntoSortedDLL(root2, head2);
       
        // Step 2: Merge sorted LL
        Node* head = mergeLinkedLists(head1, head2);
       
        // Step 3: Store the values of merged DLL into a vector
        vector<int> result;
        while (head != nullptr) {
            result.push_back(head->data);
            head = head->right;
        }
        
        return result;
    }
};  

/*Time Complexity: O(n)
Space Complexity: O(1)*/