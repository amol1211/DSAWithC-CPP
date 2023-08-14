#include <iostream>

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Declare a global variable to store the head of the linked list
Node* head = nullptr;

// Function to insert a node at the beginning of the linked list
void Insert(int x) {
    // Allocate memory for a new node
    Node* temp = new Node;
    
    // Assign data to the new node
    temp->data = x;
    
    // Point the new node's 'next' to the current head
    temp->next = head;
    
    // Update the head to the new node
    head = temp;
}

// Function to print the elements of the linked list
void Print() {
    Node* temp = head;
    
    // Print the list elements
    std::cout << "List is: ";
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Main function
int main() {
    // Initialize the head as nullptr, indicating an empty list
    head = nullptr;

    // Prompt the user for the number of elements to insert
    std::cout << "How many numbers?" << std::endl;
    int n, x;
    std::cin >> n;

    // Loop to insert elements into the linked list
    for (int i = 0; i < n; i++) {
        std::cout << "Enter the number: ";
        std::cin >> x;
        
        // Call the Insert function to add the element to the linked list
        Insert(x);
        
        // Print the linked list after each insertion
        Print();
    }
    
    // Return 0 to indicate successful completion
    return 0;
}
