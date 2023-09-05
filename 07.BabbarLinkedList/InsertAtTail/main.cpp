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

void InsertAtTail(Node*& tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void Print(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

int main() {
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    Print(head);

    InsertAtTail(tail, 12);
    Print(head);

    InsertAtTail(tail, 15);
    Print(head);

    return 0;
}
