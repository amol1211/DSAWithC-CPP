#include <iostream>
using namespace std;

// Node struct represents each element of the linked list
struct Node {
    int data;       // Data value of the node
    Node* next;     // Pointer to the next node
};

Node* head;         // Global pointer to the head of the linked list

// Function to insert a new node at the end of the linked list
void Insert(int x) {
    Node* temp = new Node;  // Create a new node
    temp->data = x;         // Set data value of the new node
    temp->next = NULL;      // Initialize the next pointer to NULL

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        head = temp;
        return;
    }

    Node* last = head;
    // Traverse to the last node in the list
    while (last->next != NULL) {
        last = last->next;
    }
    // Append the new node to the last node
    last->next = temp;
}

// Function to print the elements of the linked list
void Print() {
    Node* temp = head;   // Start from the head
    while (temp != NULL) {
        cout << temp->data << " ";  // Print the data value
        temp = temp->next;          // Move to the next node
    }
    cout << '\n';
}

// Function to delete a node at a specified position
void Delete(int n) {
    Node* temp1 = head;     // Start from the head

    // If the node to be deleted is the first node
    if (n == 1) {
        head = temp1->next;  // Update the head pointer
        delete(temp1);       // Delete the node
        return;
    }

    // Traverse to the node just before the one to be deleted
    for (int i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;  // Node to be deleted
    temp1->next = temp2->next;  // Update next pointer of previous node
    delete(temp2);              // Delete the node
}

int main() {
    head = NULL;          // Initialize an empty linked list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();              // Print the initial linked list

    int n;
    cout << "Enter the position you want to delete the data value of: ";
    cin >> n;
    Delete(n);            // Delete node at the specified position
    Print();              // Print the updated linked list

    return 0;
}
