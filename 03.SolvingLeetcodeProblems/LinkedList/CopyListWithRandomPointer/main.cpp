#include <iostream>
using namespace std;

//Approach 1 :
class Solution {

void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

public:
    Node* copyRandomList(Node* head) {
        //Step 1 : Create a clone list of the original list
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;

        Node* temp = head;

        while (temp != nullptr) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        //Step 2 : Create a map to keep track of random node
        unordered_map<Node*, Node*> oldToNewNode;

        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while (originalNode != nullptr && cloneNode != nullptr) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        //Assign random pointers
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != nullptr) {
            if (originalNode->random != nullptr) {
                cloneNode->random = oldToNewNode[originalNode->random];
            }
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;

        }

        return cloneHead;
    }
};
