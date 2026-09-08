class Solution:
    def countCommas(self, n: int) -> int:
        res=n-999
        if(res<=0):
            return 0
        else:
            return res
        