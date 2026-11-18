class Solution {
public:
    int solve(int ind,vector<int> &dp,vector<int> &nums){
        int n=nums.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){return dp[ind];}
        int take=nums[ind]+solve(ind+2,dp,nums);
        int not_take=solve(ind+1,dp,nums);
        return dp[ind]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int res=solve(0,dp,nums);
        return res;
        
    }
};