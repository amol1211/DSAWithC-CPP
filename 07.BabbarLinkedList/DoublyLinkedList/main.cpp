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

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;

    print(head);
    cout << getLength(head) << '\n';

    insertAtHead(head, 11);
    print(head);

    insertAtHead(head, 13);
    print(head);

    insertAtHead(head, 8);
    print(head);

    return 0;
}