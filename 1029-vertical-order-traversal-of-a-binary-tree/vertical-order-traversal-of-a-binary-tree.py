# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def height(self,root):
        if(root is None):
            return 0
        l=self.height(root.left)
        r=self.height(root.right)
        return 1+max(l,r)
    def solve(self,root,ind,res):
        if(root is None):
            return 
        res[ind].append(root.val)
        self.solve(root.right,ind+1,res)
        self.solve(root.left,ind-1,res)
    def bfs(self,root,ind,res):
        if (root is None):
            return []
        q=deque()
        q.append([root,ind,1])
        while(q):
            rt,idx,lvl=q.popleft()
            res[idx].append([lvl,rt.val])
            if(rt.left is not None):
                q.append([rt.left,idx-1,lvl+1])
            if(rt.right is not None):
                q.append([rt.right,idx+1,lvl+1])
                    
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        r=self.height(root.right)
        l=self.height(root.left)
        
        res=[[] for _ in range(100000)]
        # self.solve(root,l,res)
        self.bfs(root,10000,res)
        res=[x for x in res if x != []]
        for x in res:
            x.sort()
            for i in range(len(x)):
                x[i] = x[i][1]
        return res


        