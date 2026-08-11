class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,int color,int icol, vector<vector<int>> &vis){
        int n=image.size();
        int m=image[0].size();
        vis[row][col]=1;
        image[row][col]=color;
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==icol && vis[nrow][ncol]==0){
                dfs(nrow,ncol,image,color,icol,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        dfs(sr,sc,image,color,image[sr][sc],vis);
        return image;

        
    }
};