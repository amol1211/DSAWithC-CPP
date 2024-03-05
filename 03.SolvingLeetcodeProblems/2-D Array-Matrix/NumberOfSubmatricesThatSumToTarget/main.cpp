//1074. Number of Submatrices That Sum to Target

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : Brute force approach

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // Number of rows in the matrix
        int n = matrix[0].size(); // Number of columns in the matrix
        int result = 0; // Initialize the result variable to store the count of submatrices
        
        // Nested loops to iterate through all possible starting and ending points of submatrices
        for (int s_r = 0; s_r < m; s_r++) {
            for (int s_c = 0; s_c < n; s_c++) {
                for (int e_r = s_r; e_r < m; e_r++) {
                    for (int e_c = s_c; e_c < n; e_c++) {
                        int sum = 0; // Initialize the sum of elements in the current submatrix
                        
                        // Nested loops to calculate the sum of elements in the current submatrix
                        for (int i = s_r; i <= e_r; i++) {
                            for (int j = s_c; j <= e_c; j++) {
                                sum += matrix[i][j]; // Accumulate the sum
                            }
                        }
                        
                        // Check if the sum equals the target and increment the result if true
                        if (sum == target) {
                            result++;
                        }
                    }
                }
            }
        }
        
        return result; // Return the final count of submatrices
    }
};

/*Time Complexity: O(m^2 * n^2) where m is the number of rows and 
n is the number of columns in the matrix.
Space Complexity: O(1) This approach checks all possible submatrices and calculates their sums, 
which leads to high time complexity.*/

/*----------------------------------------------------------------------------------------------------------------------------*/

//Approach 2: Optimized using Prefix Sum (Cumulative Sum) and Hash Map

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(); // Number of rows in the matrix
        int cols = matrix[0].size(); // Number of columns in the matrix
        int result = 0; // Initialize the result variable to store the count of submatrices
        
        // First we'll find row wise cumulative sum
        // Calculate row-wise cumulative sums
        for (int row = 0; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                matrix[row][col] += matrix[row][col - 1]; // Update the element to contain the cumulative sum
            }
        }

        //Now, we need to find the no. of submatrices with sum == target (same as leetcode 560) in downword direction

        // Nested loops to iterate through all possible starting and ending columns
        for (int startCol = 0; startCol < cols; startCol++) {
            for (int j = startCol; j < cols; j++) {
                unordered_map<int, int> mp; // Hash map to store cumulative sums and their counts
                mp.insert({0, 1}); // Initialize the hash map with zero sum and count 1
                int cumulativeSum = 0; // Initialize the cumulative sum for the current column range
                
                // Iterate through all rows and calculate cumulative sums
                for (int row = 0; row < rows; row++) {
                    cumulativeSum += matrix[row][j] - (startCol > 0 ? matrix[row][startCol - 1] : 0); // Calculate cumulative sum considering the current column range
                    
                    // Check if the complement of target sum exists in the hash map and update the result accordingly
                    if (mp.find(cumulativeSum - target) != mp.end()) {
                        result += mp[cumulativeSum - target]; // Increment the result by the count of complement sums
                    }
                    
                    mp[cumulativeSum]++; // Update the hash map with the current cumulative sum
                }
            }
        }

        return result; // Return the final count of submatrices
    }
};

/*Time Complexity: O(m * n^2) where m is the number of rows and 
n is the number of columns in the matrix.
Space Complexity: O(m) for the hash map. This approach utilizes prefix sums and 
hash map to optimize the solution, significantly reducing the time complexity compared 
to the brute force approach.*/

