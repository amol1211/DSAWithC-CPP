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

/*-------------------------------------------------------------------------*/

class Solution {
    public:
       Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* current = head;
        while (curr != nullptr) {
            Node* copy = new Node(current->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        current = head;
        while (current != nullptr) {
            if (current->random != nullptr) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        current = head;
        Node* copiedHead = current->next;
        Node* copiedCurrent = copiedHead;

        while (current != nullptr) {
            current->next = copiedCurrent->next;
            current = current->next;

            if (current != nullptr) {
                copiedCurrent->next = current->next;
                copiedCurrent = copiedCurrent->next;
            }
        }

        return copiedHead;      
    }
};