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
