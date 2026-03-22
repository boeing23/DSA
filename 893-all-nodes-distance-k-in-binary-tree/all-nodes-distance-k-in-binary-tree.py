# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:

        # basically in this question to get the node aove you just have tp create a undirected graph
        # storing the parent node and the child nodes adjacent to it

        adj=defaultdict(list)

        q=deque()
        q.append((root,None))

        while q:

            node,parent=q.popleft()

            if parent:
                adj[node].append(parent)
                adj[parent].append(node)
            if node.left:
                q.append((node.left,node))
            if node.right:
                q.append((node.right,node))
        g=deque()


        g.append(target)
        visited=set()
        visited.add(target)
        lvl=0
        # if visited i cannot go again there


        while g:
            
            if lvl==k:
                res=[]
                for node in g:
                    res.append(node.val)
                return res

            for _ in range(len(g)):
                node=g.popleft()
            
                

                for nei in adj[node]:
                    if nei not in visited:
                        visited.add(nei)
                        g.append(nei)
            lvl+=1
        return []
                    

        