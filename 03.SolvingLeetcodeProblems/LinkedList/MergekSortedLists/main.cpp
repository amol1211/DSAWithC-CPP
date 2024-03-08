//23. Merge k Sorted Lists

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Approach 1: Merge K Sorted Lists Using Sorting

/*
This approach merges K sorted linked lists by extracting all values, sorting them,
and then creating a new linked list from the sorted values. 
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;

        // Extract all values from the linked lists
        for (auto list : lists) {
            ListNode* curr = list;
            while (curr) {
                vals.push_back(curr->val);
                curr = curr->next;
            }
        }

        // Sort the values
        sort(vals.begin(), vals.end());

        // Create a new linked list from the sorted values
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int val : vals) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return dummy->next;
    }
};

/*Time Complexity: O(N log N), where N is the total number of nodes in all lists.
 Space Complexity: O(N), where N is the total number of nodes in all lists 
 (used for the temporary vector).*/

 /*-----------------------------------------------------------------------------------------------*/

 //Approach 2: Merge K Sorted Lists Using Divide and Conquer

 /*
This approach merges K sorted linked lists using divide and conquer.
It recursively partitions the lists and merges them in pairs.
 */

class Solution {
private:
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        // Merge two sorted lists
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
        return nullptr;
    }

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        // Partition and merge lists recursively
        if (start > end) return nullptr;
        if (start == end) return lists[start];
        
        int mid = start + (end - start) / 2;
        ListNode* L1 = partitionAndMerge(start, mid, lists);
        ListNode* L2 = partitionAndMerge(mid + 1, end, lists);
        return mergeTwoSortedLists(L1, L2);
    } 
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return nullptr;
        return partitionAndMerge(0, k - 1, lists);
    }
};

/*Time Complexity: O(N log K), where N is the total number of nodes in all lists and K is the number of lists.
Space Complexity: O(log K), for the recursion stack.*/

/*-----------------------------------------------------------------------------------------------------------------*/

//Approach 3: Merge K Sorted Lists Using Priority Queue (Min Heap)

/*
 This approach merges K sorted linked lists using a priority queue (min heap).
 It maintains a min heap of the heads of all lists, and repeatedly extracts the minimum node.
 */

// Define a comparison class for the priority queue
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Change to > for minHeap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a priority queue (min heap) of ListNode pointers with custom comparison
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();

        // Check if there are no lists, return nullptr
        if (k == 0) 
            return nullptr;

        // Insert the heads of all non-empty lists into the min heap
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }    

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        // Merge the lists until the min heap is empty
        while (!minHeap.empty()) {
            // Extract the minimum node from the min heap
            ListNode* top = minHeap.top();
            minHeap.pop();

            // Push the next node of the extracted node into the min heap
            if (top->next != nullptr) {
                minHeap.push(top->next);
            }

            // Append the extracted node to the result list
            if (head == nullptr) {
                // Result list is empty
                head = top;
                tail = top;
            } else {
                // Append the node to the end of the result list
                tail->next = top;
                tail = top;
            }
        }

        // Return the head of the merged list
        return head;
    }
};

/* Time Complexity: O(N log K), where N is the total number of nodes in all lists and K is the number of lists.
Space Complexity: O(K), for the priority queue.*/