class Solution {
public:
    bool dfs(int node, int clr, vector<int> &vis, vector<vector<int>>& adj){
        vis[node]=clr;
        for(auto it:adj[node]){
            if(vis[it]==-1){
                if(!dfs(it,!clr,vis,adj)){return false;}
            }
            if(clr==vis[it]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(i,0,vis,graph)){
                    return false;
                }
            }
        }
        return true;
        
    }
};