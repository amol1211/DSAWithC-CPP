#include <iostream> // Include the input-output stream library

using namespace std; // Use the standard namespace

struct Node { // Define a structure for a node in the linked list
    int data;    // Integer data to store in the node
    Node* next;  // Pointer to the next node
};

Node* head; // Declare a global variable to store the head of the linked list

void Print() {
    Node* temp = head; // Create a temporary pointer to traverse the linked list
    while (temp != NULL) { // Loop until the end of the list
        cout << temp->data << " "; // Print the data in the current node
        temp = temp->next; // Move to the next node
    }
    cout << '\n'; // Print a new line after printing the list
}

void Insert(int data, int n) {
    Node* temp1 = new Node(); // Create a new node using dynamic memory allocation
    temp1->data = data; // Set the data of the new node
    temp1->next = NULL; // Initialize the next pointer to NULL

    if(n == 1) { // If the new node should be inserted at the beginning
        temp1->next = head; // Set the next pointer of the new node to the current head
        head = temp1; // Update the head to point to the new node
        return; // Exit the function
    }

    Node* temp2 = head; // Create another temporary pointer to traverse the list
    for(int i = 0; i < n-2; ++i ) { // Traverse to the (n-1)-th node
        temp2 = temp2->next;
    }
    temp1->next = temp2->next; // Set the next pointer of the new node
    temp2->next = temp1; // Update the next pointer of the (n-1)-th node to point to the new node
}

int main() {
    Node* head = NULL; // Initialize an empty linked list with local head variable
    Insert(2,1); // Insert 2 at position 1
    Insert(3,2); // Insert 3 at position 2
    Insert(4,1); // Insert 4 at position 1
    Insert(5,2); // Insert 5 at position 2
    Print(); // Print the linked list
    return 0; // Return 0 to indicate successful completion
}
