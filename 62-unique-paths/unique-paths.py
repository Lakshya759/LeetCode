class Solution:
    def solve(self,row,col,n,m,l):
        if(row==n and col==m):
            return 1
        if(row>n or col>m):
            return 0
        if(l[row][col]!=-1):
            return l[row][col]
        right=self.solve(row,col+1,n,m,l)
        down=self.solve(row+1,col,n,m,l)
        l[row][col]=right+down
        return l[row][col]

    def uniquePaths(self, n: int, m: int) -> int:
        l=[[-1]*(m+1) for _ in range(n+1)]
        return self.solve(1,1,n,m,l)

        