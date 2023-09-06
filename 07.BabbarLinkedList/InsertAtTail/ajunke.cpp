#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next = nullptr;

    Node (int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node* &tail) {
    Node* temp = tail;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    return 0;
}
