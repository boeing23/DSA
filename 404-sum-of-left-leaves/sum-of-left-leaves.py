# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:


        def dfs(node):

            if not node:
                return 0

            total=0
            if node.left:
                if not node.left.left and not node.left.right:
                    total+=node.left.val
                else:
                    total+=dfs(node.left)
            if node.right:
                total+=dfs(node.right)
            return total
        return dfs(root)


        