// Include necessary header files
#include <stdlib.h>
#include <stdio.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Declare a global variable to store the head of the linked list
struct Node* head;

// Function to insert a node at the beginning of the linked list
void Insert(int x) {
    // Allocate memory for a new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data to the new node
    temp->data = x;
    
    // Point the new node's 'next' to the current head
    temp->next = head;
    
    // Update the head to the new node
    head = temp;
}

// Function to print the elements of the linked list
void Print() {
    struct Node* temp = head;
    
    // Print the list elements
    printf("List is: ");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the head as NULL, indicating an empty list
    head = NULL;

    // Prompt the user for the number of elements to insert
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);

    // Loop to insert elements into the linked list
    for (i = 0; i < n; i++) {
        printf("Enter the number \n");
        scanf("%d", &x);
        
        // Call the Insert function to add the element to the linked list
        Insert(x);
        
        // Print the linked list after each insertion
        Print();
    }
    
    // Return 0 to indicate successful completion
    return 0;
}
