//641. Design Circular Deque

#include <iostream>
#include <queue>
using namespace std;

class MyCircularDeque {
public:
    int *arr;    // An array to store elements in the circular deque.
    int front;   // Pointer to the front element.
    int rear;    // Pointer to the rear element.
    int size;    // Maximum size of the deque.

    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;  // Initialize front and rear pointers to -1 to indicate an empty deque.
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;  // If the deque is full, return false.
        }
        if (isEmpty()) {
            front = rear = 0;  // If the deque is empty, set front and rear to 0.
        } else {
            front = (front - 1 + size) % size;  // Move front pointer in a circular manner.
        }
        arr[front] = value;  // Insert the value at the new front position.
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;  // If the deque is full, return false.
        }
        if (isEmpty()) {
            front = rear = 0;  // If the deque is empty, set front and rear to 0.
        } else {
            rear = (rear + 1) % size;  // Move rear pointer in a circular manner.
        }
        arr[rear] = value;  // Insert the value at the new rear position.
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;  // If the deque is empty, return false.
        }
        if (front == rear) {
            front = rear = -1;  // If there's only one element, set front and rear to -1.
        } else {
            front = (front + 1) % size;  // Move front pointer in a circular manner.
        }
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;  // If the deque is empty, return false.
        }
        if (front == rear) {
            front = rear = -1;  // If there's only one element, set front and rear to -1.
        } else {
            rear = (rear - 1 + size) % size;  // Move rear pointer in a circular manner.
        }
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;  // If the deque is empty, return -1.
        }
        return arr[front];  // Return the element at the front position.
    }

    int getRear() {
        if (isEmpty()) {
            return -1;  // If the deque is empty, return -1.
        }
        return arr[rear];  // Return the element at the rear position.
    }

    bool isEmpty() {
        return front == -1;  // Check if the front pointer is -1 to determine if the deque is empty.
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);  // Check if the deque is full.
    }
};


/*--------------------------------------------------------------------------------*/

class MyCircularDeque {
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularDeque(int k) {
        size=k;
        arr=new int [size];
        front =-1;
        rear =-1;
    }
    
    bool insertFront(int value) {
         if(isFull()){
            // cout<<"queue is full";
            return false;
        }
        // for first element push
         if(front==-1 && rear==-1){
            front = rear =0;
        }
        else if(front == 0){  
           front=size-1;
        }
        else{
            front--;
        }
        arr[front]=value;

        return true;
    }
    
    bool insertLast(int value) {
          if(isFull()){
            // cout<<"queue is full";
            return false;
        }
        // for first element push
         if(front==-1 && rear==-1){
            front = rear =0;
        }
        else{  
            rear=(rear+1)%size;
        }
        arr[rear]=value;

        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){ //to check queue is empty
            return false;
        }
        int ans=arr[front];
        arr[front]=-1;
         if (front==rear){ //single element is present
            front=rear=-1;
        }
        else {
            front=(front+1)%size;
        }
        return true;
    }
    
    bool deleteLast() {
         if(isEmpty()){
            return false;
        }
        int ans=arr[rear];
        arr[rear]=-1;

        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
         if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1){ //to check queue is empty
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if((rear+1)%size==front){
            // cout<<"queue is full";
            return true;
         } else {
            return false;
         }
    }
};

