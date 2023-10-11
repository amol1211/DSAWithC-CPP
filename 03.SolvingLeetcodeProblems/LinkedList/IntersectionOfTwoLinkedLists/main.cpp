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
