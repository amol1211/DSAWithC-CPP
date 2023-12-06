//Sort linked list of 0s, 1s and 2s (GFG)-

#include <iostream>
using namespace std;

//Approach 1

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == 0) 
                zeroCount++;
            
            else if (temp->data == 1) 
                oneCount++;
            
            else if (temp->data == 2) 
                twoCount++;
                
            temp = temp->next;    
            
        }
            temp = head;

        
        while (temp != nullptr) {
            if (zeroCount != 0) {
                temp->data = 0;
                zeroCount--;
            }
            else if (oneCount != 0) {
                temp->data = 1;
                oneCount--;
            }
            else if (twoCount != 0) {
                temp->data = 2;
                twoCount--;
            }
            temp = temp->next;
        }
        
        return head;
    }
};

/*---------------------------------------------------------------*/

//Approach 2

class Solution
{
    public:
    
    void insertAtTail(Node* &tail, Node* curr) {
        tail->next = curr;
        tail = curr;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* curr = head;
        
        //Creating separate list of 0's, 1's, 2's
        while (curr != nullptr) {
            
            int value = curr->data;
            
            if (value == 0) {
                insertAtTail(zeroTail, curr);
            }
            else if (value == 1) {
                insertAtTail(oneTail, curr);
            }
            else if (value == 2) {
                insertAtTail(twoTail, curr);
            }
            curr = curr->next;
        }
        
        //Merging 3 sublists into one 
        //if 1's list is not empty
        if (oneHead->next != nullptr) {
            zeroTail->next = oneHead->next;
        }
        else {
            //if 1's list is empty
            zeroTail->next = twoHead->next;
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = nullptr;
        
        //Set up head
        
        head = zeroHead->next;
        
        //Deleting dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};

//Time complexity : O(n)
//Space complexity : O(1)

