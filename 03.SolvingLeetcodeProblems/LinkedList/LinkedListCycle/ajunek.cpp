// 141. Linked List Cycle

// Approach 1: Hash Table

class Solution{
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> visited_nodes;
        ListNode *current_node = head;

        while (current_node != nullptr) {
            if (visited_nodes.find(current_node) != visited_nodes.end()) {
                return true;
            }
            visited_nodes.insert(current_node);
            current_node = current_node->next;
        }
        return false;
    }
};

/*------------------------------------------------------------------*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow_pointer = head, *fast_pointer = head;
        while (fast_pointer != nullptr && fast_pointer->next != nullptr) {
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
            if (slow_pointer == fast_pointer) {
                return true;
            }
        }
        return false;
    }
};