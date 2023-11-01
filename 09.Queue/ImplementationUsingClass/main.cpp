#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << '\n';
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << '\n';
        } else {
            front++;
            if (front == rear) {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << '\n';
            return -1; // Or use another error handling mechanism, like throwing an exception.
        } else {
            return arr[front];
        }
    }
};

int main() {
    Queue q;

    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front of the queue: " << q.getFront() << endl;

    q.dequeue();
    cout << "Front of the queue after dequeue: " << q.getFront() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.dequeue(); // This should print "Queue is empty" message.

    return 0;
}
