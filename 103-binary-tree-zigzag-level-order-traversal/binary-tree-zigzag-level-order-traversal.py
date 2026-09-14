# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        s1=[]
        s2=[]
        res=[]
        if(root is not None):
            s1.append(root)
        while(len(s1)>0 or len(s2)>0):
            temp=[]
            while(len(s1)>0):
                temp.append(s1[-1].val)
                if(s1[-1].left is not None):
                    s2.append(s1[-1].left)
                if(s1[-1].right is not None):
                    s2.append(s1[-1].right)
                s1.pop()
            if(len(temp)>0):    
                res.append(temp)
            temp=[]
            while(len(s2)>0):
                temp.append(s2[-1].val)
                if(s2[-1].right is not None):
                    s1.append(s2[-1].right)
                if(s2[-1].left is not None):
                    s1.append(s2[-1].left)
                s2.pop()
            if(len(temp)>0):    
                res.append(temp)
        return res
            

            

        