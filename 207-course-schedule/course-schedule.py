class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:


        # indegree tells us inward nodes and how many are coming inside
        # visited would 

        # indegree is basically

        adj=defaultdict(list)

        indegree=[0 for _ in range(numCourses)]

        #now the task is to form an adj list which tells you the nei

        #[0 1] 1 > 0 and 1's indegree is 1

        for a,b in prerequisites:
            adj[b].append(a)
            indegree[a]+=1

        q=deque() #it is for tracking courses with 0 prereq so we finish those first

        for i in range(numCourses):
            if indegree[i]==0:
                q.append(i)

        #now let's finish all 0 prereq courses

        completed=0

        while q:

            curr=q.popleft()

            completed+=1
            

            for nei in adj[curr]:
                indegree[nei]-=1

                if indegree[nei]==0:
                    q.append(nei)
        return completed==numCourses



            
            




        

