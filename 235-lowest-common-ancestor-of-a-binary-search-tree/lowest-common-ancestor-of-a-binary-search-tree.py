# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        # basically in this i know which side to look for, i mean

        def dfs(node,p,q):
            if not node:
                return None

            if node.val>p.val and node.val>q.val:
                return dfs(node.left,p,q)
            if node.val<p.val and node.val<q.val:
                return dfs(node.right,p,q)


            return node


        return dfs(root,p,q)

        