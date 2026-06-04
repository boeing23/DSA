# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        # basically i have to find all the increasing nodes from node to whatever path, so i need to keep a running maximum, in order to do it
        # i start at the root then go left or right, and I check if it is bigger
        # than the current max, if it is then increase the count
        # and mark it as currMax
        count=[0]
        

        def dfs(node,currMax):

            if not node:
                return
            if node.val>=currMax:
                count[0]+=1
                
            dfs(node.left,max(currMax,node.val))
            dfs(node.right,max(currMax,node.val))
        dfs(root,root.val)
        return count[0]



        