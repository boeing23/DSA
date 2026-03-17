# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        path=[]
        res=[]

        def dfs(node,path,remaining):
            if not node:
                return
            if not node.left and not node.right and remaining==node.val:
                res.append(path+[node.val])
            dfs(node.left, path+[node.val], remaining-node.val)
            dfs(node.right, path+[node.val], remaining-node.val)
        dfs(root, path, targetSum)
        return res



        