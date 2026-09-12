# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self,root:Optional[TreeNode],res:List[int]):
        if(root is None):
            return
        res.append(root.val)
        self.traversal(root.left,res)
        self.traversal(root.right,res)


    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res=[]
        st=[]
        if(root is not None):
            st.append(root)
        while(len(st)>0):
            rt=st.pop()
            res.append(rt.val)
            if(rt.right is not None):
                st.append(rt.right)
            if(rt.left is not None):
                st.append(rt.left)
        return res

        