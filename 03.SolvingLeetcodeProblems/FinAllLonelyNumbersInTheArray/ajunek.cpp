#include <iostream>
using namespace std;

class Solution {
    public:
    vector<int> findLonelyNumber(vector<int>& nums) {
    unordered_map<int, int> frequencyMap;
    vector<int> lonelyNums;

    for (int num : nums) {
        frequencyMap[num]++;
    }

    for (auto& pair : frequencyMap) {
        int num = pair.first;
        int frequency = pair.second;

        if (frequency == 1 && frequencyMap.count(num - 1) == 0 && frequencyMap.count(num + 1) == 0) {
            lonelyNums.push_back(num);
        }
    }
    return lonelyNums;
}

};
