//347. Top K Frequent Elements

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