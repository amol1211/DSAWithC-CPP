//42. Trapping Rain Water

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private: 
    // Helper function to compute the left maximum for each element in the array
    vector<int> getLeftMaxArray(vector<int> &height, int &n) {
        // Initialize a vector to store left maximum values
        vector<int> leftMax(n);

        // The leftmost element has no left maximum, so its leftMax is itself
        leftMax[0] = height[0];

        // Iterate through the array to compute left maximum values
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        return leftMax;
    }  

    // Helper function to compute the right maximum for each element in the array
    vector<int> getRightMaxArray(vector<int> &height, int &n) {
        // Initialize a vector to store right maximum values
        vector<int> rightMax(n);

        // The rightmost element has no right maximum, so its rightMax is itself
        rightMax[n - 1] = height[n - 1];

        // Iterate through the array in reverse to compute right maximum values
        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        return rightMax;
    }      
public:

    int trap(vector<int>& height) {
        // Get the size of the input array
        int n = height.size();

        // Compute left maximum array
        vector<int> leftMax = getLeftMaxArray(height, n);

        // Compute right maximum array
        vector<int> rightMax = getRightMaxArray(height, n);

        // Initialize variable to store the total trapped water amount
        int sum = 0;

        // Iterate through each element and calculate trapped water at that position
        for (int i = 0; i < n; i++) {
            // Calculate the height of trapped water at the current position
            int h = min(leftMax[i], rightMax[i]) - height[i];

            // Add the calculated trapped water height to the total sum
            sum += h;
        }

        // Return the total trapped water amount
        return sum;
    }
};


//Time complexity : O(n)
//Space complexity : O(n)