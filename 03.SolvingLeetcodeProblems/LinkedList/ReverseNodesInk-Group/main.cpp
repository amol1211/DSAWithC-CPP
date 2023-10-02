#include <iostream>
using namespace std;

class Solution {
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) {
            return head;
        }

        ListNode* next = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        count = 0;

        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};