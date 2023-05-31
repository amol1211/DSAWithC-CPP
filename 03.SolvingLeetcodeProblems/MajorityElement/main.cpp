//169. Majority Element

#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int majority = nums[0]; // Assume the first element as the majority element

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                // If the count becomes zero, update the majority element
                majority = nums[i];
            }
            
            if (nums[i] == majority) {
                // If the current element is the same as the majority element, increment the count
                count++;
            } else {
                // If the current element is different from the majority element, decrement the count
                count--;
            }
        }
        
        return majority;
    }
};
