#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    //Destructor
    ~Node() {
        int value = this->data;
        //Freeing the memory of node we're trying to delete
        if(this->next != nullptr) {
            delete next;
            this->next = nullptr;
        }
        cout << " Memory is free for node with data " << value << '\n';
    }
};

void insertAtHead(Node* &head, int data) {
    //Create a new node
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* &head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

void deleteNode(int position, Node* &head) {
    //Deleting first node
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        //free memory of the start node
        temp->next = nullptr;
        delete temp;
    }
    else {
        //Deleting any middle or last node
        Node* curr = head;
        Node* prev = nullptr;

        int count = 1;
        while(count < position) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
}

int main() {
    //Created a new node
    Node* node1 = new Node(10);

    //Head pointed to node1
    Node* head = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 15);
    print(head);



    deleteNode(3, head);
    print(head);

    return 0;
}