//1011. Capacity To Ship Packages Within D Days

#include <bits/stdc++.h>
using namespace std;

class Solution {  // Define the Solution class
private:
    // Helper function to determine the number of days required to ship with given capacity
    int daysRequired(vector<int> &weights, int capacity) {
        int days = 1, load = 0;  // Initialize days to 1 and load to 0

        for (int i = 0; i < weights.size(); i++) {  // Iterate through each weight
            if (weights[i] + load > capacity) {  // If adding this weight exceeds the capacity
                days += 1;  // Increment the number of days
                load = weights[i];  // Start a new load with the current weight
            }
            else {
                load += weights[i];  // Otherwise, add the weight to the current load
            }
        }

        return days;  // Return the total number of days required
    }

public:
    // Function to determine the minimum capacity needed to ship within given days
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());  // Minimum capacity is the max weight
        int high = accumulate(weights.begin(), weights.end(), 0);  // Maximum capacity is the sum of all weights

        while (low <= high) {  // Perform binary search
            int mid = low + (high - low)/2;  // Calculate the mid value of the current range

            int numOfDays = daysRequired(weights, mid);  // Determine the number of days needed for mid capacity
            if (numOfDays <= days) {  // If the number of days is within the allowed days
                high = mid - 1;  // Decrease the upper bound
            }
            else {
                low = mid + 1;  // Otherwise, increase the lower bound
            }
        }

        return low;  // Return the minimum capacity required
    }
};

/*### Time Complexity

1. **`daysRequired` function**:
   - The for loop iterates through the weights vector once, so the time complexity is (O(n)), where (n) is the number of weights.

2. **`shipWithinDays` function**:
   - Finding the maximum element with `max_element` takes (O(n)).
   - Calculating the sum of elements with `accumulate` also takes (O(n)).
   - The binary search loop runs (O(log{S})) times, where (S) is the range between `low` and `high` (the sum of all weights).
   - For each iteration of the binary search, the `daysRequired` function is called, which takes (O(n)).

Therefore, the overall time complexity is (O(n log{S})).

### Space Complexity

1. **`daysRequired` function**:
   - Uses a constant amount of extra space for variables `days` and `load`, so the space complexity is (O(1)).

2. **`shipWithinDays` function**:
   - Uses a constant amount of extra space for variables `low`, `high`, and `mid`, so the space complexity is (O(1)).

Since the functions use only a constant amount of extra space apart from the input vector, the overall space complexity is (O(1)).
*/