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
        if (this->next != nullptr) {
            delete next;
            this->next = nullptr;
        }
        cout << " Memory is free for node with data " << value << '\n';
    }
};

void insertAtHead(Node* &head, int data) {
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
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    else {
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
    Node* node1 = new Node(10);

    Node* head = node1;
    print(head);

    insertAtHead(head,12);
    print(head);

    insertAtHead(head,15);
    print(head);

    deleteNode(1, head);
    print(head);

    return 0;
}
