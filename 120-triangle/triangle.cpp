class Solution {
public:
    int solve(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(row==0 && col==0){
            return grid[row][col];
        }
        if(dp[row][col]!=-1)return dp[row][col];
        int top=INT_MAX,right=INT_MAX;
        if(row>0 && col<row){
            top=solve(row-1,col,grid,dp);
        }
        if(col>0){
            right=solve(row-1,col-1,grid,dp);
        }
        return dp[row][col]=grid[row][col]+min(top,right);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int res=INT_MAX;
        for(int i=0;i<m;i++){
            int x=solve(n-1,i,grid,dp);
            res=min(x,res);
        }
        return res;
    }
};