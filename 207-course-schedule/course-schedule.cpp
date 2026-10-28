class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<vector<int>>& adj,vector<int> &path){
        vis[node]=1;
        path[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==1 && path[it]==1){
                return 0;
            }
            if(vis[it]==0){
                if(!dfs(it,vis,adj,path)){
                    return 0;
                };
            }
        }
        path[node]=0;
        return 1;
    }
    bool canFinish(int n, vector<vector<int>>& edge) {
        
        vector<vector<int>> adj(n);
        for(auto it:edge){
            adj[it[0]].push_back(it[1]);
            
        }
        vector<int> vis(n,0);
        vector<int> path(n,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(!dfs(i,vis,adj,path)){
                    return 0;
                };
            }
        }
        return 1;

        
    }
};