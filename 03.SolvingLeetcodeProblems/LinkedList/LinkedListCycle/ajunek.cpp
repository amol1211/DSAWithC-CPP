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

