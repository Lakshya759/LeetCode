class Solution {
public:
    bool solve(int ind,int sum,vector<int> &nums,int tsum,vector<vector<int>> &dp){
        int n=nums.size();
        if(ind==n){
            return false;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        int temp=sum+nums[ind];
        if(temp==tsum-temp){
            return true;
        }
        bool take=solve(ind+1,temp,nums,tsum,dp);
        bool not_take=solve(ind+1,sum,nums,tsum,dp);
        return dp[ind][sum]= (take || not_take);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,0,nums,sum,dp);
        

    }
};