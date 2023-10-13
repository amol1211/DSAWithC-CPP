//430. Flatten a Multilevel Doubly Linked List

//Approach 1 : Brute force

/*
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

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

/*----------------------------------------------------------------------------------------*/

//GFG Problem : Flattening a Linked List

// We have return the entire list in sorted order

/*
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
*/

Node* merge(Node* root1, Node* root2) {
    if (!root1) return root2;  // If root1 is null, return root2.
    if (!root2) return root1;  // If root2 is null, return root1.

    Node* dummy = new Node(0);  // Create a dummy node to simplify the merging.
    Node* curr = dummy;  // Create a pointer to keep track of the merged list.

    while (root1 && root2) {
        if (root1->data <= root2->data) {
            curr->bottom = root1;  // Link the current node to the smaller of the two lists.
            root1 = root1->bottom;  // Move to the next node in the same list.
        } else {
            curr->bottom = root2;  // Link the current node to the smaller of the two lists.
            root2 = root2->bottom;  // Move to the next node in the other list.
        }
        curr = curr->bottom;  // Move to the next node in the merged list.
    }

    // Attach any remaining nodes from root1 or root2.
    if (root1) {
        curr->bottom = root1;
    } else if (root2) {
        curr->bottom = root2;
    }

    Node* result = dummy->bottom;  // Get the merged result list.
    delete dummy;  // Delete the dummy node to release memory.
    return result;  // Return the merged result list.
}

Node* flatten(Node* root) {
    if (!root || !root->next) {
        return root;  // If the list is empty or only one level, return it as is.
    }
    return merge(root, flatten(root->next));  // Recursively merge and flatten the lists.
}

