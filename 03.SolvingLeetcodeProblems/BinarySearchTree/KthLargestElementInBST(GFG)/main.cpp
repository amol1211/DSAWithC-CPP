//Kth largest element in BST(GFG)

#include <iostream>
#include <stack>
using namespace std;

//Approach 1 : Iterative approach using stack

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthLargestUtil(Node* root, int& k) {
        stack<Node*> stk;
        Node* curr = root;

        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->right; // Traverse right first
            }

            curr = stk.top();
            stk.pop();

            k--;
            if (k == 0) {
                return curr->data; // Kth largest element found
            }

            curr = curr->left;
        }

        return -1; // If K is greater than the number of nodes in the BST
    }

    int kthLargest(Node* root, int K) {
        return kthLargestUtil(root, K);
    }
};

/*Time Complexity:
The time complexity is O(N), where N is the number of nodes in the Binary Search Tree (BST).
In the worst case, we visit all nodes once during the in-order traversal.
Space Complexity:
The space complexity is O(H), where H is the height of the BST.
In the worst case (skewed tree), the space complexity approaches O(N) 
as the maximum height of the stack becomes N.*/

/*------------------------------------------------------------------------------------------------------------*/

//Approach 2 : Recursive approach

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void kthLargestUtil(Node* root, int& k, int& result) {
        if (!root || k == 0) {
            return;
        }

        // Traverse the right subtree first
        kthLargestUtil(root->right, k, result);

        // Process the current node
        k--;
        if (k == 0) {
            result = root->data; // Kth largest element found
            return;
        }

        // Continue with the left subtree
        kthLargestUtil(root->left, k, result);
    }

    int kthLargest(Node* root, int K) {
        int result = -1;
        kthLargestUtil(root, K, result);
        return result;
    }
};

/*Time Complexity:
The time complexity is O(N), where N is the number of nodes in the Binary Search Tree (BST).
In the worst case, we visit all nodes once during the recursive in-order traversal.
Space Complexity:
The space complexity is O(H), where H is the height of the BST.
The recursive approach uses the call stack, and in the worst case (skewed tree), 
the maximum height of the call stack becomes H.
*/