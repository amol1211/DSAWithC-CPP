//1512. Number of Good Pairs

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Approach 1 : Brute force approach

class Solution {
public:
    // Function to count the number of identical pairs in a vector of integers
    int numIdenticalPairs(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();

        // Initialize a counter for identical pairs
        int count = 0;

        // Iterate through each element in the vector
        for (int i = 0; i < n; i++) {

            // Compare the current element with all elements to its right
            for (int j = i + 1; j < n; j++) {
                // If two elements are identical, increment the counter
                if (nums[i] == nums[j]) {
                    count += 1;
                }
            }
        }

        // Return the final count of identical pairs
        return count;
    }
};

/*
Space Complexity:
The time complexity is O(n^2), where n is the size of the input vector.
Space Complexity:
The algorithm uses a constant amount of space (for variables like n and count), 
so the space complexity is O(1).*/

/*-------------------------------------------------------------------------------------------------------------*/

//Approach 2 : Using unordered map and formula (n * (n - 1) / 2 )for counting occurences of elements 

class Solution {
public:
    // Function to count the number of identical pairs in a vector of integers
    int numIdenticalPairs(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();

        // Initialize the result variable to store the count of identical pairs
        int result = 0;

        // Create an unordered_map to store the count of each number in the vector
        unordered_map<int, int> mp;

        // Iterate through each element in the vector and update the count in the map
        for (auto& i : nums) {
            mp[i]++;
        }

        // Iterate through the map and calculate the count of identical pairs using the formula
        for (auto& it : mp) {
            int count = it.second;
            result += (count * (count - 1)) / 2;  // Using the formula for combinations to calculate pairs
        }

        // Return the final count of identical pairs
        return result;
    }
};

/*Time Complexity:
The first loop takes O(n) time to iterate through each element in nums and 
update the counts in mp, where n is the size of the input vector.

The second loop iterates through the unique elements in the original vector, 
where the number of unique elements is less than or equal to n. Therefore, in the worst case, 
where all elements are unique, the second loop takes O(n) time.
Overall, the time complexity is O(n).

Space Complexity:
The space complexity is O(n), where n is the size of the input vector. This is because 
the unordered_map mp stores the count of each unique element in the vector.*/

/*------------------------------------------------------------------------------------------------------------------------*/

//Approach 3 : Using unordered map single pass 

class Solution {
public:
    // Function to count the number of identical pairs in a vector of integers
    int numIdenticalPairs(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();

        // Initialize a counter for identical pairs
        int count = 0;

        // Create an unordered_map to store the count of each number in the vector
        unordered_map<int, int> mp;

        // Iterate through each element in the vector
        for (auto& i : nums) {
            // Increment the counter by the current count of the element in the map
            count = count + mp[i];
            
            // Increment the count of the current element in the map
            mp[i]++;
        }

        // Return the final count of identical pairs
        return count;
    }
};


/*Time Complexity:

The loop takes O(n) time to iterate through each element in the vector.
Space Complexity:

The space complexity is O(n) due to the unordered_map storing the count of each number in the vector.*/