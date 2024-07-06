//1870. Minimum Speed to Arrive on Time

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the total time taken with a given speed
    double isPossible(vector<int>& dist, int midSpeed) {
        double time = 0.0; // Initialize total time to 0

        int n = dist.size(); // Get the number of distances

        // Loop through all but the last distance
        for (int i = 0; i < n - 1; i++) {
            double t = (double)dist[i] / (double)midSpeed; // Calculate time for the current segment
            time += ceil(t); // Add the ceiling of the time to the total time
        }

        // Add the time for the last segment without ceiling
        time += (double)dist[n - 1] / (double)midSpeed;

        return time; // Return the total time taken
    }

    // Function to find the minimum speed required to reach within the given hour
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1; // Minimum possible speed
        int r = 1e7; // Maximum possible speed

        int minSpeed = -1; // Initialize the result with -1 (not found)

        // Binary search to find the minimum speed
        while (l <= r) {
            int midSpeed = l + (r - l) / 2; // Calculate the middle speed

            // If the time with midSpeed is within the given hour
            if (isPossible(dist, midSpeed) <= hour) {
                minSpeed = midSpeed; // Update the minimum speed
                r = midSpeed - 1; // Try to find a lower speed
            } else {
                l = midSpeed + 1; // Try to find a higher speed
            }
        }

        return minSpeed; // Return the minimum speed found
    }
};

/*### Time Complexity
- The `isPossible` function has a time complexity of O(n), where n is the number of 
distances in the dist vector. This is because it loops through each element in the vector once.
- The `minSpeedOnTime` function uses a binary search algorithm, which has a time complexity of O(log M),
 where M is the range of possible speeds (in this case, up to 10^7). Each call to isPossible within the 
 binary search is O(n). Therefore, the total time complexity of the minSpeedOnTime function is O(n log M).

### Space Complexity
- The space complexity of the `isPossible` function is O(1) as it uses a constant amount of extra space.
- The space complexity of the `minSpeedOnTime` function is also O(1) because it uses only a few extra 
variables for the binary search and does not require additional space proportional to the input size.
*/