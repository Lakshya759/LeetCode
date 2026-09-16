class Solution:
    def nCr(self,n, r):
        MOD=1000000007
        if r<0 or r>n:
            return 0

        r=min(r,n-r)
        ans=1

        for i in range(1, r+1):
            ans=ans*(n-r+i)%MOD
            ans=ans*pow(i,MOD-2,MOD)%MOD
        return ans

    def numberOfSets(self, n: int, k: int) -> int:
        if(k==1):
            return self.nCr(n,k+1)
        MOD=1000000007
        res=self.nCr(n+k-1,2*k)
        
        return res
        