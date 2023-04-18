//118. Pascal's Triangle
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Create a vector with numRows rows
        vector<vector<int>> r(numRows);

        // Loop over each row
        for (int i = 0; i < numRows; i++) {
            // Resize the current row to have i + 1 elements
            r[i].resize(i + 1);
            // Set the first and last elements of the current row to 1
            r[i][0] = r[i][i] = 1;

            // Loop over the remaining elements of the current row
            for (int j = 1; j < i; j++) {
                // Set the current element to the sum of the two elements above it in the previous row
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }

        // Return the completed Pascal's triangle
        return r;
    }
};
