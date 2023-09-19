#include <iostream>
using namespace std;

class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode *temp = head;
            int length = 0;
            while(temp) {
                length++;
                temp = temp->next;
            }
            int half = length/2;
            temp = head;
            while(temp && half--) {
                temp = temp->next;
            }
            return temp;
        }
};

/*----------------------------------------------------------------*/

class Solution {
    public:
       ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
       }
       return slow;
    }     
};