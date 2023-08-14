//21. Merge Two Sorted Lists



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node as the head of the merged list
        ListNode* dummy = new ListNode(0);
        // Initialize a current pointer to track the current position in the merged list
        ListNode* current = dummy;
        // Initialize two pointers, ptr1 and ptr2, to traverse list1 and list2 respectively
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        // Traverse both lists until either ptr1 or ptr2 becomes null
        while (ptr1 && ptr2) {
            // If the value in ptr1 is less than or equal to the value in ptr2
            if (ptr1->val <= ptr2->val) {
                // Set the next node of the current pointer to ptr1
                current->next = ptr1;
                // Move ptr1 to the next node
                ptr1 = ptr1->next;
            } else {
                // Otherwise, if the value in ptr2 is less than the value in ptr1
                // Set the next node of the current pointer to ptr2
                current->next = ptr2;
                // Move ptr2 to the next node
                ptr2 = ptr2->next;
            }
            // Move the current pointer to the next node in the merged list
            current = current->next;
        }

        // Append any remaining nodes from list1 or list2 to the merged list
        if (ptr1) {
            current->next = ptr1;
        } else if (ptr2) {
            current->next = ptr2;
        }

        // Store the head of the merged list
        ListNode* head = dummy->next;
        // Delete the dummy node
        delete dummy;
        // Return the head of the merged list
        return head;
    }
};
