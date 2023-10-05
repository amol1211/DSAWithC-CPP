//83. Remove Duplicates from Sorted List

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* duplicate = curr->next;
                curr->next = duplicate->next;
                delete duplicate;
            }
            else {
                curr = curr->next;
            }         
        }

        return head; 

    }
};

//Time complexity = O(n)
//Space complexity = O(n)

