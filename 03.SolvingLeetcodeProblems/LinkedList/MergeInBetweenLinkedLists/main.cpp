//1669. Merge In Between Linked Lists

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Initialize pointers for left and right boundaries
        ListNode* left = nullptr;
        ListNode* right = list1;

        // Iterate through list1 to find the left boundary node
        for (int i = 0; i <= b; i++) {
            if (i == a - 1) {
                left = right;
            }
            right = right->next;
        }
        
        // Merge list2 into list1 by setting the next of left to list2
        left->next = list2;

        // Iterate through list2 to find the last node
        ListNode* temp = list2;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Connect the last node of list2 to the node after the right boundary
        temp->next = right;

        // Return the head of the modified list1
        return list1;
    }
};

/**
 * This function merges a portion of a singly-linked list (list1) with another singly-linked list (list2)
 * Parameters:
 *   - list1: The head of the first singly-linked list
 *   - a: Start index (inclusive) in list1 where merging begins
 *   - b: End index (inclusive) in list1 where merging ends
 *   - list2: The head of the second singly-linked list to be merged into list1
 * Returns:
 *   - The head of the modified list1 after merging
 * Time Complexity: O(n + m), where n is the length of list1 and m is the length of list2
 * Space Complexity: O(1)
 */


