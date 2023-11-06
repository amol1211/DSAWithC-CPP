//232. Implement Queue using Stacks

#include <iostream>
#include <stack>
using namespace std;

//Approach 1: Push Expensive

class MyQueue {
private:
    stack<int> stack1; // Primary stack for pushing
    stack<int> stack2; // Secondary stack for popping

public:
    MyQueue() {}

    // Push operation is more expensive
    void push(int x) {
        // Reversing the order by moving elements from stack2 to stack1
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(x);
    }

    // Pop operation is less expensive
    int pop() {
        // If stack2 is empty, move elements from stack1 to stack2 to reverse order
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    // Peek operation is similar to pop
    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/*Time Complexity:
Push: O(n), where n is the number of elements in stack2 at the time of pushing.
Pop: Amortized O(1), as elements are moved from stack1 to stack2 only when stack2 is empty.
Peek: Amortized O(1), same as the pop operation.
Empty: O(1)
Space Complexity: O(n), where n is the total number of elements in both stacks.*/

/*--------------------------------------------------------------------------------------------------*/

//Approach 2: Pop Expensive

class MyQueue {
private:
    std::stack<int> stack1; // Primary stack for pushing
    std::stack<int> stack2; // Secondary stack for popping

public:
    MyQueue() {}

    // Push operation is less expensive
    void push(int x) {
        stack1.push(x);
    }

    // Pop operation is more expensive
    int pop() {
        // If stack2 is empty, move elements from stack1 to stack2 to reverse order
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    // Peek operation is similar to pop
    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/*Time Complexity:
Push: O(1)
Pop: Amortized O(1), as elements are moved from stack1 to stack2 only when stack2 is empty.
Peek: Amortized O(1), same as the pop operation.
Empty: O(1)
Space Complexity: O(n), where n is the total number of elements in both stacks.*/