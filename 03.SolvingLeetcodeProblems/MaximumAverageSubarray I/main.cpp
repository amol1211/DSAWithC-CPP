// This class represents a solution to a specific problem.
class Solution {
public:
    // This function calculates the maximum average of a subarray of size 'k' within the given 'nums' array.
    double findMaxAverage(vector<int>& nums, int k) {
    
        // Initialize a variable to keep track of the sum of the first 'k' elements.
        double avgSum = 0;
        for(int i = 0; i < k; i++) {
            avgSum += nums[i];
        }
        
        // Calculate the average of the first 'k' elements.
        avgSum = avgSum / k;
        
        // Initialize a variable to store the final result.
        double result = avgSum;
        
        // Iterate through the array starting from the (k+1)-th element.
        for (int i = k; i < nums.size(); i++) {
            // Get the value of the element that will be removed from the current subarray.
            int prev = nums[i - k];
            
            // Get the value of the element that will be added to the current subarray.
            int next = nums[i];
            
            // Update the average sum by adding the difference between the new element and the removed element.
            avgSum = avgSum + double(next - prev) / k;
            
            // Update the result with the maximum of the current result and the updated average sum.
            result = max(result, avgSum);
        }
        
        // Return the maximum average.
        return result;
    }
};
