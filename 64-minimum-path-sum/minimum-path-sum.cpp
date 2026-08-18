class Solution {
public:
    int solve(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(row==0 && col==0){
            return grid[row][col];
        }
        if(dp[row][col]!=-1)return dp[row][col];
        int top=INT_MAX,right=INT_MAX;
        if(row>0){
            top=solve(row-1,col,grid,dp);
        }
        if(col>0){
            right=solve(row,col-1,grid,dp);
        }
        int res=grid[row][col]+min(top,right);
        return dp[row][col]=res;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(n-1,m-1,grid,dp);
    }
};