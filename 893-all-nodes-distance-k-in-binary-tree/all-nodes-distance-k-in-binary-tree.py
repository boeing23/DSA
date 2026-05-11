# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:


        #this ones easy you create a adj list 
        


        q=deque()


        q.append((root,None))

        adj=defaultdict(list)


        while q:

            node,parent=q.popleft()

            if parent:

                adj[node].append(parent)
                adj[parent].append(node)

            if node.left:
                q.append((node.left,node))
            if node.right:
                q.append((node.right,node))

        #this creates the adj list now let's traverse this

        #okay now traversing will be bit tricky

        # dfs is basically do gown the rabbit hole


        visited=set()
        ans=[]

        def dfs(node,dist):

            if not node:
                return
            if node in visited:
                return
            if dist==k:
                ans.append(node.val)
            visited.add(node)

            for nei in adj[node]:
                dfs(nei,dist+1)
        dfs(target,0)
        return ans

            


        
        






