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

