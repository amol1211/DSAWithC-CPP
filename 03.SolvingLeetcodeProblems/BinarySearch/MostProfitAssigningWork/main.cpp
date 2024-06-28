//826. Most Profit Assigning Work

#include <bits/stdc++.h>
using namespace std;

//Approach 1: Max-Heap and Descending Sort

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        // Step 1: Create a max-heap to store pairs of profit and difficulty
        priority_queue<pair<int, int>> pq; // Max heap of pair {profit, difficulty}

        // Step 2: Push all {profit, difficulty} pairs into the max-heap
        for (int i = 0; i < n; i++) {
            int diff = difficulty[i];
            int prof = profit[i];
            pq.push({prof, diff});
        }

        // Step 3: Sort the workers in descending order of their ability
        sort(worker.begin(), worker.end(), greater<int>());

        int i = 0;
        int totalProfit = 0;

        // Step 4: Assign the best possible jobs to each worker
        while (i < m && !pq.empty()) {
            if (pq.top().second > worker[i]) {
                pq.pop(); // Remove jobs that are too difficult for the current worker
            } else {
                totalProfit += pq.top().first; // Add the profit of the job to total profit
                i++; // Move to the next worker
            }
        }

        return totalProfit;
    }
};

/*Time Complexity: O(n log n + m log m)
Space Complexity: O(n)
Explanation: Sorting the worker array takes O(m log m), and creating and managing the heap takes O(n log n).*/

/*------------------------------------------------*/

//Approach 2: Binary Search After Preprocessing

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        // Step 1: Create a vector of pairs to store difficulty and profit
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        // Step 2: Sort the vector based on difficulty
        sort(vec.begin(), vec.end());

        // Step 3: Preprocess to find the maximum profit up to each index
        for (int i = 1; i < vec.size(); i++) {
            vec[i].second = max(vec[i].second, vec[i - 1].second);
        }

        int totalProfit = 0;
        for (int i = 0; i < m; i++) {
            int workerDiffLevel = worker[i];

            // Step 4: Binary search to find the best job the worker can do
            int l = 0, r = vec.size() - 1;
            int maxProfit = 0;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (vec[mid].first <= workerDiffLevel) {
                    maxProfit = max(maxProfit, vec[mid].second);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};

/*
Certainly! Here are the three approaches with clear comments, names, and time and space complexity analysis:

Approach 1: Max-Heap and Descending Sort
cpp
Copy code
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        // Step 1: Create a max-heap to store pairs of profit and difficulty
        priority_queue<pair<int, int>> pq; // Max heap of pair {profit, difficulty}

        // Step 2: Push all {profit, difficulty} pairs into the max-heap
        for (int i = 0; i < n; i++) {
            int diff = difficulty[i];
            int prof = profit[i];
            pq.push({prof, diff});
        }

        // Step 3: Sort the workers in descending order of their ability
        sort(worker.begin(), worker.end(), greater<int>());

        int i = 0;
        int totalProfit = 0;

        // Step 4: Assign the best possible jobs to each worker
        while (i < m && !pq.empty()) {
            if (pq.top().second > worker[i]) {
                pq.pop(); // Remove jobs that are too difficult for the current worker
            } else {
                totalProfit += pq.top().first; // Add the profit of the job to total profit
                i++; // Move to the next worker
            }
        }

        return totalProfit;
    }
};
Time Complexity: O(n log n + m log m)
Space Complexity: O(n)
Explanation: Sorting the worker array takes O(m log m), and creating and managing the heap takes O(n log n).

Approach 2: Binary Search After Preprocessing
cpp
Copy code
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        // Step 1: Create a vector of pairs to store difficulty and profit
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        // Step 2: Sort the vector based on difficulty
        sort(vec.begin(), vec.end());

        // Step 3: Preprocess to find the maximum profit up to each index
        for (int i = 1; i < vec.size(); i++) {
            vec[i].second = max(vec[i].second, vec[i - 1].second);
        }

        int totalProfit = 0;
        for (int i = 0; i < m; i++) {
            int workerDiffLevel = worker[i];

            // Step 4: Binary search to find the best job the worker can do
            int l = 0, r = vec.size() - 1;
            int maxProfit = 0;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (vec[mid].first <= workerDiffLevel) {
                    maxProfit = max(maxProfit, vec[mid].second);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};
Time Complexity: O(n log n + m log n)
Space Complexity: O(n)
Explanation: Sorting the jobs takes O(n log n), and each worker performs a binary search on the sorted jobs, which is O(m log n).*/

/*------------------------------------------------------*/

//Approach 3: Two-Pointer Technique After Sorting

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        // Step 1: Create a vector of pairs to store difficulty and profit
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        // Step 2: Sort the vector based on difficulty
        sort(vec.begin(), vec.end());

        // Step 3: Sort the workers based on their ability
        sort(worker.begin(), worker.end());

        int totalProfit = 0;
        int j = 0; // Pointer for jobs
        int maxProfit = 0;

        // Step 4: Assign the best possible jobs to each worker using two pointers
        for (int i = 0; i < m; i++) {
            while (j < n && worker[i] >= vec[j].first) {
                maxProfit = max(maxProfit, vec[j].second); // Update max profit seen so far
                j++;
            }
            totalProfit += maxProfit; // Add the best possible profit for the current worker
        }

        return totalProfit;
    }
};

/*Time Complexity: O(n log n + m log m)
Space Complexity: O(n)
Explanation: Sorting both the jobs and the workers takes O(n log n) and O(m log m) respectively. The two-pointer traversal is O(n + m).*/
