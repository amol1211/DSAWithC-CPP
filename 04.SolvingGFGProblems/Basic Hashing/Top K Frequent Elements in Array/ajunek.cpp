#include <iostream>
using namespace std;

class Solution {
    public:
    vector<int> topK(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        vector<int> res;
        while(k-- > 0 && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};