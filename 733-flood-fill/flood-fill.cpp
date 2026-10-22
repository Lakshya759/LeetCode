class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &img, int c1, int c2 ){
        int n=img.size();
        int m=img[0].size();
        img[row][col]=c2;
        vector<int> dr={1,-1,0,0};
        vector<int> dc={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && (img[nr][nc]==c1 && img[nr][nc]!=c2)){
                dfs(nr,nc,img,c1,c2);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr,sc,image,image[sr][sc],color);
        return image;
        
    }
};