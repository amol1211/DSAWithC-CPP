//1752. Check if Array Is Sorted and Rotated

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()])
                count++;
        }
        return (count<=1);
    }
};