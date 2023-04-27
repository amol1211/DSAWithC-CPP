#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head; // Global variable which can be accessed anywhere 

void Insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void print_forward(Node* p) {
    if (p == NULL) return;
    cout << p->data << " ";
    print_forward(p->next);
}

void print_reverse(Node* p) {
    if ( p == NULL) return;
    print_reverse(p->next);
    cout << p->data << " ";
}

int main() {
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    cout << "Elements of linked list in forward order: " << '\n';
    print_forward(head);
    cout << '\n';
    cout << "Elements of linked list in reverse order: " << '\n';
    print_reverse(head);
    cout << '\n';
    return 0;
}