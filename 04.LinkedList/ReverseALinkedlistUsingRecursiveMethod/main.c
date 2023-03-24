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

// Recursive function to reverse the linked list
struct Node* reverse(struct Node* p) {
    // Base case: if the current node is the last node in the original list, return it
    if (p->next == NULL) {
        head = p; // Set the head of the reversed list to the current node
        return p;
    }
    // Recursive case: recursively call the function with the next node in the original list
    struct Node* q = reverse(p->next);
    q->next = p; // Set the next pointer of the next node to the current node
    p->next = NULL; // Set the next pointer of the current node to NULL
    return p; // Return the current node
}

int main() {
    head = NULL; // Initialize the head of the linked list to NULL
    insert(2);
    insert(4);
    insert(6);
    insert(5);

    printf("Original linked list: ");
    struct Node* p = head;
    // Print the original linked list
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    reverse(head); // Reverse the linked list using the recursive function

    printf("Reversed linked list: ");
    p = head;
    // Print the reversed linked list
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}
