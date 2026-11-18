class Solution:
    def solve(self,row,col,l,grid):
        m=len(grid[0])
        n=len(grid)
        if(row==n-1 and col==m-1):
            return grid[row][col]
        if(row>=n or col>=m):
            return 1e9
        if(l[row][col]!=-1):
            return l[row][col]
        right=self.solve(row,col+1,l,grid)
        bottom=self.solve(row+1,col,l,grid)
        l[row][col]=grid[row][col]
        if(right!=1e9 or bottom!=1e9):
            l[row][col]+=min(right,bottom)
        return l[row][col]

    def minPathSum(self, grid: list[list[int]]) -> int:
        m=len(grid[0])
        n=len(grid)
        l=[[-1]*(m+1) for _ in range(n+1)]

        return self.solve(0,0,l,grid)