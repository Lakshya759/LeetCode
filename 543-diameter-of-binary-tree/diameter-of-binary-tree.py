# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self,root):
        if(root is None):
            return [0,0]
        [maxl,l]=self.solve(root.left)
        [maxr,r]=self.solve(root.right)
        return [max(maxl,max(maxr,l+r)),max(l,r)+1]
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        [maxi,height]=self.solve(root)
        return maxi
        