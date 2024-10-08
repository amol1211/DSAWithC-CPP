#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    //Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->next = nullptr;
    }

    ~Node() {
        int val = this->data;
        cout << "Memory free for node with data " << val << '\n';
    }
};

void insertNode(Node* &tail, int element, int data) {
    //Empty list
    if (tail == nullptr) {
        Node* newNode = new Node(data);
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else {
        // Non-empty list
        // Assuming that the element is present is present in the list

        Node* curr = tail->next;

        do {
            if (curr->data == element) {
                Node* temp = new Node(data);
                temp->next  = curr->next;
                temp->prev = curr;
                curr->next->prev = temp;
                curr->next = temp;
                return;
            }
            curr = curr->next;
        } while (curr != tail->next);
    }
}

void print(Node* tail) {
    Node* temp = tail;

    if (tail == nullptr) {
        cout << "List is empty " << '\n';
        return;
    }

    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << '\n';
}


void deleteNode(Node* &tail, int val) {
    //Empty list
    if (tail == nullptr) {
        cout << "List is already empty, please check again" << '\n';
        return;
    }
    else {
        // Non-empty
        Node* curr = tail->next;

        do {
            if (curr->data == val) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                if (curr == tail) {
                    tail = curr->prev;
                }

                delete curr;
                return;
            }
            curr = curr->next;
        } while (curr != tail->next);
    }
}

int main() {
    Node* tail = nullptr;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    
    return 0;
}