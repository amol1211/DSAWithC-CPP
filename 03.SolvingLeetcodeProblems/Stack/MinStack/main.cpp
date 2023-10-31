//155. Min Stack

#include <iostream>
#include <stack>
using namespace std;

//Approach 1 : Two-Stack Approach

class MinStack {
public:
    stack<int> s;         // Stack for storing values.
    stack<int> minStack;  // Stack for tracking minimum values.

    MinStack() {
        // Constructor, no need for any specific initialization.
    }
    
    void push(int x) {
        s.push(x);  // Push the value to the value stack.

        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);  // If the minimum stack is empty or the value is less than or equal to the current minimum, push it to the minimum stack.
        }
    }
    
    void pop() {
        if (!s.empty()) {
            if (s.top() == minStack.top()) {
                minStack.pop();  // If the value being popped is also the current minimum, pop it from the minimum stack.
            }
            s.pop();  // Pop the value from the value stack.
        }
    }
    
    int top() {
        if (!s.empty()) {
            return s.top();  // Return the top value from the value stack.
        }
        return -1;  // If the stack is empty, return -1 to indicate an error.
    }
    
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();  // Return the top value from the minimum stack, which is the current minimum.
        }
        return -1;  // If the minimum stack is empty, return -1 to indicate an error.
    }
};

//Time Complexity: O(1)
//Space Complexity: O(n)

/*-----------------------------------------------------------------------------*/

//Approach 2 : Flag Value Approach

class MinStack {
public:
    stack<long> s;  // A stack to store values (long is used to handle potential overflow).
    long mini;      // A variable to keep track of the minimum value.

    MinStack() {
        // Constructor, no need for any specific initialization.
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);      // If the stack is empty, push the value.
            mini = x;        // Update the minimum.
        }
        else if(x <= mini){
            s.push(2ll*x - mini);  // If the value is less than or equal to the minimum, store a "flag" and update the minimum.
            mini = x;
        }
        else{
            s.push(x);  // If the value is greater than the current minimum, push it to the stack as a normal value.
        }
    }
    
    void pop() {
        if(s.empty()) return;  // If the stack is empty, no action is needed.

        if(s.top() < mini){
            mini = 2ll*mini - s.top();  // If the top value in the stack is less than the minimum, update the minimum before popping.
        }
        s.pop();  // Pop the top value from the stack.
    }
    
    int top() {
        if(s.empty()) return -1;  // If the stack is empty, return -1 to indicate an error.

        if(s.top() < mini){
            return mini;  // If the top value in the stack is less than the minimum, return the minimum value.
        }
        return s.top();  // Otherwise, return the top value in the stack.
    }
    
    int getMin() {
        if(s.empty()) return -1;  // If the stack is empty, return -1 to indicate an error.

        return mini;  // Return the minimum value.
    }
};

//Time Complexity: O(1)
//Space Complexity: O(1)


