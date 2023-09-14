// 48. Rotate Image

/***************************************** Approach 1 Code *****************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp[j][n-1-i] = matrix[i][j];

            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = temp[i][j];
            }
        }
    }
};
/*

    Time Complexity : O(N^2), Where N is the number of row and column of matrix. Here two nested loops creates
    the time complexity.

    Space Complexity : O(N^2), temp matrix space.

    Solved using Matrix + Math.

*/










/***************************************** Approach 2 Code *****************************************/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
/*

    Time Complexity : O(N^2), Where N is the number of row and column of matrix. Here two nested loops creates
    the time complexity.

    Space Complexity : O(1), Constant space.

    Solved using Matrix + Math.

*/