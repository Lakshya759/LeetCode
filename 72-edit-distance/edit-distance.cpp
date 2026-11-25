class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(i<0){
            return max(0,j+1);
        }
        if(j<0){
            return max(0,i+1);
        }
        if(dp[i][j]!=-1){return dp[i][j];}


        if(s[i]==t[j]){

           return dp[i][j]=solve(i-1,j-1,s,t,dp);

        }

        int x=1+solve(i,j-1,s,t,dp);
        int y=1+solve(i-1,j,s,t,dp);
        int z=1+solve(i-1,j-1,s,t,dp);
        return dp[i][j]=min(x,min(y,z));
    }
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,w1,w2,dp);
    }
};