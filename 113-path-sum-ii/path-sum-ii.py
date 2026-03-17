# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:

        # basically in this you have to take a path and if the pathsum==0 then 
        # add that path to the result
        # now here too you go to each node and append the path
        # so in this question the catch is if you append it early on then you pass the 
        # mutated value to the recursive call
        path=[]
        res=[]

        def dfs(node,remaining,path):
            if not node:
                return 0
            if not node.left and not node.right and remaining==node.val:
                res.append(path+[node.val])
                print(path)
            dfs(node.left,remaining-node.val, path+[node.val])

            
            dfs(node.right,remaining-node.val, path+[node.val])
        dfs(root, targetSum, path)
        return res
        