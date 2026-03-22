# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        #min majha left asnar and max majha right

        def dfs(node,max_val,min_val)->bool:
            if not node:
                return True
            if node.val<=min_val or node.val>=max_val:
                return False
            return dfs(node.left,node.val,min_val) and dfs(node.right,max_val,node.val)


        return dfs(root,float('inf'),float('-inf'))
        