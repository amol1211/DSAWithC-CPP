//2. Add Two Numbers
#include <iostream>
using namespace std;

//Approach 1 : (Iterative with Dummy Node)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify handling the result
        ListNode* dummy = new ListNode(0);
        // Create a pointer to the current node in the result linked list
        ListNode* current = dummy;
        // Initialize carry to 0
        int carry = 0;

        // Loop through both input linked lists and handle any carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Initialize the sum with the current carry
            int sum = carry;

            // If l1 is not nullptr, add its value to the sum and move to the next node
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // If l2 is not nullptr, add its value to the sum and move to the next node
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Calculate the new carry and the digit to be placed in the result
            carry = sum / 10;
            int digit = sum % 10;

            // Create a new node with the calculated digit and add it to the result linked list
            current->next = new ListNode(digit);
            current = current->next;
        }

        // Get the actual result linked list (excluding the dummy node)
        ListNode* result = dummy->next;
        // Delete the dummy node to avoid memory leaks
        delete dummy;

        // Return the resulting linked list representing the sum
        return result;
    }
};

//Time Complexity: O(max(N, M))
//Space Complexity: O(max(N, M))

/*----------------------------------------------------------------------------------------*/
//Approach 2 : (Iterative without Dummy Node)

class Solution {
private:
    void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
        ListNode* temp = new ListNode(val);
        // Empty list
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ansHead = nullptr;
        ListNode* ansTail = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            // Create a new node with the digit and add it to the result list
            insertAtTail(ansHead, ansTail, digit);

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return ansHead;
    }
};

//Time Complexity: O(max(N, M))
//Space Complexity: O(max(N, M))

/*----------------------------------------------------------------------------*/
//Approach 3 : Recursive

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Base case: If both input lists are empty, return NULL.
        if (l1 == NULL and l2 == NULL)
            return NULL;
        // If one of the input lists is empty, return the other list.
        else if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;

        // Calculate the sum of the current nodes' values from l1 and l2.
        int ans = l1->val + l2->val;

        // Create a new node with the last digit of the sum and initialize its next pointer as the result of the recursive call.
        ListNode *temp = new ListNode(ans % 10);
        temp->next = addTwoNumbers(l1->next, l2->next);

        // If the sum is greater than or equal to 10, there is a carry.
        if (ans >= 10) {
            // Add 1 to the next node by recursively calling addTwoNumbers with a new ListNode(1).
            temp->next = addTwoNumbers(temp->next, new ListNode(1));
        }

        // Return the current node with the correct value and next pointer.
        return temp;
    }
};

//Time Complexity: O(max(N, M))
//Space Complexity: O(max(N, M))


