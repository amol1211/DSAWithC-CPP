// GFG problem

#include <iostream>
using namespace std;

class Solution{
public:
    // Function to find the starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n) {
        // Initialize variables to keep track of the deficit, starting point, and balance.
        int deficit = 0;
        int start = 0;
        int balance = 0;

        // Iterate through the petrol pumps.
        for (int i = 0; i < n; i++) {
            // Calculate the balance by subtracting the distance from the petrol available at the current pump.
            balance += p[i].petrol - p[i].distance;

            // If the balance becomes negative, it means we can't reach the next pump, so we adjust the starting point.
            if (balance < 0) {
                // Add the negative balance to the deficit.
                deficit += balance;
                // Update the starting point to the next pump.
                start = i + 1;
                // Reset the balance to 0 because we're starting from the new pump.
                balance = 0;
            }
        }

        // Check if it's possible to complete the circular route.
        // The truck can complete the route if the sum of the deficit and balance is non-negative.
        if (deficit + balance >= 0) {
            return start; // Return the starting point.
        } else {
            return -1; // Return -1 if it's not possible to complete the route.
        }
    }
};

//Time complexity : O(n)
//Space complesity : O(1)
