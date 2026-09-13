# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res=0
    def solve(self,root):
        if(root is None):
            return [0,0]
        [maxl,l]=self.solve(root.left)
        [maxr,r]=self.solve(root.right)
        return [max(maxl,max(maxr,l+r)),max(l,r)+1]
    def solve1(self,root):
        if(root is None):
            return 0
        l=self.solve1(root.left)
        r=self.solve1(root.right)
        self.res=max(self.res,l+r)
        return max(l,r)+1
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # [maxi,height]=self.solve(root)
        # return maxi
        self.solve1(root)
        return self.res
        