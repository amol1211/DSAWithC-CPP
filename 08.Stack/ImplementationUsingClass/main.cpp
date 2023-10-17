#include <iostream>
#include <stack>
using namespace std;


class Stack {
    // Properties
public:
    int *arr; // Pointer to an array to store stack elements.
    int top;  // Index of the top element.
    int size; // Maximum size of the stack.

    // Constructor
    Stack(int size) {
        this->size = size;
        arr = new int(size); // Allocating memory for the stack.
        top = -1; // Initializing top to -1 (stack is initially empty).
    }

    void push(int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << "Stack overflow" << '\n';
        }
    }   

    void pop() {
        if (top >= 0) {
            top--;
        }
        else {
            cout << "Stack underflow" << '\n';
        }
    } 

    int peek() {
        if (top >= 0) 
            return arr[top];
        else {
            cout << "Stack is empty" << '\n';
            return -1;
        }
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);


    cout << st.peek() << '\n';

    st.pop();

    cout << st.peek() << '\n';

    st.pop();

    cout << st.peek() << '\n';

    st.pop();

    cout << st.peek() << '\n';

    if (st.isEmpty()) {
        cout << "Stack is empty" << '\n';
    }
    else {
        cout << "Stack is not empty" << '\n';
    }



    return 0;
}