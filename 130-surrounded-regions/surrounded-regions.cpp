class Solution {
public:
    // void bfs(int row,int col, vector<vector<int>> &vis, vector<vector<char>> &mat){
    //     int n=mat.size();
    //     int m=mat[0].size();
    //     queue<pair<int,int>> q;
       
        
    //     q.push({row,col});
    //     vis[row][col]=1;
    //     while(!q.empty()){
    //         int row=q.front().first;
    //         int col=q.front().second;
            
    //         q.pop();
    //         vector<int> dr={0,0,1,-1};
    //         vector<int> dc={-1,1,0,0};
    //         for(int i=0;i<4;i++){
    //             int r=row+dr[i];
    //             int c=col+dc[i];
    //             if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0 && mat[r][c]=='0'){
                    
    //                 vis[r][c]=1;
    //                 q.push({r,c});
    //             }
    //         }
    //     }
    // }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(mat[i][m-1]=='O'){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }

        for(int i=0;i<m;i++){
            if(mat[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(mat[n-1][i]=='O'){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            vector<int> dr={0,0,1,-1};
            vector<int> dc={-1,1,0,0};
            for(int i=0;i<4;i++){
                int r=row+dr[i];
                int c=col+dc[i];
                if(r>=0 && r<n && c>=0 && c<m && mat[r][c]=='O' && vis[r][c]==0){
                    vis[r][c]=1;
                    q.push({r,c});
                }

            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && vis[i][j]==0){
                    mat[i][j]='X';
                }
            }
        }
        
        

        
    }
};