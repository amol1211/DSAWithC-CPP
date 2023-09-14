/*Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.

Example 1:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]

Example 2:
Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

Example 3:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
    int m= size(grid) , n= size(grid[0]);
    auto func=[](vector<vector<int>> &ans,int m,int n){
        int last= ans[m-1][n-1];
        for(int i=m-1;i>=0;i--){
          for(int j=n-1;j>=0;j--){
             if(i==m-1 and j==n-1) continue;
             if(j==n-1) ans[i+1][0]= ans[i][j];
             else ans[i][j+1]= ans[i][j];
          }
        }
        ans[0][0]=last;
    };
    k=k%(m*n);
    while(k--) func(grid,m,n);
    return grid;
}
    
};
