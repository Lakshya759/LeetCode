class Solution:
    def solve(self,r,c,m,n,dp):
        
        if(r==m-1 and c==n-1):
            return 1
        if(dp[r][c]!=-1):
            return dp[r][c]
        dr=[1,0]
        dc=[0,1]
        res=0
        for i in range(2):
            nr=r+dr[i]
            nc=c+dc[i]
            if(nr>=0 and nr<m and nc>=0 and nc<n):
                res+=self.solve(nr,nc,m,n,dp)
        dp[r][c]=res
        return dp[r][c]

    def uniquePaths(self, m: int, n: int) -> int:
        dp=[[-1]*(n+1) for i in range(m+1)]
        res=self.solve(0,0,m,n,dp)
        return res

        