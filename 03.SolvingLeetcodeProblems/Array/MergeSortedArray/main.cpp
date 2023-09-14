//88. Merge Sorted Array

//1.Solved using Array + Sorting. (Brute Force Approach).

/*
Time Complexity : O(N+M), Because we iterate N+M times for both the Array(nums1 and nums2). 
Where M is the number of elements in Array(nums1) and N is the number of elements in Array(nums2).
Space Complexity : O(1), Constant Space.
*/

// Define a class called Solution
class Solution {
public:
    // Define a function called merge that takes in four arguments: a vector of integers called nums1,  
    // an integer called m, another vector of integers called nums2, and an integer called n
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Add each element of nums2 to the end of nums1
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        // Sort the entire nums1 vector
        sort(nums1.begin(), nums1.end());
    }
};

/*-----------------------------------------------------------------------------------------------------------------------*/

//2.Solved using Array + Two Pointers. 

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Initialize three pointers i, j, and k
    // i and j are used to traverse nums1 and nums2 respectively
    // k is used to store the merged elements in nums1
    int i = m - 1, j = n - 1, k = m + n - 1;
    
    // Merge the elements in nums1 and nums2 in descending order
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) { // If nums1 has a larger element
            nums1[k] = nums1[i];    // Copy the element to the end of nums1
            i--;                    // Decrement i
            k--;                    // Decrement k
        } else {                    // If nums2 has a larger element
            nums1[k] = nums2[j];    // Copy the element to the end of nums1
            j--;                    // Decrement j
            k--;                    // Decrement k
        }
    }
    
    // If there are remaining elements in nums2, copy them to the end of nums1
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
