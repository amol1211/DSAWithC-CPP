//142. Linked List Cycle II

#include <iostream>
using namespace std;

//Approach 1 : 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while (head) {
            if (seen.find(head) != end(seen)) return head;
            seen.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

/*------------------------------------------------------------------------*/

//Approach 2 :

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return NULL;
 
    ListNode *slow = head, *fast = head;
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
    // Search for loop using slow and
    // fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    // If loop does not exist
    if (slow != fast)
        return NULL;
    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

