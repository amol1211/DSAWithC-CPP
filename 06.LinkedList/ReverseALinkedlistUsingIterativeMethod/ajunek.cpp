 #include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head;

void Insert(int x) {
    Node* temp = new Node; // Create a new node
    temp->data = x;        // Set the data of the new node
    temp->next = nullptr;  // Set the next pointer to nullptr

    if (head == nullptr) { // If the linked list is empty
        head = temp;       // Make the new node the first node (head)
        return;            // Exit the function
    }

    Node* last = head;     // Create a pointer to traverse the list
    while (last->next != nullptr) {
        last = last->next; // Move to the last node
    }

    last->next = temp;     // Link the new node to the last node
}

void Print() {
    Node* temp = head;     // Start at the head of the list
    while (temp != nullptr) {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next;         // Move to the next node
    }
    cout << '\n';
}

void Reverse() {
    Node* prev = nullptr;   // Initialize a pointer to previous node
    Node* current = head;   // Initialize a pointer to current node
    Node* nextNode;         // Initialize a pointer to next node

    while (current != nullptr) { // Loop through the linked list
        nextNode = current->next; // Save the next node
        current->next = prev;     // Change next to point to previous node

        prev = current;           // Move prev and current one step forward
        current = nextNode;
    }

    head = prev; // Update the head to the last node (new first node)
}

int main() {
    head = nullptr;     // Initialize head to nullptr
    Insert(2);          // Insert nodes into the linked list
    Insert(4);
    Insert(6);
    Insert(5);
    Print();            // Print the original linked list

    cout << "Reversing the linked list...\n";
    Reverse();          // Reverse the linked list
    Print();            // Print the reversed linked list

    return 0;
}
