//881. Boats to Save People

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate the minimum number of boats required
    int numRescueBoats(vector<int>& people, int limit) {
        // Get the number of people
        int n = people.size();

        // Sort the array of people in ascending order
        sort(people.begin(), people.end());

        // Initialize pointers for the lightest and heaviest people
        int lightWeightPerson = 0;
        int heavyWeightPerson = n - 1;

        // Initialize variable to count the number of boats
        int boatCount = 0;

        // Iterate until all people have been considered
        while (lightWeightPerson <= heavyWeightPerson) {
            // Calculate the sum of weights of the lightest and heaviest people
            int sum = people[lightWeightPerson] + people[heavyWeightPerson];

            // Check if the sum is within the limit
            if (sum <= limit) {
                // If within limit, pair them on the same boat
                boatCount++;
                lightWeightPerson++;
                heavyWeightPerson--;
            } else {
                // If beyond limit, only the heaviest person can be on the boat
                boatCount++;
                heavyWeightPerson--;
            }
        }

        // Return the total number of boats required
        return boatCount;
    }
};

/*Time Complexity: The time complexity is O(n log n) due to the sorting step.
Space Complexity: The space complexity is O(1) as we are using constant extra space for variables.*/
