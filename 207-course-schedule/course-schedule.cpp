class Solution {
public:
    bool dfs(int node , vector<int> &vis, vector<int> &pvis,vector<int> adj[]){
        vis[node]=1;
        pvis[node]=1;
        for(auto it:adj[node]){
            if(pvis[it]){
                return true;
            }
            if(vis[it]==0){
                if(dfs(it,vis,pvis,adj)){
                    return true;
                }
            }
        }
        pvis[node]=0;
        return false;
    }
   
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto it: pre){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(n,0);
        vector<int> pvis(n,0);
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                if(dfs(i,vis,pvis,adj)){
                    return false;
                }
            }
        }
        return true;
        
    }
};