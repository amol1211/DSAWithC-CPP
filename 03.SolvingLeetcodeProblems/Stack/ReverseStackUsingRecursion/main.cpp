#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:

    // This function inserts an element at the bottom of the stack using recursion.
    void insertAtBottom(stack<int> &s, int element) {
        
        if (s.empty()) {
            // If the stack is empty, simply push the element to the stack.
            s.push(element);
            return;
        }
        
        // Store the top element of the stack.
        int num = s.top();
        s.pop();
        
        // Recursively call insertAtBottom to push the element to the bottom.
        insertAtBottom(s, element);
        
        // Push the previously stored element back on top.
        s.push(num);
    }
    
    // This function reverses the given stack using recursion.
    void Reverse(stack<int> &St){
        
        if (St.empty()) {
            // If the stack is empty, we're done.
            return;
        }
        
        // Store the top element of the stack.
        int num = St.top();
        St.pop();
        
        // Recursively call Reverse to reverse the remaining part of the stack.
        Reverse(St);
        
        // Insert the stored element at the bottom of the reversed stack.
        insertAtBottom(St, num);
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)