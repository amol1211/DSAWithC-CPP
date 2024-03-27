// 1. Most efficient approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // If input vector is empty, return an empty vector
        if(nums.empty()) return {};
        
        // Create an empty vector to store the duplicates
        vector<int> ans;
        
        // Traverse the input vector
        for(int i=0;i<nums.size();i++){
            // Mark the element at the index equal to the absolute value of the current element as negative
            if(nums[abs(nums[i])-1]<0) // If it's already negative, it's a duplicate
                ans.push_back(abs(nums[i])); // Add it to the answer vector
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1]; // Mark the element as negative
        }
        
        // Return the answer vector
        return ans;
    }
};
// time complexity- O(n)
// space complexity- O(1)  
/* 
Assume I/O Array   A -[ 4,   3,   2,   7,   8,    2,   3,    1   ]
          index -       0     1    2   3    4     5    6      7
		  
				   
				   index                 element                       Todo                               
				    0                      A[0] = 4                   A[4-1] Not negative
					                                                  do it negetive mean we visited 4
																	  array - [4,3,2,-7,8,2,3,1]
																	 
					1                     A[1] = 3                      A[3-1] Not negative
					                                                    do it negetive mean we visited 3
					                                                    array - [4,3,-2,-7,8,2,3,1]
																	  
                   2                      A[2] = 2                      A[2-1] Not negative
				                                                        do it negetive mean we visited 2
																	    array - [4,-3,-2,-7,8,2,3,1]
																	 
				   3                        A[3]=7                      A[7-1] Not negative
				                                                        do it negetive mean we visited 7
																        Array- [4,-3,-2,-7,8,2,-3,1]
																 
				   4                       A[4]=8                      A[8-1] Not negative
				                                                       do it negetive mean we visited 8
																        Array- [4,-3,-2,-7,8,2,-3,-1]
																 
				   5                     A[5]=2                       A[2-1] is Negative Mean It is A 
				                                                      duplicate ele so Put it into ans array  
																     Array- [4,-3,-2,-7,8,2,-3,-1]
																
                    6                   A[6]=3                        A[3-1] is Negative Mean It is A 
                                                                     duplicate ele so Put it into ans array  
                                                                      Array- [4,-3,-2,-7,8,2,-3,-1]
																
					7                  A[7] = 1                     A[1-1] Not negative
					                                                do it negetive mean we visited 1
                                                                     Array- [-4,-3,-2,-7,8,2,-3,-1]
															   
	So we Have {2 , 3 }  <= Here For ans
*/

// 2. Brute force
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // If input vector is empty, return an empty vector
        if(nums.empty()) return {};
        
        // Create an empty vector to store the duplicates
        vector<int> ans;
        
        // Traverse the input vector
        for(int i=0;i<nums.size();i++){
            // Compare each element to all elements that come after it
            for(int j=i+1;j<nums.size();j++){
                // If a duplicate is found, add it to the answer vector and break out of the inner loop
                if(nums[i]!=nums[j]) continue;
                else{
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        
        // Return the answer vector
        return ans;
    }
};

// time complexity- O(n^2)
// space complexity- O(1)

// 3. Using sorting 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // If input vector is empty, return an empty vector
        if(nums.empty()) return {};
        
        // Create an empty vector to store the duplicates
        vector<int> ans;
        
        // Sort the input vector in non-descending order
        sort(begin(nums), end(nums));
        
        // Initialize s to the first element in the vector
        int s = nums[0];
        
        // Traverse the input vector
        for(int i=1; i<nums.size(); i++){
            // If the current element is equal to the previous element, it is a duplicate
            if(!(s^nums[i])){
                // Add the duplicate element to the answer vector
                /*when a Boolean expression is evaluated, it is converted to either true or false. 
                The ! operator is used to invert the Boolean value of an expression, not its numeric value.
                In the case of the expression !(s^nums[i]), if s and nums[i] have the same value, then their 
                XOR operation will result in 0, which is considered as false in C++. Since the ! operator is 
                applied to the expression, the resulting value will be the opposite of false, which is true.
                So, if the expression !(s^nums[i]) evaluates to true, it means that the XOR of s and nums[i] 
                is zero, which in turn means that s and nums[i] have the same value and nums[i] is a duplicate 
                of the previous element s.*/
                ans.push_back(nums[i]);
                
                // Skip the next element since we know it is a duplicate
                i += 1;
                
                // If there are more elements in the vector, update the value of s to the next element
                if(i < nums.size()) s = nums[i];
                else break;
            }
            // Otherwise, update the value of s to the current element
            else s = nums[i];
        }
        
        // Return the answer vector
        return ans;
    }
};
// time complexity- O(n log n)
// space complexity- O(1)

