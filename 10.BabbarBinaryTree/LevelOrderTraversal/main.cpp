#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *buildTree(Node *root) {
    cout << "Enter the data: " << '\n';
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return nullptr;
    }

    cout << "Enter data for inserting in left of " << data << '\n';
    root->left = buildTree(root->left);
    cout << "Enter data for inserting at right of " << data << '\n';
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node *root) {
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr) { // Previous level has been traversed completely
            cout << '\n';
            if (!q.empty()) {
                q.push(nullptr);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node *root = nullptr;

    // Creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order traversal
    cout << "Printing the level order traversal output " << '\n';
    levelOrderTraversal(root);

    return 0;
}