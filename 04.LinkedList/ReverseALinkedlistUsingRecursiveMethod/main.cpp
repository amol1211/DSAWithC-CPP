#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head; //Global variable which can be accessed anywhere

void Insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

Node* reverse( Node* p ) {
    if (p->next == NULL) {
        head = p;
        return p;
    }

    Node* q = reverse(p->next);
    q->next = p;
    p->next = NULL;
    return p;
}

int main() {
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);

    cout << "Original linked list: " << '\n';
    Node* p = head;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";

    reverse(head);

    cout << "Reversed linked list: " << '\n';
    p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';

    return 0;
}