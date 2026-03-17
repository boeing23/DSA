class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        #basically first find all the rotten oranges and start rotting from there

        row=len(grid)
        col=len(grid[0])
        q=deque()
        fresh=0
        rotten=0
        directions=[[1,0],[-1,0],[0,1],[0,-1]]
        for r in range(row):
            for c in range(col):
                if grid[r][c]==2:
                    q.append([r,c])
                    rotten+=1
                if grid[r][c]==1:
                    fresh+=1
        time=0
        while fresh!=0 and q:
            l=len(q)
            for i in range(l):
                node=q.popleft()
                for r,c in directions:
                    nr=node[0]+r
                    nc=node[1]+c
                    if nr in range(len(grid)) and nc in range(len(grid[0])) and grid[nr][nc]==1:
                        grid[nr][nc]=2
                        q.append([nr,nc])
                        rotten+=1
                        fresh-=1
            time+=1
        return time if fresh==0 else -1


        

        