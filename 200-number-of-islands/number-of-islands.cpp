class Solution {
public:
    void dfs(int row,int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        vector<int> dr={1,-1,0,0};
        vector<int> dc={0,0,-1,1};
        for(int i=0;i<4;i++){
            int r=row+dr[i];
            int c=col+dc[i];
            if(r<n && r>=0 && c<m && c>=0 && grid[r][c]=='1' && vis[r][c]==0){
                dfs(r,c,vis,grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};