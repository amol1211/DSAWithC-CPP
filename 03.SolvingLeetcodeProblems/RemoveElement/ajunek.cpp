#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[j++]=nums[i];
            }
        }
        return j;        
    }
};

/*----------------------------------------------------------------------------------*/

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int length = nums.size(), index = 0;
		while ( index < length )
		{
			 if ( nums[index] == val )
			 {
				 nums[index] = nums[length - 1];
				 -- length;
			 }
				
			else ++index;
		}
		 return length;  
	}
};
