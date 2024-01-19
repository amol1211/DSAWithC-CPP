//2352. Equal Row and Column Pairs

#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Approach 1 : Brute force approach

class Solution {
public:

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int count = 0;

    // Loop through each element in the grid
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            bool isEqual = true;

            // Check if all corresponding elements in the row and column are equal
            for (int i = 0; i < n; i++) {
                if (grid[r][i] != grid[i][c]) {
                    isEqual = false;
                    break;
                }
            }

            // If all elements are equal, increment the count
            if (isEqual == true)
                count++;
        }
    }

    // Return the final count
    return count;
    }
};

/*Time complexity: O(N^3), where N is the size of the grid. The three nested loops 
contribute to a cubic time complexity.
Space complexity: O(1) (constant space), as the algorithm uses a fixed amount of extra space 
regardless of the input size.*/

/*----------------------------------------------------------------------------------------------------*/

//Approach 2 : Using map

class Solution {
public:

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int count = 0;

    // Create a map to store the frequency of each row
    map<vector<int>, int> mp; //key : row , value : count(frequency) of that corresponding row

    // Loop through each row in the grid
    for (int r = 0; r < n; r++) {
        mp[grid[r]]++; // Update the frequency of the current row
    }

    // Loop through each column in the grid
    for (int c = 0; c < n; c++) {
        vector<int> temp;

        // Populate temp vector with elements from the current column
        for (int r = 0; r < n; r++) {
            temp.push_back(grid[r][c]);
        }

        // Increment count by the frequency of the current column in the map
        count += mp[temp];
    }

    // Return the final count
    return count;
   }
};

/*Time complexity: O(N^2), where N is the size of the grid. The outer loop runs in O(N), 
and for each iteration, the inner loop runs in O(N), resulting in a total complexity of O(N^2).

Space complexity: O(N^2), where N is the size of the grid (due to the map).*/