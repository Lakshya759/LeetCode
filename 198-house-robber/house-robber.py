class Solution:
    def solve(self,nums,ind,dp):
        if(ind>=len(nums)):
            return 0
        if(dp[ind]!=-1):
            return dp[ind]
        take=nums[ind]+self.solve(nums,ind+2,dp)
        not_take=self.solve(nums,ind+1,dp)
        dp[ind]=max(take,not_take)
        return dp[ind]

    def rob(self, nums: List[int]) -> int:
        dp=[-1]*(len(nums)+1)
        res=self.solve(nums,0,dp)
        return res
        