//2191. Sort the Jumbled Numbers

#include <bits/stdc++.h>
using namespace std;

//Approach 1: Using String Conversion

class Solution {
public:
    // This function maps each digit of the given number string using the provided mapping.
    string getMappedNum(string &num, vector<int>& mapping) {
        string mappedNum = "";  // Initialize an empty string to store the mapped number

        for (int i = 0; i < num.size(); i++) {  // Iterate over each character in the input number string
            char ch = num[i];  // Get the current character
            int intCh = ch - '0';  // Convert character to integer
            mappedNum += to_string(mapping[intCh]);  // Map the digit and append to the result string
        }

        return mappedNum;  // Return the mapped number as a string
    }

    // This function sorts the numbers based on the mapped values.
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();  // Get the size of the input numbers array

        vector<pair<int, int>> vec;  // Vector to store pairs of mapped numbers and their original indices

        for (int i = 0; i < n; i++) {  // Iterate over each number in the input array
            string numStr = to_string(nums[i]);  // Convert the number to a string

            string mappedStr = getMappedNum(numStr, mapping);  // Get the mapped string

            int mappedNum = stoi(mappedStr);  // Convert the mapped string back to an integer

            vec.push_back({mappedNum, i});  // Store the mapped number and its original index in the vector
        }

        sort(vec.begin(), vec.end());  // Sort the vector based on the mapped numbers

        vector<int> result;  // Vector to store the sorted numbers

        for (auto &p : vec) {  // Iterate over the sorted vector
            int originalNumIdx = p.second;  // Get the original index of the number

            result.push_back(nums[originalNumIdx]);  // Append the original number to the result vector
        }

        return result;  // Return the sorted numbers
    } 
};


/* Time Complexity
     getMappedNum:
     This function iterates over the length of the string num. If num has d digits, the time complexity is O(d).
     sortJumbled:
     Converting each number to a string and mapping it takes O(n⋅d) time, where n is the number of elements in nums and d is the average number of digits.
     Sorting the vector of pairs takes O(nlogn) time.
     Constructing the result vector takes O(n) time.
     Overall time complexity of sortJumbled: O(n⋅d+nlogn).

     Space Complexity
     getMappedNum:
     Uses a string mappedNum to store the mapped digits, which has a space complexity of O(d).
     sortJumbled:
     Uses a vector of pairs vec to store mapped numbers and their indices, which has a space complexity of O(n).
     The result vector has a space complexity of O(n).
     Overall space complexity of sortJumbled: O(n).

     */

    /*---------------------------------------------------------------------------------------------*/

    //Approach 2: Using Integer Manipulation

    class Solution {
private:
    // Function to get the mapped number using the mapping array
    // Time Complexity: O(d)
    // Space Complexity: O(1)
    int getMappedNum(int num, vector<int>& mapping) { // Pass num by value instead of by reference
        if (num < 10) {
            return mapping[num]; // Directly return the mapped value if num is a single digit
        }

        int mappedNum = 0; // Initialize the mapped number
        int placeValue = 1; // Initialize the place value (units, tens, etc.)

        while (num) { // Loop until num becomes 0
            int lastDigit = num % 10; // Get the last digit
            int mappedDigit = mapping[lastDigit]; // Get the mapped digit from the mapping array
            mappedNum += (mappedDigit * placeValue); // Construct the mapped number

            placeValue *= 10; // Move to the next place value
            num /= 10; // Remove the last digit from num
        }

        return mappedNum; // Return the constructed mapped number
    }    
public:
    // Function to sort the nums array based on the mapped values
    // Time Complexity: O(n * d + n log n)
    // Space Complexity: O(n)
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size(); // Get the size of the nums array

        vector<pair<int, int>> vec; // Vector to store pairs of mapped numbers and their original indices

        for (int i = 0; i < n; i++) { // Iterate over each number in nums
            int mappedNum = getMappedNum(nums[i], mapping); // Get the mapped number

            vec.push_back({mappedNum, i}); // Store the mapped number and its original index in the vector
        }

        sort(vec.begin(), vec.end()); // Sort the vector based on the mapped numbers

        vector<int> result; // Vector to store the sorted numbers

        for (auto &p : vec) { // Iterate over the sorted vector
            int originalNumIdx = p.second; // Get the original index of the number

            result.push_back(nums[originalNumIdx]); // Append the original number to the result vector
        }

        return result; // Return the sorted numbers
    } 
};
