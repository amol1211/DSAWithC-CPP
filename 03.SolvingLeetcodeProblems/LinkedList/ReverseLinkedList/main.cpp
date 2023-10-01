//206. Reverse Linked List

//Approach 1: Iterative approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        ListNode* forward = nullptr;
        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;      
        }
        return prev;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)

/*---------------------------------------------------------*/

//Approach 2: Recursive 

class Solution {
public:

    void reverse(ListNode* &head, ListNode* curr, ListNode* prev) {

        //Base case
        if (curr == nullptr) {
            head = prev;
            return;
        }

        ListNode* forward = curr->next;
        reverse(head, forward, curr);
        curr->next = prev;
        

    }
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = nullptr;
        reverse(head, curr, prev);
        return head;
    }
};

//Time complexity: O(n)
//Space complexity: O(n)

/*-----------------------------------------------------*/

//Approach 3: Optimized recursive approach

class Solution {
public:

    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* remainingHead = reverse(head->next);

        head->next->next = head;
        head->next = nullptr;

        return remainingHead;
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head);
        
    }
};

//Time complexity: O(n)
//Space complexity: O(n)