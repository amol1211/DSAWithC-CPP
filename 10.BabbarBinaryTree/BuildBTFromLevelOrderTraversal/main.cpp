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

void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;
    cout << "Enter data for root : " << '\n';
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << '\n';
        int leftData;
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << '\n';
        int rightData;
        cin >> rightData;

        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = nullptr;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);


   return 0;
}