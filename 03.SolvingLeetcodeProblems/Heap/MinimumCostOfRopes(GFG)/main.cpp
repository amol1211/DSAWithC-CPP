//Minimum Cost of ropes (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to return the minimum cost of connecting the ropes.
    
    long long minCost(long long arr[], long long n) {
        // Creating a min-heap
        
        // Declaring a priority queue with elements in increasing order.
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // Pushing all elements of the array into the priority queue.
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        
        // Initializing cost to store the total cost of connecting the ropes.
        long long cost = 0;
        
        // Loop until only one rope is left in the priority queue.
        while (pq.size() > 1) {
            // Extracting the two smallest ropes from the priority queue.
            long long a = pq.top(); // Extracting the smallest rope.
            pq.pop();
            
            long long b = pq.top(); // Extracting the second smallest rope.
            pq.pop();
            
            // Calculating the cost of connecting these two ropes.
            long long sum = a + b;
            
            // Adding the cost of connecting these two ropes to the total cost.
            cost += sum;
            
            // Pushing the newly formed rope back into the priority queue.
            pq.push(sum);
        }
        
        // Returning the total cost of connecting all ropes.
        return cost;
    }
};

// Time Complexity: O(n*log(n)) - Where 'n' is the number of ropes in the array.
// The time complexity is dominated by the construction of the priority queue.
// Space Complexity: O(n) - We are using a priority queue to store the ropes, which can take up to 'n' elements.