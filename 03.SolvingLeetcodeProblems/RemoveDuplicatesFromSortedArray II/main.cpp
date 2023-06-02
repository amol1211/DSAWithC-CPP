#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> freq;
        int count = 0;

        for (auto i : nums) {
            freq[i]++;
            if (freq[i] <= 2) {
               nums[count++] = i;
            }
        }
        return count;
    }
};