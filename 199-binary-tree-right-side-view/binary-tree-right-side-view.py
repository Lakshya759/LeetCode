# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self,root,res):
        if(root is None):
            return
        # res.append(root.val)
        # if(root.right is not None):
        #     self.solve(root.right,res)
        # else:
        #     self.solve(root.left,res)
        q=deque()
        q.append(root)
        q.append(None)

        while(len(q)>0):
            if(q[0] is None):
                if(len(q)>1):
                    q.append(None)
                q.popleft()
                continue
            if(q[1] is None):
                res.append(q[0].val)
            
            if(q[0].left is not None):
                q.append(q[0].left)
            if(q[0].right is not None):
                q.append(q[0].right)
            q.popleft()
        
            

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res=[]
        self.solve(root,res)
        return res


        