class Solution {
public:
    void bfs(int r,int c,vector<vector<char>> &grid, vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            vector<int> dr={0,-1,1,0};
            vector<int> dc={1,0,0,-1};
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m =grid[0].size();
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    bfs(i,j,grid,vis);
                    count++;
                }
                
            }
        }
        return count;
    }
};