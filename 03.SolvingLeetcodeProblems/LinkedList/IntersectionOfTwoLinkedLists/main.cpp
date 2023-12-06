// 160. Intersection of Two Linked Lists

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *temp;

        while (headB != nullptr) {
            temp = headA;
            while (temp != nullptr) {
                if (temp == headB) {
                    return headB;
                }
                temp = temp->next;
            }
            headB = headB->next;
        }

        return nullptr;
    }
};

//Time Complexity: O(N*M)
//Space Complexity: O(1) 
/*-----------------------------------------------------------------------*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA != tempB) {
            tempA = tempA ? tempA->next : headB;
            tempB = tempB ? tempB->next : headA;
        }

        return tempA;
    }
};

//Time Complexity: O(N) 
//Space Complexity: O(1)

/*------------------------------------------------*/

//GFG problem

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != temp2) {
        // Move both pointers forward
        temp1 = (temp1 == nullptr) ? head2 : temp1->next;
        temp2 = (temp2 == nullptr) ? head1 : temp2->next;
    }

    return (temp1 == nullptr) ? -1 : temp1->data; // Return the intersection point's data
}

//Time complexity : O(m + n)
//Space complexity : O(1) 