// 4. Using unordered map
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // If input vector is empty, return an empty vector
        if(nums.empty()) return {};
        
        // Create an empty vector to store the duplicates
        vector<int> ans;
        
        // Create an unordered map to count the occurrences of each element
        unordered_map<int,int> mp;
        
        // Traverse the input vector and add counts to the map
        for(int no : nums) {
            mp[no]++;
        }
        
        // Traverse the map and add any elements that appear exactly twice to the answer vector
        for(auto it : mp) {
            if(it.second == 2) {
                ans.push_back(it.first);
            }
        }
        
        // Return the answer vector
        return ans;
    }
};
// time complexity- O(n)
// space complexity- O(n)
 

 /*-------------------------------------------------------*/

 class Solution {
public:
    // Function to find duplicates in an array
    // Time Complexity: O(n), where n is the size of the input array nums.
    // Space Complexity: O(1) (excluding the output vector)
    vector<int> findDuplicates(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
        
        // Initialize a vector to store duplicate elements
        vector<int> ans;

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Get the absolute value of the current element
            int num = abs(nums[i]);
            
            // Calculate the index (zero-based) for the current number
            int index = num - 1;

            // If the number at index is negative, it means we've seen this number before,
            // so it's a duplicate. Add it to the output vector.
            if (nums[index] < 0) {
                ans.push_back(num);
            }
            // Otherwise, mark the number at index as seen by negating its value.
            else {
                nums[index] *= -1;
            }
        }

        // Return the vector containing duplicates
        return ans;
    }
};

/*
Here's the commented version of the provided C++ code with explanations and the time and space complexity analysis:

cpp
Copy code
class Solution {
public:
    // Function to find duplicates in an array
    // Time Complexity: O(n), where n is the size of the input array nums.
    // Space Complexity: O(1) (excluding the output vector)
    vector<int> findDuplicates(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
        
        // Initialize a vector to store duplicate elements
        vector<int> ans;

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Get the absolute value of the current element
            int num = abs(nums[i]);
            
            // Calculate the index (zero-based) for the current number
            int index = num - 1;

            // If the number at index is negative, it means we've seen this number before,
            // so it's a duplicate. Add it to the output vector.
            if (nums[index] < 0) {
                ans.push_back(num);
            }
            // Otherwise, mark the number at index as seen by negating its value.
            else {
                nums[index] *= -1;
            }
        }

        // Return the vector containing duplicates
        return ans;
    }
};
Explanation:

The function findDuplicates takes a vector of integers nums as input and returns a vector containing duplicates found in the input array.
It iterates through the input array, and for each element:
It calculates the absolute value of the element and uses it to find the index in the array.
If the value at that index is negative, it means we've seen this number before, so it's a duplicate. We add it to the output vector.
Otherwise, it marks the number at the calculated index as seen by negating its value.
Finally, it returns the vector containing the duplicates found in the input array.
Time Complexity:

The time complexity of the algorithm is O(n), where n is the size of the input array nums. This is because we iterate through the array once.
Space Complexity:

The space complexity is O(1) excluding the space required for the output vector. We only use a constant amount of extra space for variables n, ans, num, and index, regardless of the size of the input array.*/