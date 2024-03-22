//1353. Maximum Number of Events That Can Be Attended

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxEvents(vector<vector<int>>& events) {
        // Sorting events based on their start time
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        int day = 0; // Current day
        int index = 0; // Index for iterating through events
        int n = events.size(); // Total number of events
        int result = 0; // Count of attended events

        // Priority queue to store end times of events
        priority_queue<int, vector<int>, greater<int>> pq;

        // Loop until there are events in the priority queue or there are unattended events
        while (!pq.empty() || index < n) {
            // If the priority queue is empty, set the current day to the start time of the next event
            if (pq.empty()) {
                day = events[index][0];
            }

            // Add events that start on or before the current day to the priority queue
            while (index < n && events[index][0] <= day) {
                pq.push(events[index][1]); // Push end time of event to priority queue
                index++; // Move to the next event
            }

            pq.pop(); // Attend the event with the earliest end time
            day++; // Move to the next day
            result++; // Increment the count of attended events

            // Remove events that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return result; // Return the count of attended events
    }
};


/*Time Complexity:

Sorting the events takes O(n log n) time, where n is the number of events.
The while loop iterates through the events and performs operations on the priority queue. 
In the worst case, each event may be pushed and popped from the priority queue once, 
resulting in O(n log n) operations.
Overall time complexity: O(n log n)
Space Complexity:

Additional space is used for the priority queue to store end times of events, 
which can hold at most n elements, where n is the number of events.
Additional variables day, index, n, and result require constant space.
Overall space complexity: O(n)*/

//DRY RUN:
/*events = [[1,2],[2,3],[3,4],[1,2]].

Initialization:

events: [[1,2],[2,3],[3,4],[1,2]]
day: 0
index: 0
n (total number of events): 4
result (count of attended events): 0
pq (priority queue to store end times of events): Empty
Sorting events based on start time:

After sorting, events becomes: [[1,2],[1,2],[2,3],[3,4]]
Main Loop:

Iteration 1:
pq is empty, so set day = 1 (start time of the first event).
Add events starting on or before day to the priority queue.
Add event [1,2] to pq.
Increment index to 1.
Attend the event with the earliest end time from pq.
Attend event [1,2].
Increment day to 2.
Increment result to 1.
Remove events that have already ended from pq.
No events in pq have ended.
Iteration 2:
pq is not empty.
Add events starting on or before day to the priority queue.
Add event [1,2] to pq.
Increment index to 2.
Attend the event with the earliest end time from pq.
Attend event [1,2].
Increment day to 3.
Increment result to 2.
Remove events that have already ended from pq.
No events in pq have ended.
Iteration 3:
pq is not empty.
Add events starting on or before day to the priority queue.
Add event [2,3] to pq.
Increment index to 3.
Attend the event with the earliest end time from pq.
Attend event [2,3].
Increment day to 4.
Increment result to 3.
Remove events that have already ended from pq.
No events in pq have ended.
Iteration 4:
pq is not empty.
Add events starting on or before day to the priority queue.
Add event [3,4] to pq.
Increment index to 4.
Attend the event with the earliest end time from pq.
Attend event [3,4].
Increment day to 5.
Increment result to 4.
Remove events that have already ended from pq.
No events in pq have ended.
End of Iterations.
Return Result:

Return result which is 4.
So, the maximum number of events that can be attended is 4.*/