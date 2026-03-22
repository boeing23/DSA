# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:

        # hya madhe tar left nd right madhe jaa and check kar heigh kuthe jyast aahe
        # i cannot do top down because i do not know which side to go for maximizing
        maxD=[0]*1
        maxD[0]=0
        def dfs(node):
            #mala hyat each child varu varti kahi tari send karaycha aahe
            if not node:
                return 0
            left=dfs(node.left)
            right=dfs(node.right)

            maxD[0]=max(left+right,maxD[0])
            
            return 1+max(left,right)


        dfs(root)
        return maxD[0]
        