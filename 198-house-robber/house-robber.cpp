class Solution {
public:
    int solve(int ind,vector<int> &nums,vector<int> &dp){
        int n=nums.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int take=nums[ind]+solve(ind+2,nums,dp);
        int not_take=solve(ind+1,nums,dp);
        return dp[ind]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
        
        
    }
};