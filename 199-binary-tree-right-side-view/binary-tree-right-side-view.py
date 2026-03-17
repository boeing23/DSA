# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        res=[]
        def dfs(node,depth)->None:
            if not node:
                return
            if depth==len(res):
                res.append(node.val)
            depth+=1
            dfs(node.right,depth)
            dfs(node.left,depth)


        # this is a level order traversal question

        dfs(root,0)
        return res
        