#include <iostream>
using namespace std;

class Deque {
    int *arr;   // Array to store deque elements
    int front;  // Index of the front element
    int rear;   // Index of the rear element
    int size;   // Maximum size of the deque

public:
    // Initialize your data structure.
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1; // Initialize front and rear to -1 to indicate an empty deque
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x) {
        // Check if the deque is full
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            front = rear = 0; // If the deque is empty, set front and rear to 0
        } else if (front == 0 && rear != size - 1) {
            front = size - 1; // Wrap around to the end of the array
        } else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x) {
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0; // Wrap around to the beginning of the array
        } else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront() {
        if (isEmpty()) {
            return -1; // Return -1 to indicate an empty deque
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) {
            front = rear = -1; // Single element is present
        } else if (front == size - 1) {
            front = 0; // Wrap around to the beginning
        } else {
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear() {
        if (isEmpty()) {
            return -1; // Return -1 to indicate an empty deque
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear) {
            front = rear = -1; // Single element is present
        } else if (rear == 0) {
            rear = size - 1; // Wrap around to the end
        } else {
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty() {
        return (front == -1);
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull() {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1))) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    // Create a deque with a maximum size of 5
    Deque dq(5);

    // Push elements to the front and rear of the deque
    dq.pushFront(1);
    dq.pushRear(2);
    dq.pushFront(3);
    dq.pushRear(4);
    dq.pushFront(5);

    // Check if the deque is full
    if (dq.isFull()) {
        cout << "Deque is full." << endl;
    } else {
        cout << "Deque is not full." << endl;
    }

    // Print the front and rear elements
    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    // Pop elements from the front and rear
    cout << "Popped from Front: " << dq.popFront() << endl;
    cout << "Popped from Rear: " << dq.popRear() << endl;

    return 0;
}

//Time complexity: O(1) for each operation.
//Space complexity: O(n)