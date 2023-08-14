//347. Top K Frequent Elements

//Approach 1: priority queue approach" or "heap approach"
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        for ( auto i : nums) {
            freq[i]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto it: freq) {
            pq.push({it.second, it.first});
        }

        vector<int> result;
        while (k-- > 0 && !pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

// Time complexity : O(n log n).
// Space complexity : O(n).

/*------------------------------------------------------------------------------------------*/

//Approach 2: combination of a hash map and a bucket sort.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Calculate frequency of each element using a hash map
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets and place elements in their corresponding frequency buckets
        vector<vector<int>> buckets(nums.size() + 1); // Create buckets
        for (auto& pair : freq) {
            buckets[pair.second].push_back(pair.first);
        }

        // Step 3: Extract top k frequent elements from the buckets
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && k > 0; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                k--;
                if (k == 0) break;
            }
        }
        
        return result;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)