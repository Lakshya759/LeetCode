class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis){
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1 && vis[i][j]==0){
                        dfs(i,j,grid,vis);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;

    }
};