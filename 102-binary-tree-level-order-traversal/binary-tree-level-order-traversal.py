# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res=[]
        q=deque()
        if(root is None):
            return res
        q.append(root)
        q.append(None)
        res=[]
        temp=[]
        while(len(q)>0):
            if(q[0] is None):
                res.append(temp)
                temp=[]
                q.popleft()
                if(len(q)>=1):
                    q.append(None)
                continue
            x=q.popleft()
            temp.append(x.val)
            if(x.left is not None):
                q.append(x.left)
            if(x.right is not None):
                q.append(x.right)  
        return res

        