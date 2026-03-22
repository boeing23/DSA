# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        # ha level order traversal ni karto

        # basically left pasna add karat jaa then jo last asnar to ans
        if not root:
            return []

        q=deque()

        q.append(root)
        ans=[]

        while q:
            l=len(q)
            r=0
            for i in range(l):
                node=q.popleft()

                r=node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(r)
        return ans
                


        