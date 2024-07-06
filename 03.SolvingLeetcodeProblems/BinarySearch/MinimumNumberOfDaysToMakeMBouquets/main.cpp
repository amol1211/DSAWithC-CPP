//1482. Minimum Number of Days to Make m Bouquets

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the number of bouquets that can be made by day 'mid'
    int canMakeMBouq(vector<int>& bloomDay, int mid, int k) {
         int bouqCount = 0; // Initialize bouquet count to 0
         int consecutiveCount = 0; // Initialize consecutive flowers count to 0

         // Loop through each day in the bloomDay vector
         for (int i = 0; i < bloomDay.size(); i++) {
              if (bloomDay[i] <= mid) { // If the flower blooms by day 'mid'
                  consecutiveCount++; // Increment consecutive flowers count
              } else {
                  consecutiveCount = 0; // Reset consecutive flowers count if condition not met
              }

              // If enough consecutive flowers to make a bouquet
              if (consecutiveCount == k) {
                  bouqCount++; // Increment bouquet count
                  consecutiveCount = 0; // Reset consecutive flowers count
              }
         }

         return bouqCount; // Return the total number of bouquets made
    }

    // Function to find the minimum number of days required to make 'm' bouquets
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(); // Get the number of days in bloomDay

        int startDay = 1; // Minimum possible day
        int endDay = *max_element(bloomDay.begin(), bloomDay.end()); // Maximum possible day

        int minDays = -1; // Initialize the result with -1 (not found)

        // Binary search to find the minimum day
        while (startDay <= endDay) {
               int mid = startDay + (endDay - startDay) / 2; // Calculate the middle day
               // If it's possible to make at least 'm' bouquets by day 'mid'
               if (canMakeMBouq(bloomDay, mid, k) >= m) {
                   minDays = mid; // Update the minimum days
                   endDay = mid - 1; // Try to find a smaller number of days
               } else {
                   startDay = mid + 1; // Try to find a larger number of days
               }
        }

        return minDays; // Return the minimum number of days found
    }
};

/*### Time Complexity
- The `canMakeMBouq` function has a time complexity of O(n), where n is the number of 
elements in the `bloomDay` vector. This is because it loops through each element in the vector once.
- The `minDays` function uses a binary search algorithm, which has a time complexity of O(log D), 
where D is the range of possible days (from 1 to the maximum value in `bloomDay`). Each call to 
`canMakeMBouq` within the binary search is O(n). Therefore, the total time complexity of the `minDays` 
function is O(n log D).

### Space Complexity
- The space complexity of the `canMakeMBouq` function is O(1) as it uses a constant amount of extra space.
- The space complexity of the `minDays` function is also O(1) because it uses only a few extra variables 
for the binary search and does not require additional space proportional to the input size.
*/