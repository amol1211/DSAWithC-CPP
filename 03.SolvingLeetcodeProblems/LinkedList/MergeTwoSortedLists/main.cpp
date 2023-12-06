//21. Merge Two Sorted Lists
#include <iostream>
using namespace std;

//Approach 1:

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        while (ptr1 && ptr2) {
            if (ptr1->val <= ptr2->val) {
                current->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                current->next = ptr2;
                ptr2 = ptr2->next;
            }
            current = current->next;
        }

        if (ptr1) {
            current->next = ptr1;
        } else if (ptr2) {
            current->next = ptr2;
        }

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};

/* The time complexity of this function is O(m + n), 
where m is the number of nodes in list1, and n is the 
number of nodes in list2.
Space complexity : O(1) 
/*------------------------------------------------------*/

//Approach 1: Recursive 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if((list1->val)<(list2->val))
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else 
        {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};

// Space complexity : O(m + n)
// Space complexity : O(m + n)

/*------------------------------------------------------------*/

//Approach 3:

class Solution {
public:
    // Helper function to merge two sorted linked lists
    ListNode* solve(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = list2;
        ListNode* next2 = curr2->next;

        // Iterate through both lists
        while (next1 != nullptr && curr2 != nullptr) {
            if (curr2->val >= curr1->val && curr2->val <= next1->val) {
                // Add curr2 in between the first list
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;

                // Update the pointers
                curr1 = curr2;
                curr2 = next2;
            } else {
                curr1 = next1;
                next1 = next1->next;

                if (next1 == nullptr) {
                    // If we reach the end of list1, append the rest of list2 to list1
                    curr1->next = curr2;
                    return list1;
                }
            }
        }

        // Handle the case where there are remaining elements in list2
        if (next1 == nullptr && curr2 != nullptr) {
            curr1->next = curr2;
        }

        return list1;
    }

    // Main function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) 
            return list2;
        
        if (list2 == nullptr) 
            return list1;
        
        if (list1->val <= list2->val) {
            return solve(list1, list2);
        } else {
            return solve(list2, list1);
        }
    }
};

//Time Complexity: O(m + n) where m and n are the lengths of the two input lists.
//Space Complexity: O(1), constant space.




