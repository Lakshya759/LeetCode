class Solution {
public:
    int solve(int ind,vector<int> &dp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return 1;
        }
        if(dp[ind]!=-1){return dp[ind];}
        int res=solve(ind-1,dp)+solve(ind-2,dp);
        return dp[ind]=res;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int res=solve(n ,dp);
        return res;
        
    }
};