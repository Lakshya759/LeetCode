class Solution:
    def solve(self,nums,ind,dp,n):
        
        if(ind>n):
            return 0
        if(dp[ind]!=-1):
            return dp[ind]
        take=nums[ind]+self.solve(nums,ind+2,dp,n)
        not_take=self.solve(nums,ind+1,dp,n)
        dp[ind]=max(take,not_take)
        return dp[ind]

    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if(len(nums)==1):
            return nums[0]
        dp1=[-1]*(len(nums)+1)
        dp2=[-1]*(len(nums)+1)
        res1=self.solve(nums,1,dp1,n-1)
        res2=self.solve(nums,0,dp2,n-2)
        res=max(res1,res2)
        return res

        