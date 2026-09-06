class Solution {
public:
    int solve(int i,int j,string s,string t,vector<vector<int>> &dp){
        int n=s.length();
        int m=t.length();
        if( j>=m){
            return 1;
        }
        if(i>=n){
            return 0;
        }
        if(dp[i][j]!=-1){return dp[i][j];}

        
        int take=0;
        if(s[i]==t[j]){
            take=solve(i+1,j+1,s,t,dp);
        }
        int notTake=solve(i+1,j,s,t,dp);
        return dp[i][j]=take+notTake;


    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        
        
        for(int i=0;i<n+1;i++){
            dp[i][m]=1;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                long long take=0;
                if(s[i]==t[j]){
                    take=dp[i+1][j+1];
                }
                long long notTake=dp[i+1][j];

                dp[i][j]=take+notTake;
                if (dp[i][j] > INT_MAX) {
                    dp[i][j] = INT_MAX;
                }
            }
        }
        long long res=dp[0][0];
        return res;
    }
};