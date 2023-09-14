//141. Linked List Cycle

//Approach 1: Hash Table

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Create a hash set to store visited nodes.
        unordered_set<ListNode*> visited_nodes;
        
        // Start from the head of the linked list.
        ListNode *current_node = head;

        // Traverse the linked list.
        while (current_node != nullptr) {
            // If the current node is already in the hash set, it means we've visited it before,
            // so there must be a cycle. Return true.
            if (visited_nodes.find(current_node) != visited_nodes.end()) {
                return true;
            }
            
            // Otherwise, insert the current node into the hash set to mark it as visited.
            visited_nodes.insert(current_node);

            // Move to the next node in the list.
            current_node = current_node->next;
        }

        // If we reach the end of the list without finding a cycle, return false.
        return false;
    }
};

//Time Complexity: O(n)O(n)O(n) — Each node is visited once.
//Space Complexity: O(n)O(n)O(n) — To store visited nodes.

/*-----------------------------------------------------------------------------------------------------------*/

//Approach 2: Two-Pointer Method (Floyd's Cycle-Finding Algorithm || Floyd's Tortoise and Hare algorithm)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Initialize two pointers, slow and fast, both initially pointing to the head of the list.
        ListNode *slow_pointer = head, *fast_pointer = head;
        
        // Traverse the list using two pointers.
        while (fast_pointer != nullptr && fast_pointer->next != nullptr) {
            // Move the slow pointer one step at a time.
            slow_pointer = slow_pointer->next;
            
            // Move the fast pointer two steps at a time.
            fast_pointer = fast_pointer->next->next;
            
            // If the slow and fast pointers meet, it means there's a cycle in the list.
            if (slow_pointer == fast_pointer) {
                return true;
            }
        }
        
        // If we reach the end of the list without finding a cycle, return false.
        return false;
    }
};

//Time Complexity: O(n) — In the worst-case scenario, each node is visited once.
//Space Complexity: O(1) — Constant space is used.
