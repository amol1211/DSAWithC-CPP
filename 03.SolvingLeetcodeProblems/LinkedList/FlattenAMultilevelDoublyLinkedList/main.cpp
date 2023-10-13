//430. Flatten a Multilevel Doubly Linked List

//Approach 1 : Brute force

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;  // If the list is empty, return it as is.

        Node* current = head;  // Start from the head of the list.

        while (current != nullptr) {  // Traverse the list.
            if (current->child != nullptr) {  // If the current node has a child list.
                Node* next = current->next;  // Store the next node in the top-level list.
                Node* child = current->child;  // Get the child list.

                current->next = child;  // Connect the current node to the child list.
                child->prev = current;  // Update the child list's previous pointer.
                current->child = nullptr;  // Clear the child pointer in the current node.

                while (child->next != nullptr) {
                    child = child->next;  // Traverse to the end of the child list.
                }

                child->next = next;  // Connect the child list to the rest of the top-level list.

                if (next != nullptr) {
                    next->prev = child;  // Update the previous pointer of the next node.
                }
            }

            current = current->next;  // Move to the next node in the top-level list.
        }

        return head;  // Return the flattened list.
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1)
