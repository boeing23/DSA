# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:

        counter=[0]*1
        counter[0]= k
        res=[0]*1
        res[0]=0
        def dfs(node):
            if not node:
                return
            
            #if not node.left and not node.right and counter[0]==0:
            dfs(node.left)
            counter[0]-=1
            if counter[0]==0:
                res[0]=node.val
            dfs(node.right)
        dfs(root)
        return res[0]

            



        