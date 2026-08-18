class Solution {
public:
    int solve(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(row==0 && col==0 && grid[row][col]==0){return 1;}
        if(grid[row][col]==1){
            return 0;
        }
        if(dp[row][col]!=-1)return dp[row][col];
        int top=0,right=0;
        if(row>0){
            top=solve(row-1,col,grid,dp);
        }
        if(col>0){
            right=solve(row,col-1,grid,dp);
        }
        return dp[row][col]=top+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,grid,dp);
    }
};