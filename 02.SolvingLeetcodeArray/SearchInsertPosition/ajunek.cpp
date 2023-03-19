#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
/*---------------------------------------------------------------------------------------------*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first=0, last=nums.size(), mid;
        while (first<last) {
            mid=first+((last-first)/2); 
            	
			if (nums[mid]<target) 
				first=mid+1;
			else 
				last=mid;
        }
        return first;
    }
};
