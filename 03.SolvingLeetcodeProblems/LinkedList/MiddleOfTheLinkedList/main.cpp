//876. Middle of the Linked List

//APPROACH 1:
//Traverse the linked list to find it's length.
//Find the middle in the second traversal (middle is length/2)
//Return pointer pointing to the middle element.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int length=0;
        while(temp)
        {
            length++;
            temp = temp->next;
        }
        int half = length/2;
        temp=head;
        while(temp && half--)
        {
            temp=temp->next;
        }
        return temp;
    }
};

/*--------------------------------------------------------------------------*/

//APPROACH-2
//Keep 2 pointers, slow and fast.
//slow moves by one step whereas fast moves by 2 steps.
//By the time fast reaches the end of the LL, slow will point to the middle.

