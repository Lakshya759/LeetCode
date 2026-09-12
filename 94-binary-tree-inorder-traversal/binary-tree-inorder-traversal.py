# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self,root,res):
        if(root is None):
            return
        self.traversal(root.left,res)
        res.append(root.val)
        self.traversal(root.right,res)
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res=[]
        st=[]

     
        while((root is not None) or len(st)>0):
            while(root is not None):
                st.append(root)
                root=root.left
            root=st.pop()
            res.append(root.val)
            
            root=root.right

        return res

        

        