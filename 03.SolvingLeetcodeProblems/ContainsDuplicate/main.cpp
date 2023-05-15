/*Given an integer array nums, return true if any value appears at least twice in the array, and return false 
if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 
Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109 */

/*Try to code by yourself by listing Approach 🥺.
Brute Force : Idea behind code

Make nested loop , generate all possible pair
Put a condition if both of the number generate in a pair are same
In this approach only the unique pair will be formed becouse outerloop is running from 0 to n - 1, 
and inner loop will start from one value extra from previous loop value ( which make it to run n*(n+1)/2 ) . 
if we are matching each and every pair of vector , then possibly we can compare if any of them have same value 
then return true. else at end of nested form loop return false.*/
// Brute Force
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool flag = false;
        for(int i =0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] == nums[j]) return true;
            }
        }
        return flag;
    }
};
/*-----------------------------------------------------------------------------------------------------*/
/*Shorted Approach : Idea behind code
sort the array.
linearly traverse , find if there is any of the number and its greater one are equal or not*/
// Shorted Approach
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool flag = false;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) return true;
        }
        return flag;
    }
};
/*------------------------------------------------------------------------------------------------------*/
/* Set Approach : Idea behind code
Set only don't contain duplicate elment .
If the size of set if less than the original vector then it contain duplicate element.
For your set approach, time complexity can be reduced from O(nlogn) to O(n) using an unordered_set. 
Regular set uses trees with O(logn) insert, but unordered_sets use hashing for O(1). :)*/

// Set Approach
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(),nums.end()).size();
    }
};
/*---------------------------------------------------------------------------------------------------*/
/*Hashmap or Map : Idea behind code

traverse vector and count frequency using any data structure.
Iterate through data structure to find if the frequency is beyond 1.*/
// Contains Duplicate
  class Solution {
  public:
      bool containsDuplicate(vector<int>& nums) {
          map<int,int> mp;
          for(auto i : nums) mp[i]++;
          bool flag = false;
          for(auto i : mp){
              if(i.second >= 2) return true;
          }
          return flag;
      }
  };

/*-----------------------------------------------------------------------------------------------------------------*/
public boolean containsDuplicate(int[] nums) {

        for(int i = 0; i < nums.length; i++) {
            for(int j = i + 1; j < nums.length; j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
/*----------------------------------------------------------------------------------------------------------------*/
    public boolean containsDuplicate(int[] nums) {

        Arrays.sort(nums);
        for(int ind = 1; ind < nums.length; ind++) {
            if(nums[ind] == nums[ind - 1]) {
                return true;
            }
        }
        return false;
    }
/*----------------------------------------------------------------------------------------------------------------*/
public boolean containsDuplicate(int[] nums) {

    final Set<Integer> distinct = new HashSet<Integer>();
    for(int num : nums) {
        if(distinct.contains(num)) {
            return true;
        }
        distinct.add(num);
    }
    return false;
}        