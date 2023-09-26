#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

//Traversing a linked list
void print(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

//Gives length of linked list
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;

    while(temp != nullptr) {
        length++;
        temp = temp->next;
    }

    return length;
}

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {

    //Insert at start
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1) {
        temp = temp->next;
        count++;
    }

    //Inserting at last position
    if(temp->next == nullptr) {
        insertAtTail(tail, data);
        return;
    }

    //Creating a node for data;
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout << getLength(head) << '\n';

    insertAtHead(head, 11);
    print(head);

    insertAtHead(head, 13);
    print(head);

    insertAtHead(head, 8);
    print(head);

    insertAtTail(tail, 25);
    print(head);

    insertAtPosition(head, tail, 2, 100);
    print(head);

    insertAtPosition(head, tail, 1, 101);
    print(head);

    insertAtPosition(head, tail, 8, 102);
    print(head);

    return 0;
}