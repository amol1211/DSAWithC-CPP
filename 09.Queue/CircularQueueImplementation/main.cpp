#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;  // Pointer to the array that stores the queue elements
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int size;  // Maximum size of the queue

public:
    // Constructor
    CircularQueue(int n) {
        size = n;            // Initialize the maximum size
        arr = new int[size]; // Create an array of 'size' to store queue elements
        front = rear = -1;   // Initialize front and rear to -1 (empty queue)
    }

    // Insert 'value' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value) {
        // Check if the queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            // Queue is full
            return false;
        } else if (front == -1) {
            // First element to push
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0; // To maintain the cyclic nature
        } else {
            // Normal insert
            rear++;
        }
        // Push inside the queue
        arr[rear] = value;
        return true;
    }

    // Pops the top element from the queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue() {
        if (front == -1) { // Check if the queue is empty
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1; // Mark the element as removed
        if (front == rear) { // Single element is present
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0; // To maintain the cyclic nature
        } else {
            // Normal pop
            front++;
        }
        return ans;
    }
};

int main() {
    CircularQueue cq(5); // Create a circular queue with a maximum size of 5

    // Enqueue elements into the queue
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    // Try to enqueue one more element (queue is full, so it should return false)
    if (cq.enqueue(6)) {
        std::cout << "Enqueue successful." << std::endl;
    } else {
        std::cout << "Enqueue failed. Queue is full." << std::endl;
    }

    // Dequeue elements from the queue
    int value;
    value = cq.dequeue();
    if (value != -1) {
        std::cout << "Dequeued: " << value << std::endl;
    } else {
        std::cout << "Dequeue failed. Queue is empty." << std::endl;
    }

    // Continue dequeuing elements
    while (true) {
        value = cq.dequeue();
        if (value != -1) {
            std::cout << "Dequeued: " << value << std::endl;
        } else {
            std::cout << "Dequeue failed. Queue is empty." << std::endl;
            break;
        }
    }

    return 0;
}
