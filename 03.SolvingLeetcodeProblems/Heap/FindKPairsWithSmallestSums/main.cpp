//373. Find K Pairs with Smallest Sums

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : Brute Force with Priority Queue

class Solution {
public:
    // Define a pair type P with an integer sum and a pair of integers representing indices from nums1 and nums2.
    typedef pair<int, pair<int, int>> P;

    // Function to find the k smallest pairs using a priority queue.
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Priority queue to store pairs with the smallest sum, sorted by the sum.
        priority_queue<P, vector<P>> pq;

        // Get the sizes of the input arrays nums1 and nums2.
        int n = nums1.size();
        int m = nums2.size();

        // Iterate through all pairs from nums1 and nums2.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Calculate the sum of current pair.
                int sum = nums1[i] + nums2[j];

                // If the priority queue size is less than k, push the current pair.
                if (pq.size() < k) {
                    pq.push({sum, {i, j}});
                }
                // If the sum of the current pair is less than the maximum sum in the priority queue, replace it.
                else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                }
                // If the sum is not less than the maximum sum, break the loop.
                else {
                    break;
                }
            }
        }

        // Store the k smallest pairs in the answer vector.
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            ans.push_back({nums1[i], nums2[j]});
        }

        // Return the answer vector.
        return ans;
    }
};

/*Time Complexity: O(n * m * log(k)), where n is the size of nums1, m is the size of nums2, and k is 
the input parameter representing the number of smallest pairs to find.

Space Complexity: O(k), where k is the size of the priority queue storing the k smallest pairs.*/

/*-----------------------------------------------------------------------------------------------------------------------*/

//Approach 2 : Optimized with Priority Queue and Visited Set

class Solution {
public:
    // Define a pair type P with an integer sum and a pair of integers representing indices from nums1 and nums2.
    typedef pair<int, pair<int, int>> P;

    // Function to find the k smallest pairs using a priority queue with a custom comparator.
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Priority queue to store pairs with the smallest sum, sorted by the sum using a custom comparator.
        priority_queue<P, vector<P>, greater<P>> pq;

        // Get the sizes of the input arrays nums1 and nums2.
        int n = nums1.size();
        int m = nums2.size();

        // Initialize the priority queue with the sum of the first pair from nums1 and nums2.
        int sum = nums1[0] + nums2[0];
        // Create a set to keep track of visited pairs.
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        pq.push({sum, {0, 0}});

        // Vector to store the resulting pairs.
        vector<vector<int>> ans;

        // Iterate until k smallest pairs are found or the priority queue becomes empty.
        while (k-- && !pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            // Add the current pair to the result.
            ans.push_back({nums1[i], nums2[j]});

            // Explore the next pairs if not visited.
            if (j + 1 < m && visited.find({i, j + 1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }

            if (i + 1 < n && visited.find({i + 1, j}) == visited.end()) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
        }

        // Return the resulting pairs.
        return ans;
    }
};

/*Time Complexity: O(k * log(k)), where k is the input parameter representing the number of smallest pairs to find.

Space Complexity: O(k), where k is the size of the priority queue storing the k smallest pairs, and also the size 
of the set keeping track of visited pairs.*/