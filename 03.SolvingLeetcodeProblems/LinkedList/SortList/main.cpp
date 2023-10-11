//148. Sort List
//Sort the given linked list using Merge Sort. 
class Solution {
public:
    ListNode* findMid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* left, ListNode* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;

    while (left != nullptr && right != nullptr) {
        if (left->val < right->val) {
            temp->next = left;
            left = left->next;
        }
        else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    // Handle remaining nodes if any
    if (left != nullptr) {
        temp->next = left;
    }
    if (right != nullptr) {
        temp->next = right;
    }

    ans = ans->next;
    return ans;
}
    ListNode* sortList(ListNode* head) {
        //Base case
       if (!head || !head->next) return head;

       
       //Break linked list into two halves
       ListNode* mid = findMid(head);

       ListNode* left = head;
       ListNode* right = mid->next;
       mid->next = nullptr;

       //Recursive call to sort both halves
       left = sortList(left);
       right = sortList(right);

       //Merge both left and right halves into one list
       ListNode* result = merge(left,right);

       return result;
    }
};

//Time Complexity: O(N log N) 
//Space Complexity: O(log N) 