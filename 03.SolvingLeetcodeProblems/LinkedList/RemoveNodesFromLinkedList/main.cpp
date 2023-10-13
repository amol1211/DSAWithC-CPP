//2487. Remove Nodes From Linked List

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Base case: if the list is empty or has only one node, return it as is.
        if (!head || !head->next) return head;

        // Recursively call removeNodes on the rest of the list.
        ListNode* temp = removeNodes(head->next);

        // If the value of the node to the right (temp) is greater than the current node (head),
        // return the rest of the modified list (temp).
        if (temp->val > head->val) return temp;

        // If the value of the current node (head) is greater than or equal to the next node (temp),
        // set the next node of the current node to be the result of the recursive call (temp).
        head->next = temp;

        // Return the current node, which now potentially has nodes with greater values removed.
        return head;
    }
};

//Time Complexity : O(n)
//Space Complexity : O(n)
