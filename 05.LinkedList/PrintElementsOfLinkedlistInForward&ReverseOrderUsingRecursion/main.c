#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data; // Data stored in the node
    struct Node* next; // Pointer to the next node
};

struct Node* head; // Head of the linked list

// Function to insert a new node at the beginning of the linked list
void insert(int x) {
    // Allocate memory for the new node
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x; // Store the data in the new node
    temp->next = head; // Set the next pointer of the new node to the current head
    head = temp; // Update the head of the linked list to the new node
}

// Recursive function to print the elements of the linked list in forward order
void print_forward(struct Node* p) {
    if (p == NULL) return; // Base case: return if we have reached the end of the list
    printf("%d ", p->data); // Print the data of the current node
    print_forward(p->next); // Recursively call the function with the next node
}

// Recursive function to print the elements of the linked list in reverse order
void print_reverse(struct Node* p) {
    if (p == NULL) return; // Base case: return if we have reached the end of the list
    print_reverse(p->next); // Recursively call the function with the next node
    printf("%d ", p->data); // Print the data of the current node
}

int main() {
    head = NULL; // Initialize the head of the linked list to NULL
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    printf("Elements of linked list in forward order: ");
    print_forward(head); // Call the function to print the linked list in forward order
    printf("\n");
    printf("Elements of linked list in reverse order: ");
    print_reverse(head); // Call the function to print the linked list in reverse order
    printf("\n");
    return 0;
}
