#include <iostream>
using namespace std;

// Node class to represent elements in the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Stack class using a singly linked list
class Stack {
public:
    Node* top; // Pointer to the top element of the stack

    Stack() {
        top = nullptr; // Initialize the stack as empty
    }

    // Push operation to add an element to the top of the stack
    void push(int element) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation to remove the top element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << '\n';
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek operation to get the top element without removing it
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << '\n';
            return -1; // Sentinel value to indicate an empty stack.
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack st; // Create a stack object

    // Push some elements onto the stack
    st.push(22);
    st.push(43);
    st.push(44);

    // Print the top element after each push
    cout << st.peek() << '\n';

    // Pop elements and print the top after each pop
    st.pop();
    cout << st.peek() << '\n';
    st.pop();
    cout << st.peek() << '\n';
    st.pop();
    cout << st.peek() << '\n';

    // Check if the stack is empty
    if (st.isEmpty()) {
        cout << "Stack is empty" << '\n';
    } else {
        cout << "Stack is not empty" << '\n';
    }

    return 0;
}
