//2542. Maximum Subsequence Score

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Using recursion (TLE)

class Solution {
public:
    int K; // K denotes the value of 'k' passed to the function
    int n; // n denotes the size of nums1 vector
    priority_queue<int, vector<int>, greater<int>> pq; // Min heap to keep track of current k smallest elements

    // Function to remove a specific number from the priority queue
    void removeFromPq(int num) {
        
        vector<int> temp; // Temporary vector to store elements temporarily

        while (!pq.empty()) {
            int x = pq.top(); // Get the top element
            pq.pop(); // Pop the top element

            if (x == num) { // If the top element matches the number to be removed, break the loop
                break;
            }

            temp.push_back(x); // Otherwise, add it to the temporary vector
        }

        for (int &x : temp) { // Re-add all elements from temporary vector back to the priority queue
            pq.push(x);
        }
    }

    // Recursive function to calculate the maximum score
    int solve(vector<int>& nums1, vector<int>& nums2, int sum, int min, int i, int count) {

        if (count == K) return sum * min; // If we've considered 'k' elements, return the product of sum and minimum element seen

        if (i >= n) return 0; // If we've reached the end of nums1, return 0

        pq.push(nums2[i]); // Add current nums2 element to priority queue

        // Recursive call considering current nums1 element
        int take_i = solve(nums1, nums2, sum + nums1[i], pq.top(), i + 1, count + 1);

        removeFromPq(nums2[i]); // Remove current nums2 element from priority queue

        // Recursive call without considering current nums1 element
        int not_take_i = solve(nums1, nums2, sum, min, i + 1, count);

        return max(take_i, not_take_i); // Return the maximum of the two recursive calls
    }

    // Function to calculate maximum score
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        K = k; // Assign value of 'k' to member variable K
        n = nums1.size(); // Assign size of nums1 to member variable n

        // Call the recursive function with initial values
        return solve(nums1, nums2, 0/*sum*/, 0/*min*/, 0/* current index */, 0/* count */);
    }
};

/*Time Complexity: The time complexity of this approach is O(2^N), where N is the size of nums1. 
This is because for each element in nums1, we have two choices: either include it or exclude it.

Space Complexity: The space complexity is O(K), where K is the value of 'k' passed to the function. 
This is because of the priority queue used to keep track of the smallest elements.*/

/*-------------------------------------------------------------------------------------------------------------*/

//Appraoch 2 : Using priority queue (minHeap)

class Solution {
public:
    // Function to calculate the maximum score
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(); // Get the size of input arrays

        vector<pair<int, int>> vec(n); // Create a vector of pairs to store nums1 and nums2 elements together

        // Fill the vector with nums1 and nums2 elements paired up
        for (int i = 0; i < n; i++) {
            vec[i] = {nums1[i], nums2[i]};
        }

        // Lambda function to define custom comparison for sorting pairs based on second element (nums2)
        auto lambda = [&](auto &P1, auto &P2) {
            return P1.second > P2.second; // Sort in descending order of second elements
        };

        sort(vec.begin(), vec.end(), lambda); // Sort the vector based on custom comparison

        priority_queue<int, vector<int>, greater<int>> pq; // Min heap to keep track of k smallest elements from nums1

        long long kSum = 0; // Variable to keep track of sum of k smallest elements from nums1

        // Calculate sum of k smallest elements from nums1 and populate min heap
        for (int i = 0; i <= k - 1; i++) {
            kSum += vec[i].first;
            pq.push(vec[i].first);
        }

        long long result = kSum * vec[k - 1].second; // Initialize result with the score obtained from k smallest elements

        // Iterate through remaining elements and update result if necessary
        for (int i = k; i < n; i++) {
            kSum += vec[i].first - pq.top(); // Update sum by removing the smallest element and adding the current element
            pq.pop(); // Remove smallest element from min heap
            pq.push(vec[i].first); // Add current element to min heap
            result = max(result, kSum * vec[i].second); // Update result if necessary
        }

        return result; // Return the final result
    }
};

/*Time Complexity: The time complexity of this approach is O(N log N), where N is the size of nums1. 
This is because of the sorting step performed on the vector of pairs. The subsequent iteration through 
the elements has a complexity of O(N).

Space Complexity: The space complexity is O(N) due to the vector of pairs created to store nums1 and 
nums2 elements together, and also due to the priority queue used to keep track of the k smallest 
elements from nums1.*/
