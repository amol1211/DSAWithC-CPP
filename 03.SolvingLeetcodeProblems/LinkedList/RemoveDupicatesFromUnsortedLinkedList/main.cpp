#include <iostream>
using namespace std;

/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if (!head || !head->next)
        {
            return head;
        }

        unordered_set<int> seenValues;
        Node *prev = nullptr;
        Node *curr = head;

        while (curr != nullptr)
        {
            if (seenValues.find(curr->data) != seenValues.end())
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                seenValues.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
     // your code goes here
    }
};