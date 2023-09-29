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

    ~Node() {
        int val = this->data;
        if (this->next != nullptr) {
            delete next;
        }
        cout << "Memory free for node with data " << val << '\n';
    }
};

void insertNode(Node* &tail, int element, int data) {

    //Empty list
    if (tail == nullptr) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        //Non-empty list
        //Assuming that the element is present in the list

        Node* curr = tail;

        while (curr->data != element) {
            curr = curr->next;
        }

        //Element found ->curr is representing element's node
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
} 

void print(Node* tail) {
    Node* temp = tail;

    if(tail == nullptr) {
        cout << "List is empty " << '\n';
        return;
    }

    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << '\n';
}

void deleteNode(Node* &tail, int val) {

    //Empty list
    if (tail == nullptr) {
        cout << "List is already empty, please check again" << '\n';
        return;
    }
    else {
        //Non-empty
        //Assuming that "val" is present in the list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //Single node linked list
        if (curr == prev) {
            tail = nullptr;
        }

        //>= 2 Node linked list
        else if (tail == curr) {
            tail = prev;
        }
        curr->next = nullptr;
        delete curr;
    }
}

int main() {
    Node* tail = nullptr;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 5);
    print(tail);


    return 0;
}