//622. Design Circular Queue

#include <iostream>
using namespace std;

class MyCircularQueue {
public:
    int *arr;  // An array to store the elements of the circular queue.
    int front;  // Index pointing to the front of the queue.
    int rear;   // Index pointing to the rear of the queue.
    int size;   // The maximum size of the circular queue.

    MyCircularQueue(int k) {
        size = k;    // Initialize the maximum size of the circular queue.
        arr = new int[size];  // Create an array of integers to hold the elements.
        front = rear = -1;   // Initialize front and rear indices to -1 (empty queue).
    }
    
    bool enQueue(int value) {
        if (isFull()) {  // If the circular queue is full (check with isFull method)
            return false;  // Return false, indicating that the enqueue operation failed.
        }
        else if (front == -1) {  // If the queue is empty.
            front = rear = 0;   // Initialize front and rear to the first index.
        }
        else if (rear == size - 1 && front != 0) {  // If rear is at the end of the array.
            rear = 0;  // Wrap around to the beginning.
        }
        else {
            rear++;  // Move rear to the next available index.
        }

        arr[rear] = value;  // Insert the value at the rear position.
        return true;  // Return true, indicating a successful enqueue operation.
    }
    
    bool deQueue() {
        if (isEmpty()) {  // If the circular queue is empty (check with isEmpty method).
            return false;  // Return false, indicating that the dequeue operation failed.
        }

        if (front == rear) {  // If there's only one element in the queue.
            front = rear = -1;  // Set front and rear to -1, indicating an empty queue.
        }
        else if (front == size - 1) {  // If front is at the end of the array.
            front = 0;  // Wrap around to the beginning.
        }
        else {
            front++;  // Move front to the next available index.
        }
        return true;  // Return true, indicating a successful dequeue operation.
    }
    
    int Front() {
        if (isEmpty()) return -1;  // If the queue is empty, return -1.
        return arr[front];  // Otherwise, return the element at the front.
    }
    
    int Rear() {
        if (isEmpty()) return -1;  // If the queue is empty, return -1.
        return arr[rear];  // Otherwise, return the element at the rear.
    }
    
    bool isEmpty() {
        return front == -1;  // Return true if the queue is empty (front is -1).
    }
    
    bool isFull() {
        return (rear + 1) % size == front;  // Return true if the queue is full (next position of rear is front).
    }
};
