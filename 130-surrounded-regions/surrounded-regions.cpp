class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1)&& board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            vector<int> dr={-1,0,1,0};
            vector<int> dc={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if((nr>=0 && nr<n) && (nc>=0 && nc<m) && board[nr][nc]=='O' && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};