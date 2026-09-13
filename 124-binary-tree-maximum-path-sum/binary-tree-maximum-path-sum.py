# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res=-10000000
    def solve(self,root):
        if(root is None):
            return 0
        self.res=max(self.res,root.val)
        l=self.solve(root.left)
        r=self.solve(root.right)
        y=root.val
        x=root.val
        if(l>0):
            y+=l
        if(r>0):
            y+=r
        if(max(l,r)>0):
            x=max(l,r)+root.val
        
        

        self.res=max(self.res,max(x,y))
        return x
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.solve(root)
        return self.res
        