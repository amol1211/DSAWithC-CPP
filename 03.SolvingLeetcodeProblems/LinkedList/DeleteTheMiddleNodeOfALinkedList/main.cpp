//2095. Delete the Middle Node of a Linked List

////Approach 1

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

/*--------------------------------------------------------*/

//Approach 2

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
    }
};