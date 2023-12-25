//2583. Kth Largest Sum in a Binary Tree

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//Appraoch 1: BFS

class Solution {
public:
    typedef long long ll;

    // Function to find the kth largest level sum in a binary tree
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Queue to perform level order traversal
        queue<TreeNode*> q;
        q.push(root);

        // Vector to store the sum of each level
        vector<ll> levelSum;

        // Perform level order traversal
        while (!q.empty()) {
            ll sum = 0;
            // Queue for the next level
            queue<TreeNode*> q2;

            // Process nodes in the current level
            while (!q.empty()) {
                auto curr = q.front();
                q.pop();
                sum += curr->val;

                // Enqueue left and right children for the next level
                if (curr->left)
                    q2.push(curr->left);
                if (curr->right) 
                    q2.push(curr->right);
            }

            // Store the sum of the current level
            levelSum.push_back(sum);

            // Move to the next level
            q = q2;
        }

        // Sort the level sums in ascending order
        sort(levelSum.begin(), levelSum.end());                        
        
        /*OR sort(levelSum.begin(), levelSum.end(), greater<ll>());

        if(levelSum.size() < k) 
            return -1;

        return levelSum[k - 1];*/ 

        // If k is greater than the number of levels, return -1
        if (levelSum.size() < k) 
            return -1;

        // Return the kth largest level sum
        return levelSum[levelSum.size() - k];    
    }
};

//Time Complexity:O(N), where N is the number of nodes in the binary tree.
//Space Complexity:O(W), where W is the maximum width (number of nodes in a level) 
//of the binary tree. In the worst case, it could be O(N) in a completely skewed tree.

/*---------------------------------------------------------------------------------------------*/

//Appraoch 2 : BFS with priority queue

class Solution {
public:
    typedef long long ll;

    // Function to find the kth largest level sum in a binary tree
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Check if the tree is empty
        if (!root) return -1;

        // Queue for level order traversal
        queue<TreeNode*> q;

        // Priority queue (max heap) to store level sums in descending order
        priority_queue<ll> pq;

        // Enqueue the root node to start level order traversal
        q.push(root);

        // Perform level order traversal
        while (!q.empty()) {
            // Get the size of the current level
            int levelSize = q.size();
            
            // Initialize sum for the current level
            long long sum = 0;

            // Process nodes in the current level
            for (int i = 0; i < levelSize; i++) {
                // Dequeue a node
                TreeNode* x = q.front();
                q.pop();
                
                // Add its value to the current level sum
                sum += x->val;

                // Enqueue its left and right children for the next level
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }

            // Push the sum of the current level into the priority queue
            pq.push(sum);
        }

        // If the heap size is less than k, return -1
        if (pq.size() < k) return -1;

        // Retrieve the kth largest sum directly
        while (--k) pq.pop();

        // Return the kth largest sum
        return pq.top();
    }
};

/*Time Complexity: O(N log M), where N is the number of nodes in the binary tree, and M is the number 
of distinct levels. The log M factor arises from the insertion and extraction operations on the priority queue.

Space Complexity: O(M), where M is the maximum number of nodes at any level in the binary tree. This is because 
the queue can store at most the nodes of the level with the maximum width.
*/