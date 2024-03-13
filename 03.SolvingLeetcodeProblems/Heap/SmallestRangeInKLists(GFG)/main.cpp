//SmallestRangeInKLists(GFG)

#include <vector>
#include <queue> // for priority_queue
#include <algorithm> // for min and max
#include <climits> // for INT_MAX and INT_MIN


using namespace std;

// Node class to store data, row, and column information
class Node {
public:
    int data; // value of the element
    int row; // row index of the element in 'KSortedArray'
    int col; // column index of the element in 'KSortedArray'

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// Comparison class to define the comparison criteria for the priority_queue
class compare {
public:
    bool operator()(Node* &a, Node* &b) {
        return a->data > b->data; // comparison based on the value of 'data'
    }
};

class Solution {
public:
    // Function to find the smallest range that includes at least one element from each row of 'KSortedArray'
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k) {
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, compare > minHeap; // minHeap to track the smallest element

        // Initialize the minHeap with the first element of each row
        for (int i = 0; i < k; i++) {
            int element = KSortedArray[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new Node(element, i, 0)); // push the element into the minHeap
        }

        int start = mini, end = maxi; // current start and end of the range
        pair<int, int> ans(start, end); // initialize the answer with the current range

        // Main loop to find the smallest range
        while (!minHeap.empty()) {
            Node* temp = minHeap.top(); // get the smallest element from the minHeap
            minHeap.pop(); // remove the smallest element from the minHeap

            mini = temp->data; // update 'mini' with the value of the current element

            // Update the start and end of the range if the current range is smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
                ans = make_pair(start, end); // update the answer with the current range
            }

            // If the current row has more elements, add the next element to the minHeap
            if (temp->col + 1 < n) {
                maxi = max(maxi, KSortedArray[temp->row][temp->col + 1]); // update 'maxi'
                minHeap.push(new Node(KSortedArray[temp->row][temp->col + 1], temp->row, temp->col + 1)); // push the next element into the minHeap
            }
            else {
                break; // if the current row is exhausted, exit the loop
            }
        }

        return ans; // return the smallest range
    }
};

/*Time Complexity: O(n⋅logk), where n is the total number of elements in 'KSortedArray' and k is the number of rows. This complexity arises due to the priority queue operations.

Space Complexity: O(k) for the priority queue 'minHeap' and O(1)
O(1) for other variables. The space complexity is dominated by the priority queue.*/