#include <iostream>
#include <vector>
using namespace std;

// 1 2 3
// 4 5 6
// 7 8 9

//left = 1, right = 1
//top = 2, bottom = 1
//direction = 3 + 1 % 4 = 0

// 1 2 3 6 9 8 7 4 5
void spiralOrder(vector<vector<int>>& matrix) {

    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    int direction = 0;

    while(left <= right && top <= bottom) {
        // left -> right
        if(direction == 0) {
            for(int col = left; col <= right; col++) {
            cout << matrix[top][col] <<" ";
            }
            top++;
        }

        // top -> bottom
        else if(direction == 1) {
            for(int row = top; row <= bottom; row++) {
                cout << matrix[row][right] <<" ";
            }
            right--;
        }

        //right -> left
        else if(direction == 2) {
            for(int col = right; col >= left; col--) {
                cout << matrix[bottom][col] <<" ";
            }
            bottom--;
        }

        // bottom -> top
        else {
            for(int row = bottom; row >= top; row--) {
                cout << matrix[row][left] <<" ";
            }
            left++;
        }
        direction = (direction + 1)%4; //0,1,2,3

    }
}

int main() {

    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int> (m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>matrix[i][j];
        }
    }

    spiralOrder(matrix);

    return 0;
}

/*--------------------------------------------------------------------------------------*/

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int* result = (int*) malloc(matrixSize * (*matrixColSize) * sizeof(int));
    *returnSize = 0;
    if(matrixSize == 0 || *matrixColSize == 0) {
        return result;
    }
    int left = 0;
    int right = *matrixColSize - 1;
    int top = 0;
    int bottom = matrixSize - 1;

    int direction = 0;

    while(left <= right && top <= bottom) {
        // left -> right
        if(direction == 0) {
            for(int col = left; col <= right; col++) {
                result[(*returnSize)++] = matrix[top][col];
            }
            top++;
        }

        // top -> bottom
        else if(direction == 1) {
            for(int row = top; row <= bottom; row++) {
                result[(*returnSize)++] = matrix[row][right];
            }
            right--;
        }

        //right -> left
        else if(direction == 2) {
            for(int col = right; col >= left; col--) {
                result[(*returnSize)++] = matrix[bottom][col];
            }
            bottom--;
        }

        // bottom -> top
        else {
            for(int row = bottom; row >= top; row--) {
                result[(*returnSize)++] = matrix[row][left];
            }
            left++;
        }
        direction = (direction + 1)%4; //0,1,2,3

    }
    return result;
}
