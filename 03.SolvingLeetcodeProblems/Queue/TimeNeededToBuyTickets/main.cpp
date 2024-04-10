//2073. Time Needed to Buy Tickets

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Using queue

class Solution {
public:
    // Function to find the time required for the person at position k to finish buying their tickets.
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(); // Number of people in the queue
        queue<int> que; // Queue to simulate the line of people

        // Enqueue each person's position into the queue
        for (int i = 0; i < n; i++) {
            que.push(i);
        }

        int time = 0; // Variable to keep track of time

        // Loop until the queue is empty
        while (!que.empty()) {
            time++; // Increment time for each iteration

            int front = que.front(); // Get the position of the person at the front of the queue
            que.pop(); // Remove the person from the front of the queue
            
            tickets[front]--; // Decrement the number of tickets the person at position front wants to buy
            
            // Check if the person at position k has finished buying their tickets
            if (k == front && tickets[front] == 0) {
                return time; // Return the current time if person at position k has finished
            }

            // If the person still wants to buy more tickets, enqueue them back into the queue
            if (tickets[front] != 0) {
                que.push(front);
            }
        }

        // If the person at position k is not found, return the current time
        return time;
    }
};

/*Time Complexity:

Enqueuing all people initially takes O(n * m) time.
In each iteration of the while loop, we dequeue one person from the queue and enqueue 
them again if they still want to buy tickets. Since there are n people in the queue, 
and each person may need to be processed up to m times, the overall time complexity is O(n * m).

Space Complexity:

We use additional space for the queue, which can hold up to n elements, where n is the number 
of people in the queue. So, the space complexity is O(n).*/

/*-------------------------------------------------------------------------------------------------*/