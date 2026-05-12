# class DSU:
#     def __init__(self, size:int):
#         self.parent=[-1 for _ in range(size)]
#         selfrank=[0 for _ in range(size)]

#     def exist(self,)

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:


        provinces=len(isConnected)

        # m=isConnected


        parent=[i for i in range(len(isConnected))]

        rank=[0 for _ in range(len(isConnected))]

        def find(x):
            if parent[x]!=x:
                parent[x]=find(parent[x])
            return parent[x]

        def union(a,b):
            root_a=find(a)
            root_b=find(b)


            if root_a==root_b:
                return 0

            if rank[root_a]<rank[root_b]:
                parent[root_a]=root_b
            elif rank[root_b]<rank[root_a]:
                parent[root_b]=root_a
            else:
                rank[root_a]+=1
                parent[root_b]=root_a

            return 1


        for r in range(len(isConnected)):
            for c in range(len(isConnected[0])):
                if isConnected[r][c]==1:
                    provinces-=union(r,c)
        return provinces




        
        