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
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = temp;
}

void Print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

void Reverse() {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    Reverse();
    Print();
    return 0;
}