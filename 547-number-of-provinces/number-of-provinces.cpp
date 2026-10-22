class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj, vector<int> & vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isC) {
        int n=isC.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isC[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int count=0;
        vector<int> vis(n+1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;

    }
};