//1814. Count Nice Pairs in an Array

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
private: 
    // Function to reverse an integer
    int rev(int num) {
        int ans = 0;

        // Reversing the digits of the number
        while (num > 0) {
            int remainder = num % 10;
            ans = (ans * 10) + remainder;

            num = num / 10;
        }

        return ans;
    }    

public:
    // Constant for modulo operation
    int MOD = 1e9 + 7;

    // Function to count nice pairs in a vector of integers
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        
        // Hash map to store the count of occurrences of computed values
        unordered_map<int, int> mp; // key : nums[i] - rev(nums[i]) , value : count of key element

        // Calculating nums[i] - rev(nums[i]) for each element in the vector
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }

        int count = 0;

        // Counting nice pairs using a hash map
        for (int i = 0; i < n; i++) {
            count = (count + mp[nums[i]]) % MOD;

            // Incrementing the count for the computed value
            mp[nums[i]]++;
        }

        // Returning the final count of nice pairs
        return count;
    }
};

/*
    Time Complexity:
    - The rev function has a time complexity of O(log10(num)), where num is the input integer.
    - The countNicePairs function has a time complexity of O(n), where n is the size of the input vector.

    Space Complexity:
    - The countNicePairs function uses an unordered_map, which has a space complexity of O(n) in the worst case, 
    where n is the size of the input vector.
*/


