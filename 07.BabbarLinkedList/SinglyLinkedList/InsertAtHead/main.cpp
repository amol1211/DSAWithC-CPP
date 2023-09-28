#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};

void InsertAtHead(Node* &head, int data) {
    // Assigned Node* &head by reference because we need changes in original 
    //linked list instead of making another copy.

    // Create new node
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;  
} 

void Print(Node* &head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}


int main() {

    //Created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
    //cout << node1 -> next << endl;

    //Head is pointed to new node1
    Node* head = node1;
    Print(head);

    InsertAtHead(head, 12);
    Print(head);

    InsertAtHead(head, 15);
    Print(head);

    return 0;
}