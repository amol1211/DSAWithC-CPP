/*Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples 
(i, j, k, l) such that:
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 
Example 1:
Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

Example 2:
Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
 
Constraints:

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <hashmap>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(); // Get the size of the vectors
        int count = 0; // Initialize a variable called count to 0
        
        // Sort the arrays nums1 and nums2
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // Traverse nums3 and nums4 using two pointers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int target = -nums3[i] - nums4[j]; // Calculate the target sum
                int left = 0, right = n - 1; // Initialize two pointers, left and right
                
                // Use the two pointers to find all pairs of elements from nums1 and nums2 that sum up to the target
                while (left < n && right >= 0) {
                    int sum = nums1[left] + nums2[right]; // Calculate the current sum
                    if (sum < target) {
                        left++; // Move the left pointer to the right
                    } else if (sum > target) {
                        right--; // Move the right pointer to the left
                    } else {
                        // If the sum is equal to the target, count the number of occurrences of each element in nums1 and nums2
                        int leftCount = 1, rightCount = 1;
                        while (left + 1 < n && nums1[left] == nums1[left+1]) {
                            leftCount++; // Count the number of occurrences of the left element
                            left++; // Move the left pointer to the right
                        }
                        while (right - 1 >= 0 && nums2[right] == nums2[right-1]) {
                            rightCount++; // Count the number of occurrences of the right element
                            right--; // Move the right pointer to the left
                        }
                        count += leftCount * rightCount; // Add the number of pairs to the count
                        left++; // Move the left pointer to the right
                        right--; // Move the right pointer to the left
                    }
                }
            }
        }
        return count; // Return the total count
    }
};
/*--------------------------------------------------------------------------------------------------*/
class Solution {
public:
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int count=0;
        unordered_map<int,int> mp;
        
        /* Philosophy
        
        1. I know that Addtion have two parts in it  EG (a +b , Part 1 - a, Part 2- b.
        2.So, Lets make and find this dependency factors. How can I do it?
        
        3. If there are 4 Sum. it means 2 sums is going to Part 1 and another 2 gonna be Part 2 which are 
        dependent on Part 1 for 0 resultant.
        
        4. I gonna store summation 2 nums1 in a FREQUENCY Hashmap.
        
        5. Then I traverse 2nd part of the summation (rest to nums) and keep checking that do (0-it1-it2) is exist in map . 
       
        6. If yes, the add the frequency of Part1 int COUNT var.
        
        7. return count;
        */
        
        //Traversing Part 1
        for (auto &it1: nums1)
            for (auto &it2:nums2)
                mp[it1+it2]++; 
        
        // Traversing Part 2
        for(auto &it3: nums3)
            for(auto &it4:nums4)
               if(mp.count(0-it3-it4)) count+=mp[0-it3-it4];
        
        return count;
    }
};
/*********************************************************************/
class Solution {
public:
    int fourSumCount(vector<int>& p, vector<int>& q, vector<int>& r, vector<int>& s) {
        unordered_map<int, int> hash;
        int n = p.size();
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                // Increment the hashtable at the sum of the pair
                hash[p[i] + q[j]]++;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                // Check if the negative of curr sum of the pair exists in the hash table. Then they will add upto zero. 
                // i.e hash[p[w] + q[x]] + hash[r[y] + s[z]] == 0.
                // But we dont want zero. We want no. of two touples. Hence we store the value in hashtable 
                //in ans. If it is present in hashtable it will get stored in ans, else it will get neglected 
                //cosidering it as a zero.
                ans = ans + hash[-(r[i] + s[j])];
            }
        }
        
        return ans;
        
    }
};
