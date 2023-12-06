//138. Copy List with Random Pointer

#include <iostream>
using namespace std;

//Approach 1 : Using set
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

//Time complexity: O(n)
//Space complexity: O(n)

/*--------------------------------------------------------------*/

//Approach 1 : Creating deep copy of original list

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Duplicate nodes and insert them immediately after the original nodes
        Node* current = head;
        while (current) {
            // Create a new node with the same value as the original node
            Node* copy = new Node(current->val);
            
            // Insert the copy node after the original node
            copy->next = current->next;
            current->next = copy;
            
            // Move to the next original node
            current = copy->next;
        }

        // Step 2: Set random pointers for the copied nodes
        current = head;
        while (current) {
            if (current->random) {
                // Set the random pointer of the copy node to the copy of the random node
                current->next->random = current->random->next;
            }
            
            // Move to the next pair of nodes (original and copy)
            current = current->next->next;
        }

        // Step 3: Separate the original and copied lists
        current = head;
        Node* copiedHead = current->next;
        Node* copiedCurrent = copiedHead;

        while (current) {
            // Restore the original list by fixing next pointers
            current->next = copiedCurrent->next;
            current = current->next;

            if (current) {
                // Update copied list pointers
                copiedCurrent->next = current->next;
                copiedCurrent = copiedCurrent->next;
            }
        }

        // Return the head of the copied list
        return copiedHead;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)
