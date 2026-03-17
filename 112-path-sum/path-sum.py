# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:

        # so basically in this question you have to check if the path sum adds up to the target or not
        # each node has it's own copy of target

        # so the trick is khudka karo and aage badho

        def dfs(node,remaining)->bool:
            if not node:
                return False
            remaining-=node.val
            if not node.left and not node.right and remaining==0:
                return True
            print(remaining)
            return dfs(node.left, remaining) or dfs(node.right, remaining)
        return dfs(root,targetSum)

       
        