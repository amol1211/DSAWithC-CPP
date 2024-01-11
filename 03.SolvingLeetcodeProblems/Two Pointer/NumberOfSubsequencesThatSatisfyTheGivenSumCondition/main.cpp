//1498. Number of Subsequences That Satisfy the Given Sum Condition

//Two pointers approach

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to calculate the number of valid subsequences
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Sorting the array to simplify the subsequences calculation
        sort(nums.begin(), nums.end());

        // Initializing an array to store powers of 2 modulo MOD
        vector<int> power(n);
        power[0] = 1;

        // Calculating powers of 2 modulo MOD
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        // Initializing result variable to store the number of valid subsequences
        int result = 0;

        // Two pointers approach to find valid subsequences
        int l = 0, r = n - 1;

        // Iterating through the sorted array
        for (auto &i : nums) {
            // If the sum of elements at pointers is less than or equal to the target
            if (nums[l] + nums[r] <= target) {
                // Calculate the number of valid subsequences using the power array
                int difference = r - l;
                result = (result % MOD + power[difference] % MOD);
                l++; // Move left pointer to the right
            } else {
                r--; // Move right pointer to the left
            }
        } 

        return result; // Return the total number of valid subsequences
    }
};

/*Time Complexity:

The sorting of the array takes O(n log n) time.
The two pointers approach iterates through the array once, taking O(n) time.
The power array calculation also takes O(n) time.
Hence, the overall time complexity is O(n log n).

Space Complexity:

The space complexity is O(n) due to the additional storage used for the power array.
The rest of the variables use constant space.
Therefore, the overall space complexity is O(n).*/