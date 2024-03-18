//Maximum Sum Combination (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Priority queue/min heap to store K smallest sums in ascending order
        priority_queue<int, vector<int>, greater<int>> pq;
        // Vector to store the final result
        vector<int> ans;

        // Sorting arrays A and B in ascending order
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        // Loop over each element in array A
        for (int i = N - 1; i >= 0; i--) {
            // Loop over each element in array B
            for (int j = N - 1; j >= 0; j--) {
                // Calculate the sum of elements A[i] and B[j]
                int sum = A[i] + B[j];
                // If priority queue is not full, push the sum
                if (pq.size() < K)
                    pq.push(sum);
                // If the current sum is greater than the top of priority queue,
                // replace the top with the current sum
                else if (pq.top() < sum) {
                    pq.pop();
                    pq.push(sum);
                } else
                    // Break if the current sum is not greater than the top
                    break;
            }
        }

        // Extracting K smallest sums from the priority queue and storing them in the result vector
        while (!pq.empty()) {
            ans.insert(ans.begin(), pq.top());
            pq.pop();
        }

        // Return the result vector containing K smallest sums
        return ans;
    }
};

/*Given that the inner loop iterates at most K times (if the condition for the break statement is met), and each iteration involves operations with the priority queue, which have a time complexity of O(log(K)), we can express the time complexity of the inner loop as O(K * log(K)).

The outer loop also iterates N times, but the number of iterations in the inner loop is dependent on the break statement. However, to simplify the analysis, we can consider the worst-case scenario where the break statement is not triggered and the inner loop iterates K times for each iteration of the outer loop. Therefore, the time complexity of the outer loop becomes O(N * K * log(K)).

dominant space complexity of the provided code is O(K), as both the priority queue and the result vector have a maximum size bounded by K.

So, the space complexity of the provided code is O(K).*/

