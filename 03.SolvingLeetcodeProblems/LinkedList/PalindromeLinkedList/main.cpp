//234. Palindrome Linked List
#include <iostream>
using namespace std;

//Approach 1:

class Solution {
private:

    bool checkPalindrome(vector<int> arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            if (arr[start] != arr[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;

    }
public:

    bool isPalindrome(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        return checkPalindrome(arr);
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*----------------------------------------------------------*/

//Approach 2

class Solution {
private:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) {
            return true;
        }

        // Step 1: Find middle
        ListNode* middle = getMid(head);

        // Step 2: Reverse list after middle node
        ListNode* temp = middle->next;
        middle->next = reverse(temp);

        // Step 3: Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle->next;

        while (head2 != nullptr) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4: Make the list as it was given (optional)
        middle->next = reverse(middle->next);

        return true;
    }
};

//Time complexity : O(n)
//Space complexity : O(1)


