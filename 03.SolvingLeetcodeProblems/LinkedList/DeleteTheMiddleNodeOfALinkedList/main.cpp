//2095. Delete the Middle Node of a Linked List

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        int count = 0;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }

        int middlePosition = count / 2;

        temp = head;
        curr = head;

        int currentPosition = 0;

        while (currentPosition < middlePosition) {
            prev = curr;
            curr = curr->next;
            currentPosition++;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};