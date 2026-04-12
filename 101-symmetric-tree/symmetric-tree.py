# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:


        def dfs(p,q)->bool:
            
            if not p and not q:
                return True
            if p and not q or not p and q:
                return False
            if p.val!=q.val:
                return False
            return dfs(p.left,q.right) and dfs(p.right,q.left)


        return dfs(root.left,root.right)
        