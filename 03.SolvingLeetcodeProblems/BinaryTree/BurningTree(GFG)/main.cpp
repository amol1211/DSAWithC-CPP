#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {

private:
    //Create mapping
    //Return target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
        Node* result = nullptr;

        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = nullptr;

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (front->data == target) {
                result = front;
            }
            
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }

        return result;
    }

    int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
        map<Node*, bool> visited;
        queue<Node*> q;

        q.push(root);
        visited[root] = true;

        int ans = 0;

        while (!q.empty()) {

            bool flag = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                //Process neighbouring nodes
                Node* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }

                if (front->right && !visited[front->right]) {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }

                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] + 1;
                }
            }
            if (flag == 1) {
                ans++;
            }
        }
        return ans;
    }

public:
    int minTime(Node *root, int target) {

        // Algorithm steps
        // Steps 1 : Create Node to Parent mapping
        // Step 2 : Find target node
        // Step 3 : Burn the tree in min time

        map<Node *, Node *> nodeToParent;
        Node *targetNode = createParentMapping(root, target, nodeToParent);

        int ans = burnTree(targetNode, nodeToParent);

        return ans;
    }
};
