//875. Koko Eating Bananas

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to check if Koko can eat all bananas at a given speed 'mid' within 'h' hours
    bool canEatAll(vector<int>& piles, int mid, int h) {
        int actualHours = 0;

        // Iterate through each pile of bananas
        for (int &x : piles) {
            // Calculate the number of hours needed to eat the current pile at speed 'mid'
            actualHours += x / mid;

            // If there are remaining bananas after dividing, add an extra hour
            if (x % mid != 0) {
                actualHours++;
            }
        }

        // Check if the total hours required is within the allowed hours 'h'
        return actualHours <= h;
    }    

public:
    // Main function to find the minimum eating speed 'k' such that Koko can finish all bananas within 'h' hours
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        // Set the lower bound of the binary search to 1 (minimum eating speed)
        int l = 1;
        // Set the upper bound of the binary search to the maximum number of bananas in any pile
        int r = *max_element(piles.begin(), piles.end());

        // Perform binary search to find the minimum feasible eating speed
        while (l < r) {
            // Calculate the middle point of the current range
            int mid = l + (r - l) / 2;
            // Check if Koko can eat all bananas at speed 'mid' within 'h' hours
            if (canEatAll(piles, mid, h)) {
                // If yes, adjust the upper bound to search for a smaller possible speed
                r = mid;
            } else {
                // If no, adjust the lower bound to search for a larger possible speed
                l = mid + 1;
            }
        }

        // Return the minimum eating speed found
        return l;
    }
};

/*
Time Complexity

- **Binary Search:** The binary search operates on the range from 1 to the maximum number of bananas in any pile, which is 
 O(log(text{max}(piles)))
 .
- **Feasibility Check (canEatAll):** For each middle point in the binary search, we check all piles, resulting in ( O(n) ) per check.
  
Combining these, the overall time complexity is:
O(n log({max}(piles))) 

### Space Complexity
- The space complexity is primarily O(1)  as we use a constant amount of extra space aside from the input.

In summary:
- **Time Complexity: O(n log(text{max}(piles))) 
- **Space Complexity: O(1) 

*/