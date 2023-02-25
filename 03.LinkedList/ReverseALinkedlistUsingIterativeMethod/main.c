#include <stdio.h>
#include <stdlib.h>

// Structure for each node in the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head; // Global variable, can be accessed anywhere

// Function to insert a node with the specified value at the end of the linked list
void Insert(int x) {
    // Allocate memory for a new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; // Store the data in the new node
    temp->next = NULL; // Initialize the next pointer to NULL

    if (head == NULL) { // If the linked list is empty,
        head = temp; // the new node becomes the head
        return;
    }

    // Find the last node in the linked list
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Add the new node to the end of the linked list
    last->next = temp;
}

// Function to print the linked list
void Print() {
    struct Node* temp = head; // Start at the head of the linked list
    while (temp != NULL) { // Until the end of the linked list is reached,
        printf("%d ", temp->data); // print the data stored in the current node
        temp = temp->next; // move to the next node
    }
    printf("\n"); // Move to the next line after printing the linked list
}

// Function to reverse the linked list
void Reverse() {
    struct Node *current, *prev, *next; // Declare three pointers to traverse the linked list
    current = head; // Set the current pointer to the head of the linked list
    prev = NULL; // Initialize prev to NULL
    
    // Continue as long as the current node is not NULL
    while (current != NULL) {
        next = current->next; // Store the next node in the linked list in next
        current->next = prev; // Reverse the direction of the current node's next pointer
        prev = current; // Move prev to the current node
        current = next; // Move current to the next node
    }
    head = prev; // Update the head of the linked list to the reversed linked list
}

int main() {
    head = NULL; // Initialize an empty linked list.
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Print(); // Prints "2 4 6 8"
    Reverse();
    Print(); // Prints "8 6 4 2"
    return 0;
}
