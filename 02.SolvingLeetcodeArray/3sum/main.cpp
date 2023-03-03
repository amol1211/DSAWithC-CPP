/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, 
and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105*/
// Two pointer approach
#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 
vector<vector<int>> threeSum(vector<int> &num) {
    
    vector<vector<int>> ans;

    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int left = i + 1;
        int right = num.size() - 1;

        while (left < right) {

            int sum = num[left] + num[right];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                left++;

            else if (sum > target)
                right--;

            else {
                vector<int> triplet = {num[i], num[left], num[right]};
                ans.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (left < right && num[right] == triplet[1]) left++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (left < right && num[right] == triplet[2]) right--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return ans;
    
}
};

// Same approach but 
/*I had made it more faster by adding this piece of code to pruning your algorithm.

        if(target < 0)
        {
            break;
        }
^_^*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > threeSum(vector<int> &num) {

    vector<vector<int> > ans;

    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {

        int target = -num[i];
        int left = i + 1;
        int right = num.size() - 1;
        
        if(target < 0)
        {
            break;
        }

        while (left < right) {

            int sum = num[left] + num[right];

            // Finding answer which start from number num[i]
            if (sum < target)
                left++;

            else if (sum > target)
                right--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[left];
                triplet[2] = num[right];
                ans.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (left < right && num[left] == triplet[1]) left++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (left < right && num[right] == triplet[2]) right--;
            }

        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }

    return ans;

}
