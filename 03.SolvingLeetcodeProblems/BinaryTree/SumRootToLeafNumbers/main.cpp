//129. Sum Root to Leaf Numbers

#include <iostream>
#include <queue>
#include <math.h>
#include <complex>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Approach: Recursive DFS
 * Description: This solution uses a recursive depth-first search (DFS) to traverse the binary tree.
 *              It accumulates the current path value and adds it to the sum when a leaf node is reached.
 * Time Complexity: O(N), where N is the number of nodes in the binary tree.
 * Space Complexity: O(H), where H is the height of the binary tree (recursion stack space).
 */
class Solution1 {
private:
    int solve(TreeNode* root, int curr) {

        // Base case: if the node is null, return 0
        if (!root) return 0;

        // Update the current path value
        curr = (curr * 10) + root->val;

        // Leaf node (We found root to leaf path)
        if (root->left == nullptr && root->right == nullptr) return curr;

        // Recursive calls for left and right subtrees
        int l = solve(root->left, curr);
        int r = solve(root->right, curr);

        // Sum of path values from left and right subtrees
        return l + r;
    }

public:
    int sumNumbers(TreeNode* root) {

        // Start the recursion with initial path value as 0
        return solve(root, 0);
    }
};

/*-----------------------------------------------------------------------*/
/**
 * Approach: BFS
 * Description: This solution uses a breadth-first search (BFS) traversal with a queue 
 * to process each level of the binary tree. It maintains the current path value and 
 * updates it at each step. The sum is accumulated when a leaf node is reached.
 * Time Complexity: O(N), where N is the number of nodes in the binary tree.
 * Space Complexity: O(W), where W is the maximum width of the binary tree (maximum number of nodes at any level).
 */
class Solution2 {
public:
    int sumNumbers(TreeNode* root) {

        // Initialize sum variable to accumulate path values
        int sum = 0;

        // Queue to perform BFS
        queue<pair<TreeNode*, int>> q;

        // Add root node to the queue with initial path value as 0
        q.push({root, 0});

        // BFS loop
        while(q.size()) {
            auto [n, cur] = q.front(); q.pop();

            // Update current path value
            cur = cur * 10 + n -> val;

            // Add left and right children to the queue with updated path value
            if(n -> left) q.push({n -> left, cur});      
            if(n -> right) q.push({n -> right, cur});

            // If leaf node is reached, add current path value to sum
            if(!n -> left && !n -> right) sum += cur;
        }

        // Return the final sum
        return sum;
    }
};

/**
 * Approach: Morris-preorder
 * Description: This solution uses Morris traversal to simulate the preorder traversal without using a stack.
 *              It maintains the current path value and updates it during the traversal. The sum is accumulated when a leaf node is reached.
 * Time Complexity: O(N), where N is the number of nodes in the binary tree.
 * Space Complexity: O(1), as it utilizes constant space without any additional data structures.
 */
class Solution3 {
public:
    int sumNumbers(TreeNode* root) {

        // Initialize variables for sum, current path value, and depth
        int sum = 0, cur = 0, depth = 0;

        // Morris traversal loop
        while(root) {

            // If the node has a left child
            if(root -> left) {

                // Find the predecessor and calculate depth
                auto pre = root -> left;
                depth = 1;
                while(pre -> right && pre -> right != root) 
                    pre = pre -> right, depth++;

                // If there is no right link, create one and move to the left child
                if(!pre -> right) {
                    pre -> right = root;
                    cur = cur * 10 + root -> val;
                    root = root -> left;
                } 
                // If there is a right link, remove it, update current value, and move to the right child
                else {
                    pre -> right = nullptr;
                    if(!pre -> left) sum += cur;
                    cur /= pow(10, depth);
                    root = root -> right;
                }
            } 
            // If the node does not have a left child, update current value and move to the right child
            else {
                cur = cur * 10 + root -> val;
                if(!root -> right) sum += cur;
                root = root -> right;
            }
        }

        // Return the final sum
        return sum;
    }
};
