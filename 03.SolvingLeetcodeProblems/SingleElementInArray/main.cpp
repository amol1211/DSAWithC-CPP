// The idea of this solution is to use binary search to find the single element that appears only once.
// We will take advantage of the fact that all elements appear twice except the single element, and that the array is sorted.
// Therefore, for any element at index i in the array:
// - if i is even and nums[i] == nums[i+1], then the single element is to the right of i+1.
// - if i is odd and nums[i] == nums[i-1], then the single element is to the right of i.
// We can use binary search to keep narrowing down the search range until we find the single element.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Initialize the left and right pointers to the start and end of the vector.
        int n = nums.size();
        int left = 0, right = n -1;
        
        // Continue binary search until left and right pointers meet.
        while(left < right){
            // Calculate the mid-point of the vector.
            int mid = left + (right-left)/2;
            
            // Check if the mid-point is even.
            if(mid % 2 == 0){ 
                // If the element at mid is equal to the element at mid+1, then the single element is on the right side of mid.
                // Therefore, set the left pointer to mid+2.
                if(nums[mid] == nums[mid+1]) left = mid + 2;
                // Otherwise, the single element is on the left side of mid.
                // Therefore, set the right pointer to mid.
                else right = mid;
            }
            // If the mid-point is odd.
            else{ 
                // If the element at mid is equal to the element at mid-1, then the single element is on the right side of mid.
                // Therefore, set the left pointer to mid+1.
                if(nums[mid] == nums[mid-1]) left = mid + 1;
                // Otherwise, the single element is on the left side of mid.
                // Therefore, set the right pointer to mid-1.
                else right = mid - 1;
            }
        }
        
        // Return the single element.
        return nums[left];
    }
};

//Approach 2. Using XOR but with range based for loop
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0; // Initialize the result variable to 0.
        
        // Loop through all the elements in the vector and perform the XOR operation on each element with the result variable.
        for(int num : nums) {
            result ^= num; // XOR operation on each element with the result variable.
        }
        
        // Return the result, which will contain the single non-duplicate element.
        return result;
    }
};


// same approach but with conventional for loop

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector.
        int ans = nums[0]; // Initialize the answer variable to the first element of the vector.
        
        // Loop through all the elements in the vector starting from the second element.
        for (int i = 1; i < n; i++) {
            ans ^= nums[i]; // Perform the XOR operation on each element with the answer variable.
        }
        
        // Return the answer variable, which will contain the single non-duplicate element.
        return ans;
    }
};


