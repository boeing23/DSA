# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:


        
        dp=defaultdict(int)
        def dfs(node)->int:
            if not node:
                return 0
            if node in dp:
                return dp[node]
            
            robbed=node.val

            if node.left:
                robbed+=dfs(node.left.left)+dfs(node.left.right)
            if node.right:
                robbed+=dfs(node.right.right)+dfs(node.right.left)
            skip=dfs(node.left)+dfs(node.right)

            dp[node]=max(robbed,skip)

            return dp[node]

            




        return dfs(root)
        