//2462. Total Cost to Hire K Workers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the total cost based on given parameters.
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // Get the size of the costs vector.
        int n = costs.size();

        // Priority queues to store the lowest 'candidates' costs from the beginning and end of the 'costs' array.
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        // Variable to store the total cost.
        long long ans = 0;

        // Variable to track the number of candidates hired.
        int hired = 0;

        // Pointers for iterating through the 'costs' array from the beginning and end.
        int i = 0, j = n - 1;

        // Loop until 'k' candidates are hired.
        while (hired < k) {

            // Fill priority queue 1 with 'candidates' number of costs from the beginning.
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i]);
                i++;
            }

            // Fill priority queue 2 with 'candidates' number of costs from the end.
            while (pq2.size() < candidates && j >= i) {
                pq2.push(costs[j]);
                j--;
            }

            // Get the minimum cost from each priority queue.
            int min_pq1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int min_pq2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            // Choose the minimum cost between the two priority queues and add it to the total cost.
            if (min_pq1 <= min_pq2) {
                ans += min_pq1;
                pq1.pop();
            } 
            else {
                ans += min_pq2;
                pq2.pop();
            }

            // Increment the number of candidates hired.
            hired++;
        }

        // Return the total cost.
        return ans;
    }
};

/*Time Complexity: The time complexity of this solution is O(k * log(candidates)), where 'k' is 
the number of candidates hired and 'candidates' is the number of candidates considered from each 
end of the 'costs' array.

Space Complexity: The space complexity is O(candidates), where 'candidates' is the number of candidates 
considered from each end of the 'costs' array, as we are using two priority queues each containing at 
most 'candidates' elements.*/