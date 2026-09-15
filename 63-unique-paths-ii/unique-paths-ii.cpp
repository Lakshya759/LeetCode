class Solution {
public:
    int solve(int r,int c, vector<vector<int>> &grid,vector<vector<int>> &dp){
        int n=grid[0].size();
        int m=grid.size();
        if(r==m-1 && c==n-1){
            return 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int res=0;
        vector<int> dr={1,0};
        vector<int> dc={0,1};
        for(int i=0;i<2;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0){
                res+=solve(nr,nc,grid,dp);
            }
            
        }
        return dp[r][c]=res;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[m-1][n-1]==1 || grid[0][0]==1){
            return 0;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        return solve(0,0,grid,dp);
        
    }
};