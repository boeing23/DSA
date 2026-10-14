class Solution:
    def shortestPath(self, grid: list[list[int]], k: int) -> int:
        # basically in this each path you take you will have to see for that
        # path how many obstacles where destroyed

        queue=deque([(0,0,0,0)])

        visited={(0,0,0)}
        rows=len(grid)
        cols=len(grid[0])

        while queue:
            r,c,steps, destroyed=queue.popleft()

            if r==rows-1 and c == cols-1:
                return steps
            for dr,dc in [[1,0],[-1,0],[0,1],[0,-1]]:
                nr = dr+r
                nc = dc+c

                if not (0<=nr<rows and 0<=nc<cols):
                    continue
                # where can I store step, destroyed. queue has the path which it 
                # has to fo
                

                new_d=destroyed+grid[nr][nc]

                if new_d>k:
                    continue
                state=(nr,nc, new_d)

                if state in visited:
                    continue
                queue.append((nr,nc,steps+1, new_d))
                visited.add((nr,nc, new_d))
        return -1

                

