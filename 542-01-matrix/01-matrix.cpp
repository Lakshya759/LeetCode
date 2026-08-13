class Solution {
public:
vector<vector<int>> bfs(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                dist[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int d=q.front().second;
        q.pop();
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if((nr>=0 && nr<n) && (nc>=0 && nc<m)){
                if(mat[nr][nc]==1 && dist[nr][nc]==INT_MAX){
                    dist[nr][nc]=min(dist[nr][nc],d+1);
                     q.push({{nr,nc},d+1});
                }
            }
        }
    }
    return dist;

}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return bfs(mat);
    }
};