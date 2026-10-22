class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &img, int c1, int c2, vector<vector<int>> &vis ){
        int n=img.size();
        int m=img[0].size();
        vis[row][col]=1;
        vector<int> dr={1,-1,0,0};
        vector<int> dc={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && img[nr][nc]==c1 && vis[nr][nc]==0){
                dfs(nr,nc,img,c1,c2,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(sr,sc,image,image[sr][sc],color,vis);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    image[i][j]=color;
                }
            }
        }
        

        return image;
        
    }
};