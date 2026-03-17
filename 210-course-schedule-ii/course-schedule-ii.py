class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj=[[] for i in range(numCourses)]
        indegree=[0]*numCourses
        for dst,src in prerequisites:
            indegree[dst]+=1
            
            adj[src].append(dst)
        q=deque()
        for i in range(numCourses):
            if indegree[i]==0:
                q.append(i)
             
                
        ans=[]
        finish=0
        while q:
            node=q.popleft()

            ans.append(node)
            print(ans)
            finish+=1
            for nei in adj[node]:
                indegree[nei]-=1
                if indegree[nei]==0:
                    q.append(nei)
        return ans if finish==numCourses else []
            