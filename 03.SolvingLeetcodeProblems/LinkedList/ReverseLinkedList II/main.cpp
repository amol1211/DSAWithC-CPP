//92. Reverse Linked List II

#include <iostream>
using namespace std;


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head; // If the input list is empty or left is equal to right, no reversal is needed, so return the original list.
        }

        ListNode* dummy = new ListNode(0); // Create a dummy node to simplify edge cases.
        dummy->next = head; // Set the dummy node as the new head of the list.
        ListNode* prev = dummy; // Initialize a pointer to the node before the left position.

        // Move prev to the node just before the left position.
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* current = prev->next; // Initialize a pointer to the left position.
        ListNode* next;

        // Reverse the subsegment from left to right.
        for (int i = left; i < right; i++) {
            next = current->next; // Store the next node for reversal.
            current->next = next->next; // Reverse the link.
            next->next = prev->next; // Update the next of the reversed node.
            prev->next = next; // Update the next of the previous node.
        }

        return dummy->next; // Return the new head of the reversed list.
    }
};

//Time complexity : O(N)
//Space complexity : O(1)