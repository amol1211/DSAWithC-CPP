//46. Permutations
#include <iostream>
#include <vector>
using namespace std;

// 1. Recursive approach

class Solution {
private: 
    // Recursive function to generate permutations
    void solve(vector<int> nums, vector<vector<int>> &ans, int index) {
        // Base case: if the index is beyond the last element, add the current permutation to the result
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Iterate over elements from the current index to the end, swapping each with the current index
        for (int j = index; j < nums.size(); j++) {
            // Swap the elements at index and j
            swap(nums[index], nums[j]);
            
            // Recursively generate permutations for the next index
            solve(nums, ans, index + 1);
            
            // Backtrack by swapping back to the original arrangement
            swap(nums[index], nums[j]);
        }
    }    
public:
    // Main function to initiate permutation generation
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};

//Time complexity : O(N!)
//Space complexity :  The space complexity is O(N), where N is the depth of the recursion stack. 
//This is because the recursion stack grows to a maximum depth of N.

/*-------------------------------------------------------------------*/

// 2.Next permutation approach

class Solution {
public:
    // Main function to generate permutations using next_permutation
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        // Sort the input vector to use next_permutation
        sort(nums.begin(), nums.end());
        
        // Generate permutations using next_permutation and add them to the result
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};

//Time complexity : O(N!)
//Space Complexity: The space complexity is O(1) because no additional space is used other than 
//the input vector and some temporary variables inside the next_permutation function.

/*------------------------------------------------------------------------------------------------*/

// 3. Map approach

class Solution {
private:
    // Recursive function to generate permutations as strings
    void generatePermutations(map<int, bool>& used, vector<int>& current, vector<vector<int>>& ans) {
        // Base case: if the current permutation is complete, add it to the result vector
        if (current.size() == used.size()) {
            ans.push_back(current);
            return;
        }

        // Iterate over elements in the map
        for (const auto& pair : used) {
            int num = pair.first;

            // If the element is not used, add it to the current permutation and recursively generate permutations
            if (!used[num]) {
                used[num] = true;
                current.push_back(num);
                generatePermutations(used, current, ans);
                used[num] = false;  // Backtrack
                current.pop_back();
            }
        }
    }

public:
    // Main function to initiate permutation generation
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, bool> used;

        // Initialize the map with all elements as unused
        for (int num : nums) {
            used[num] = false;
        }

        // Generate permutations as vectors of ints
        vector<int> current;
        generatePermutations(used, current, ans);

        return ans;
    }
};

//Time complexity : O(N * N!)
//Space Complexity:O(N)