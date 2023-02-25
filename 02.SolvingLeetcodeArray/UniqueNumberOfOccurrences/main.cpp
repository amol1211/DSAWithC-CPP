/* Problem statement
Given an array of integers arr, return true if the number of occurrences of each value in the array is 
unique or false otherwise.Given an array of integers arr, return true if the number of occurrences of 
each value in the array is unique or false otherwise.

Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:
Input: arr = [1,2]
Output: false

Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

Constraints:
1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans; // vector to store the number of occurrences of each element in arr
        int size = arr.size(); // size of arr
        int i = 0; // iterator for the while loop
        sort(arr.begin(),arr.end()); // sort arr in non-descending order
        
        // while loop to count occurrences of unique elements in arr
        while(i < size){
            int count = 1; // count of the current element
            for(int j = i+1; j < size; j++){
                if(arr[i] == arr[j]){ // if the next element is the same as the current element
                    count++; // increment count
                } else { // otherwise, break from the loop
                    break;
                }
            }
            ans.push_back(count); // push count to the ans vector
            i += count; // move the iterator to the next unique element
        }
        
        size = ans.size(); // update size to the size of the ans vector
        sort(ans.begin(),ans.end()); // sort the ans vector in non-descending order
        
        // loop to check if any adjacent elements in the ans vector are the same
        for(int i = 0; i < size-1; i++){
            if(ans[i] == ans[i+1]){ // if adjacent elements are the same
                return false; // there are multiple elements with the same number of occurrences, so return false
            }
        }
        
        return true; // if no adjacent elements are the same, then all elements in arr have unique occurrences
    }
};

/*
This is a C++ solution for a problem that checks whether each element in an input vector arr appears a unique number 
of times or not.

The code starts by declaring a new vector ans, which will be used to store the number of occurrences of each element in arr. 
Then, the code sorts the input vector arr using sort function from the STL library.

The while loop is used to iterate over the sorted input vector arr. It counts the number of occurrences of the current 
element by comparing it to the subsequent elements until there are no more occurrences. It then pushes the count into the 
ans vector and moves to the next unique element in the input vector arr.

After counting the occurrences of each unique element in the input vector, the ans vector is sorted using the sort function. 
The final loop compares adjacent elements in the ans vector. If any adjacent elements are the same, it means that there are 
multiple elements in the input vector arr that appear the same number of times, violating the problem statement. The function 
returns false in this case.

If all adjacent elements in the ans vector are different, then each element in the input vector arr appears a unique number of 
times, and the function returns true.
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i = 0;
        sort(arr.begin(), arr.end()); // sort arr in non-descending order
        vector<int> ans; // vector to store the number of occurrences of each element in arr
        while (i < arr.size()) {
            int count = 1;
            for (int j = i+1; j < arr.size(); j++) { // loop over the remaining elements of arr starting at i+1
                if (arr[i] == arr[j]) { // if the element at index i is equal to the element at index j
                    count++; // increment the count of occurrences of that element
                }
            }
            ans.push_back(count); // push count to the ans vector
            i = i + count; // update i to skip over the occurrences of the current element
        }
        sort(ans.begin(), ans.end()); // sort the vector of occurrence counts in non-descending order
        for (int i = 0; i < ans.size() - 1; i++) { // loop over the occurrence counts
            if (ans[i] == ans[i+1]) { // if two adjacent occurrence counts are the same
                return false; // the occurrences are not unique, so return false
            }
        }
        return true; // if the loop completes, then all occurrence counts are unique, so return true
    }
};


