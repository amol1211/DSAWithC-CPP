#include <iostream>
#include <queue>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;

    //Constructor
    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {

        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1) {
            int parent = index/2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void deleteFromHeap() {
        if(size  == 0) {
            cout << "nothing to delete" << endl;
            return;
        }
        
        //Step 1 : Put last element into first index
        arr[1] = arr[size];

        //Step 2 : Remove last element
        size--;

        //Step 3 : Take root node to it's correct position
        int i = 1;
        while(i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else {
                return;
            }
        }

    }
};

//Very important heapify algo

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

//Heap Sort algo
void heapSort(int arr[], int n) {
    int size = n;

    while(size > 1) {
        //step 1 : swap
        swap(arr[size], arr[1]);
        size--;
         
        //step 2 
        heapify(arr, size, 1);
    }
}
int main() {

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();

    //Heapify algo 
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    
    //Heap creation
    for (int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "printing the array now " << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    //heap sort call
    heapSort(arr, n);

    cout << "printing sorted array " << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    cout << "using Priority Queue here" << endl;

    //Max-heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    
    cout << "Element at top is " << pq.top() << endl;
    pq.pop();
    cout << "Element at top is " << pq.top() << endl;
    cout << " Size is " << pq.size();

    if (pq.empty()) {
        cout << "pq is empty ";
    }
    else {
        cout << " pq is not empty ";
    }
    
    //Min-heap
    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "Element at top is " << minheap.top() << endl;
    minheap.pop();
    cout << "Element at top is " << minheap.top() << endl;
    cout << " Size is " << minheap.size();

    if (minheap.empty()) {
        cout << "minheap is empty";
    }
    else {
        cout << " minheap is not empty ";
    }

    return 0;
}

/*Insertion in Heap:

Time Complexity: O(log n)
Space Complexity: O(1)
Inserting an element into a heap involves finding the correct position for the new element and then percolating it up (also known as "heapifying up") to maintain the heap property.
Deletion in Heap:

Time Complexity: O(log n)
Space Complexity: O(1)
Deleting an element from a heap typically involves removing the root node, replacing it with the last element, and then percolating this element down (also known as "heapifying down") to maintain the heap property.
Heapify Algorithm (Building Heap):

Time Complexity: O(n)
Space Complexity: O(1)
Heapify is used to build a heap from an array of elements. It starts from the last non-leaf node and iterates up to the root, calling the heapify procedure on each node. Since it traverses each node once, the time complexity is linear.
Heap Sort Algorithm:

Time Complexity: O(n log n)
Space Complexity: O(1)
Heap sort first builds a heap from the input array (using heapify) in O(n) time, then repeatedly extracts the maximum element from the heap (root of the heap), swaps it with the last element in the heap, and then heapifies the remaining heap. The overall time complexity is O(n log n), as each extraction takes O(log n) time and there are n such extractions.
These complexities assume a binary heap, where each node has at most two children. Additionally, these complexities are based on the assumption that the heap is implemented using an array-based data structure.*/

//In max-heap parent node is greater than both the child nodes.
//And in min-heap parent node is smaller than both the child nodes.

/* In -based indexing
 leftIndex = 2 * i;
 rightIndex = 2 * i + 1;
 parentIndex = i / 2 
 &&
 In 0-based indexing
 leftIndex = 2 * i + 1;
 rightIndex = 2 * i + 2;
 parentIndex = i / 2
 */