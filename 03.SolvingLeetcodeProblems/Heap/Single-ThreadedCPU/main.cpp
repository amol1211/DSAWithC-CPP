//1834. Single-Threaded CPU

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reorder the tasks based on their start times and processing times
    // Time Complexity: O(nlogn) where n is the number of tasks
    // Space Complexity: O(n) where n is the number of tasks
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(); // Get the number of tasks

        // Create a vector to store tasks along with their start times, processing times, and original indices
        vector<array<int, 3>> sortedTasks;

        // Iterate through each task
        for (int i = 0; i < n; i++) {
            int startTime = tasks[i][0]; // Extract the start time of the task
            int processingTime = tasks[i][1]; // Extract the processing time of the task
            
            // Store the task's start time, processing time, and original index in the sortedTasks vector
            sortedTasks.push_back({startTime, processingTime, i});
        }

        // Sort the tasks based on their start times
        sort(sortedTasks.begin(), sortedTasks.end());

        // Create a vector to store the order of execution of tasks
        vector<int> result;

        // Initialize the current time to 0 and the index to 0
        long long currentTime = 0;
        int index = 0;

        // Create a min-heap (priority queue) to store tasks based on their processing times
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;

        // Iterate until all tasks are processed or the priority queue is empty
        while (index < n || !pq.empty()) {

            // If the priority queue is empty and there are pending tasks, update the current time
            if (pq.empty() && currentTime < sortedTasks[index][0]) {
                currentTime = sortedTasks[index][0];
            }

            // Add tasks with start times less than or equal to the current time to the priority queue
            while (index < n && sortedTasks[index][0] <= currentTime) {
                pq.push({sortedTasks[index][1], sortedTasks[index][2]});
                index++;
            }

            // Get the task with the smallest processing time from the priority queue
            pair<int, int> currentTask = pq.top();
            pq.pop();

            // Update the current time by adding the processing time of the current task
            currentTime += currentTask.first;

            // Store the index of the current task in the result vector
            result.push_back(currentTask.second);
        }

        // Return the order of execution of tasks
        return result;
    }
};

/*Time Complexity:

Sorting the tasks based on their start times takes O(n log n) time, where n is the number of tasks.
The while loop iterates over each task once, and each task is pushed and popped from the priority queue at most once. Therefore, the time complexity for the while loop is O(n log n).
Overall, the time complexity is dominated by the sorting step, so the total time complexity is O(n log n).
Space Complexity:

The additional space used by the algorithm includes:
O(n) space for storing the sorted tasks along with their start times, processing times, and original indices.
O(n) space for the priority queue, as it may contain at most n elements.
O(n) space for the result vector.
Therefore, the total space complexity is O(n).*/