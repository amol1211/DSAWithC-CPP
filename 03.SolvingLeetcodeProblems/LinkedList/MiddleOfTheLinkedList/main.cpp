//876. Middle of the Linked List

//APPROACH 1:
//Traverse the linked list to find it's length.
//Find the middle in the second traversal (middle is length/2)
//Return pointer pointing to the middle element.



/*--------------------------------------------------------------------------*/

//APPROACH-2
//Keep 2 pointers, slow and fast.
//slow moves by one step whereas fast moves by 2 steps.
//By the time fast reaches the end of the LL, slow will point to the middle.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};