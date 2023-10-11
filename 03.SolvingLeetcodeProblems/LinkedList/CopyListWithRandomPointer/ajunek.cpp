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

public :
    Node* copyRandomList(Node* head) {
        Node* clonehead = nullptr;
        Node* cloneTail = nullptr;

        Node* temp = head;

        while (tail != nullptr) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        unordered_set<Node* Node*> oldToNewNode;

        Node* originalNode = head;
        Node* cloneNode* = cloneHead;

        while (originalNode != nullptr && cloneNode != nullptr) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != nullptr) {
            if (originalNode->random != nullptr) {
                cloneNode->random = oldToNewNode[originalNode->random];
            }
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return clonehead;
    }
};