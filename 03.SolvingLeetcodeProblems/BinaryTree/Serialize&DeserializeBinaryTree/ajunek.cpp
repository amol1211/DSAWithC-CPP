
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Codec {
private:
    TreeNode* deserializeHelper(queue<string> &nodes) {
        string nodeVal = nodes.front();
        nodes.pop();

        if (nodeVal == "null") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodeVal));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);

        return root;
    }    
public:
    string serialize(TreeNode* root) {
        if (!root) {
            return "null";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }



    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string node;
        
        while (getline(ss, node, ',')) {
            nodes.push(node);
        }
        return deserializeHelper(nodes);
    }
};