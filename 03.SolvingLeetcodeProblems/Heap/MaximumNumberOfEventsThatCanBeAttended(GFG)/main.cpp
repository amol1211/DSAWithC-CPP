//Maximum number of events that can be attended (GFG)

#include <bits/stdc++.h>
using namespace std;

//Approach 1: Using a Set

class Solution {
public:
    int maxEvents(int start[], int end[], int N) {
        unordered_set<int> s; // Set to store attended days
        vector<pair<int,int>> v; // Vector to store events as pairs (start, end)

        // Storing events in vector of pairs
        for(int i = 0; i < N; i++)
            v.push_back({start[i],end[i]});

        // Sorting events based on their start times
        sort(v.begin(),v.end());

        // Iterating through sorted events in reverse order
        for(int i = N-1; i >= 0; i--) { 
            // If the end day of the event is not attended, insert it into the set
            if(s.find(v[i].second) == s.end())
                s.insert(v[i].second);
            // If the end day is already attended, find the earliest available day and attend the event
            else {
                int e = v[i].second;
                while(e >= v[i].first) {
                    if(s.find(e) == s.end()) {
                        s.insert(e);
                        break;
                    }
                    e--;
                }
            }
        }
        
        return s.size(); // Return the size of the set, which represents the count of attended days
    }
};

/*-------------------------------------------------------------*/

//Approach 2: same approach but li'l verbose - Using Set and Checking Earliest Available Day

class Solution {
public:
    int maxEvents(int start[], int end[], int N) {
        unordered_set<int> attendedDays; // Set to store attended days
        vector<pair<int, int>> events; // Vector to store events as pairs (start, end)

        // Storing events in vector of pairs
        for (int i = 0; i < N; i++) {
            events.push_back({start[i], end[i]});
        }

        // Sorting events based on their start times
        sort(events.begin(), events.end());

        // Iterating through sorted events in reverse order
        for (int i = N - 1; i >= 0; i--) {
            int eventStart = events[i].first;
            int eventEnd = events[i].second;
            
            // If the end day of the event is not attended, insert it into the set
            if (attendedDays.find(eventEnd) == attendedDays.end()) {
                attendedDays.insert(eventEnd);
            }
            // If the end day is already attended, find the earliest available day and attend the event
            else {
                int earliestAvailableDay = eventEnd;
                while (earliestAvailableDay >= eventStart) {
                    if (attendedDays.find(earliestAvailableDay) == attendedDays.end()) {
                        attendedDays.insert(earliestAvailableDay);
                        break;
                    }
                    --earliestAvailableDay;
                }
            }
        }
        
        return attendedDays.size(); // Return the size of the set, which represents the count of attended days
    }
};

/*/*Time Complexity:

Constructing the unordered_set and iterating over the events takes O(N) time.
Sorting the events takes O(N log N) time.
Iterating over the sorted events and manipulating the set takes O(N) time.
Overall time complexity: O(N log N)
Space Complexity:

Additional space is used for the unordered_set and vector of pairs.
Overall space complexity: O(N)*/*/