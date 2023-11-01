#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (isEmpty()) {
            // If the queue is empty, set both front and rear to the new node.
            front = newNode;
            rear = newNode;
        } else {
            // Otherwise, add the new node to the end of the queue and update rear.
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << '\n';
        } else {
            // Remove the front element and update front.
            Node* temp = front;
            front = front->next;
            delete temp;

            if (front == nullptr) {
                // If the queue is now empty, also update rear.
                rear = nullptr;
            }
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << '\n';
            return -1; // Or use another error handling mechanism, like throwing an exception.
        } else {
            return front->data;
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

//Time Complexity: O(n)
//Space Complexity: O(n)