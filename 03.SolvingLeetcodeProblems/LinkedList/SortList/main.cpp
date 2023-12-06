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

/*---------------------------------------------------*/

// 2. Detecting length and using dummy node Approach

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;  // Already sorted if there is only one node or no node.
        }

        int length = getLength(head);  // Get the length of the linked list.

        ListNode* dummy = new ListNode(0);  // Create a dummy node to simplify merging.
        dummy->next = head;

        for (int step = 1; step < length; step *= 2) {
            ListNode* prev = dummy;
            ListNode* curr = dummy->next;

            while (curr) {
                // Split the list into two halves.
                ListNode* left = curr;
                ListNode* right = split(left, step);

                // Move to the next pair of lists.
                curr = split(right, step);

                // Merge the two halves and update the previous pointer.
                prev = merge(left, right, prev);
            }
        }

        head = dummy->next;
        delete dummy;  // Delete the dummy node to release memory.

        return head;
    }

    // Function to get the length of the linked list.
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

    // Function to split the linked list into two halves.
    ListNode* split(ListNode* head, int n) {
        while (head && --n) {
            head = head->next;
        }

        if (!head) {
            return nullptr;
        }

        ListNode* secondHalf = head->next;
        head->next = nullptr;

        return secondHalf;
    }

    // Function to merge two sorted linked lists.
    ListNode* merge(ListNode* left, ListNode* right, ListNode* prev) {
        while (left && right) {
            if (left->val <= right->val) {
                prev->next = left;
                left = left->next;
            } else {
                prev->next = right;
                right = right->next;
            }
            prev = prev->next;
        }

        prev->next = left ? left : right;

        while (prev->next) {
            prev = prev->next;
        }

        return prev;
    }
};

//Time Complexity: O(N log N) 
//Space Complexity: O(1) 