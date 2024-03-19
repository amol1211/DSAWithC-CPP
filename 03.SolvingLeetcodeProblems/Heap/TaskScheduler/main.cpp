//621. Task Scheduler

#include <bits/stdc++.h>
using namespace std;

//Priority queue/ max heap approach

// This class represents a solution to find the least interval required to execute a given list of tasks.
class Solution {
public:
    // Function to calculate the least interval required.
    int leastInterval(vector<char>& tasks, int n) {
        // Initialize a vector to store the frequency of each task.
        vector<int> mp(26, 0);

        // Count the frequency of each task.
        for (char &ch : tasks) {
            mp[ch - 'A']++;
        }

        // Variable to store the total time.
        int time = 0;

        // Priority queue to store the frequency of tasks in descending order.
        priority_queue<int> pq;

        // Fill the priority queue with the frequencies of tasks.
        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0) {
                pq.push(mp[i]);
            }
        }

        // Continue until the priority queue is empty.
        while(!pq.empty()) {
            // Temporary vector to store frequencies after executing 'n + 1' tasks.
            vector<int> temp;

            // Execute 'n + 1' tasks.
            for (int i = 1; i <= n + 1; i++) {
                // If the priority queue is not empty, execute the task.
                if (!pq.empty()) {
                    int freq = pq.top(); // Get the frequency of the top task.
                    pq.pop(); // Remove the task from the priority queue.
                    freq--; // Decrease the frequency as the task is executed.
                    temp.push_back(freq); // Store the updated frequency.
                }
            }

            // Restore the tasks with updated frequencies to the priority queue.
            for (int &f : temp) {
                if (f > 0) {
                    pq.push(f);
                }
            }

            // If the priority queue is empty, add the number of executed tasks to the total time.
            if (pq.empty()) {
                time += temp.size();
            }
            // If the priority queue is not empty, add 'n + 1' to the total time (including idle time).
            else {
                time += n + 1;
            }
        }

        // Return the total time required.
        return time;
    }
};

/*Time Complexity: O(N), where N is the number of tasks. In the worst case, all tasks need to be executed once.

Space Complexity: O(1) since the space used is independent of the input size, as the size of the priority 
queue and temporary vector is bounded by a constant (26 for the alphabet).*/