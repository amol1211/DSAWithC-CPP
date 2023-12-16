//297. Serialize and Deserialize Binary Tree

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
        TreeNode *left;
        TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
private:
    // Helper function for deserialization
    TreeNode* deserializeHelper(queue<string>& nodes) {
        string nodeVal = nodes.front();
        nodes.pop();

        if (nodeVal == "null") {
            return nullptr; // Return nullptr for "null" nodes
        }

        // Create a new node with the value
        TreeNode* root = new TreeNode(stoi(nodeVal));
        // Recursively deserialize the left and right subtrees
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "null"; // Return "null" for empty nodes
        }

        // Preorder traversal for serialization
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string node;

        // Tokenize the serialized string
        while (getline(ss, node, ',')) {
            nodes.push(node);
        }

        return deserializeHelper(nodes);
    }
};

// Time complexity : O(n)
// Space complexity : O(n)