#include <iostream>
#include <stack>
using namespace std;

// This function inserts the 'num' element into the 'stack' while keeping the stack sorted in ascending order.
// If the 'stack' is empty or 'num' is greater than the top element, it directly pushes 'num' onto the 'stack'.
// Otherwise, it temporarily removes the top element, makes a recursive call, and then reinserts the top element.
void sortedInsert(stack<int> &stack, int num) {
    // Base case: If the stack is empty or 'num' is greater than the top element, push 'num' onto the stack.
    if (stack.empty() || (!stack.empty() && stack.top() < num)) {
        stack.push(num);
        return;
    }

    // Remove the top element from the stack.
    int n = stack.top();
    stack.pop();

    // Recursive call to insert 'num' in the correct position.
    sortedInsert(stack, num);

    // Reinsert the previously removed top element.
    stack.push(n);
}

// This function sorts the 'stack' in ascending order using a recursive approach.
// It recursively pops elements from the 'stack', sorts the remaining elements,
// and then inserts each popped element back into the sorted 'stack'.
void sortStack(stack<int> &stack) {
    // Base case: If the stack is empty, no further action is required.
    if (stack.empty()) {
        return;
    }

    // Remove the top element from the stack.
    int num = stack.top();
    stack.pop();

    // Recursively sort the remaining elements in the stack.
    sortStack(stack);

    // Insert the previously removed element back into the sorted stack.
    sortedInsert(stack, num);
}

//Time Complexity:  O(n^2) 
//Space Complexity: O(n)