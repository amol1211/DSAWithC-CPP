//73. Set Matrix Zeroes

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // check if first row has zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // check if first column has zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        
        // mark zeros on first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        // set zeros except for first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // set zeros for first row and column
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

//The time complexity of this algorithm is O(mn)
//The space complexity of this algorithm is O(1)

/* We start by initializing two boolean variables, firstRowZero and firstColZero, to false. These variables 
will be used later to keep track of whether the first row or first column of the matrix should be set to 0.

We iterate through the first row of the matrix to check if there are any zeros in it. If we find a zero, we set
firstRowZero to true.

We iterate through the first column of the matrix to check if there are any zeros in it. If we find a zero, we set 
firstColZero to true.

We iterate through the rest of the matrix (i.e., starting from the second row and second column). For each element that 
is equal to 0, we set the corresponding element in the first row to 0 and the corresponding element in the first column to 0.

We iterate through the matrix again (starting from the second row and second column). For each element that is in a row or 
column that has been marked with a 0 in the first row or first column, we set the element to 0.

Finally, if firstRowZero is true, we set the entire first row of the matrix to 0. If firstColZero is true, we set the entire 
first column of the matrix to 0.

By using the first row and first column to store information about which rows and columns should be set to 0, we can do this 
in-place without using any extra space (except for the two boolean variables).
*/