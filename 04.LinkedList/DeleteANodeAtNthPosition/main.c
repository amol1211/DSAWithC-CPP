#include <stdlib.h>
#include <stdio.h>

// Structure for each node in the linked list
struct Node{
    int data; // Data stored in the node
    struct Node* next; // Pointer to the next node in the linked list
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

// Function to delete a node at the specified position in the linked list
void Delete(int n){
    struct Node* temp1 = head; // Start at the head of the linked list
    if(n == 1) { // If the first node is to be deleted,
        head = temp1->next; // the head now points to the second node.
        free(temp1); // The first node is freed.
        return;
    }
    int i;
    for (i = 0; i < n-2; i++) { // Move to the (n-1)th node.
        temp1 = temp1->next; // temp1 points to the (n-1)th node.
    }
    struct Node* temp2 = temp1->next; // The nth node is stored in temp2.
    temp1->next = temp2->next; // The (n+1)th node is now linked to the (n-1)th node.
    free(temp2); // The nth node is freed.
}

int main(){
    head = NULL; // Initialize an empty linked list.
    Insert(2); 
    Insert(4); 
    Insert(6); 
    Insert(5); 
    Print(); // Prints "2,4,6,5"
    int n;
    printf("Enter a position you want to delete the data value of\n");
    scanf("%d", &n);
    Delete(n); // Deletes the node at the specified position.
    Print(); // Prints the updated linked list.
}
