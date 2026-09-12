# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self,root):
        if(root is None):
            return [0,True]
        [ls,lt]=self.solve(root.left)
        [rs,rt]=self.solve(root.right)
        if(not (lt and rt)):
            return [0,False]
        if(abs(ls-rs)<=1):
            return [max(ls,rs)+1,True]
        return [0,False]
        
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        res=self.solve(root)
        return res[1]        