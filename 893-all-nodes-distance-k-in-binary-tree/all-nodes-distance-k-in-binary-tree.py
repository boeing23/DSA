# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        adj=defaultdict(list)

        def dfs(parent, node):
            if not node:
                return
            if not parent:
                if node.left:
                    adj[node].append(node.left)
                if node.right:
                    adj[node].append(node.right)
            else:
                adj[node].append(parent)
                if node.left:
                    adj[node].append(node.left)
                if node.right:
                    adj[node].append(node.right)
            dfs(node,node.left)
            dfs(node,node.right)





        dfs(None, root)
        visited=set()
        ans=[]
        

        def dfsnei(node,distance):


            if distance==k:
                ans.append(node.val)
            visited.add(node)

            for nei in adj[node]:
                if nei not in visited:
                    visited.add(nei)
                    
                    dfsnei(nei,distance+1)
            #visited.remove(node)

                
            

        dfsnei(target,0)
        return ans

        