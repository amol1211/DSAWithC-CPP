#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head;

void Insert(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = temp;
}

void Print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

void Reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;

        prev = current;
        current = nextNode;
    }

    head = prev;
}

int main() {
    head = nullptr;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();

    cout << "Reversing the linked list...\n";
    Reverse();
    Print();

    return 0;
}