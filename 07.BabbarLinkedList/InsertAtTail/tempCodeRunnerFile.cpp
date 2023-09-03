#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};


void InsertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void Print(Node* &tail) {
    Node* temp = tail;
    while (tail != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

int main() {
    Node* node1 = new Node(10);

    Node* tail = node1;
    Print(tail);

    InsertAtTail(tail, 12);
    Print(tail);

    InsertAtTail(tail, 15);
    Print(tail);
}