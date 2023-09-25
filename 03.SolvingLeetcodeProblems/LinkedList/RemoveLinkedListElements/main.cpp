//203. Remove Linked List Elements

class Solution {
public:
    /*
		Approach: 1
        Solving the problem using two pointers: previous and current.
	 */
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            if(curr->val==val){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;        
            }
        }
        return head;
    }
    
    /*------------------------------------------------------------------------*/
