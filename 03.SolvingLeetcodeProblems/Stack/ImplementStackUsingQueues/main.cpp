//225. Implement Stack using Queues

#include <iostream>
#include <queue>
using namespace std;

//Approach 1: Push Expensive

class MyStack {
private:
    queue<int> q1; // Main queue
    queue<int> q2; // Temporary queue

public:
    MyStack() {}

    // Push operation is more expensive
    void push(int x) {
        // Move elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element into the empty q1
        q1.push(x);

        // Move elements from q2 back to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

/*Time Complexity:
Push: O(n), where n is the number of elements in the stack (size of q1).
Pop: O(1)
Top: O(1)
Empty: O(1)
Space Complexity: O(n), where n is the number of elements in the stack (size of q1).*/

/*----------------------------------------------------------------------------------------*/

//Approach 2: Pop Expensive

class MyStack {
private:
    queue<int> q; // Main queue

public:
    MyStack() {}

    // Push operation is less expensive
    void push(int x) {
        q.push(x);
    }

    int pop() {
        // Move all elements except the last one to the back
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        // The last element is the one to be removed
        int top = q.front();
        q.pop();
        return top;
    }

    int top() {
        return q.back(); // The back element is the top
    }

    bool empty() {
        return q.empty();
    }
};

/*Time Complexity:
Push: O(1)
Pop: O(n), where n is the number of elements in the stack (size of q).
Top: O(1)
Empty: O(1)
Space Complexity: O(n), where n is the number of elements in the stack (size of q).*/