#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
    ~Node() {
        int val = this->next;
        if (next != nullptr) {
            delete next;
            next = nullptr;
        }
        cout << "Memory free for node with data " << val << '\n';
    }
};

//Traversing a linked list
void print(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

//Gives length of linked list
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;

    while(temp != nullptr) {
        length++;
        temp = temp->next;
    }

    return length;
}

void insertAtHead(Node* &tail, Node* &head, int data) {
    
    //Empty list
    if (head == nullptr) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
}

void insertAtTail(Node* &tail, Node* &head, int data) {

    //Empty list
    if (tail == nullptr) {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {

    //Insert at start
    if (position == 1) {
        insertAtHead(tail, head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1) {
        temp = temp->next;
        count++;
    }

    //Inserting at last position
    if(temp->next == nullptr) {
        insertAtTail(tail, head, data);
        return;
    }

    //Creating a node for data;
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node* &head) {

    //Deleting first or start node
    if (position == 1) {
        Node* temp = head;
        temp->next->prev = nullptr;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
    }
}

int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    print(head);
    //cout << getLength(head) << '\n';

    insertAtHead(tail, head, 11);
    print(head);
    cout << "head " << head->data << '\n';
    cout << "tail " << tail->data << '\n';

    insertAtHead(tail, head, 13);
    print(head);
    cout << "head " << head->data << '\n';
    cout << "tail " << tail->data << '\n';

    insertAtHead(tail, head, 7);
    print(head);
    cout << "head " << head->data << '\n';
    cout << "tail " << tail->data << '\n';

    insertAtTail(tail, head, 25);
    print(head);
    cout << "head " << head->data << '\n';
    cout << "tail " << tail->data << '\n';

    insertAtPosition(head, tail, 2, 100);
    print(head);
    cout << "head " << head->data << '\n';
    cout << "tail " << tail->data << '\n';

    insertAtPosition(head, tail, 1, 101);
    print(head);

    cout << "head " << head->data << '\n';
    cout << "tail " << tail->data << '\n';

    insertAtPosition(head, tail, 7, 102);
    print(head);
    cout << "head " << head->data << '\n';
    cout << "tail " << tail->data << '\n';

    return 0;
}