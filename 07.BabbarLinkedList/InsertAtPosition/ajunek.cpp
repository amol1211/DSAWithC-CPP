#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp; 
}

void print(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    
    //Inserting at start
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int count = 1;

    while(count < position - 1) {
        temp = temp->next;
        count++;
    }

    //Inserting at end
    if (temp->next == nullptr) {
        insertAtTail(tail, data);
        return;
    }

    //Creating a new node for data
    Node* NodeToInsert = new Node(data);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 15);
    print(head);

    insertAtPosition(head,tail, 3, 22);
    print(head);

    return 0;
}