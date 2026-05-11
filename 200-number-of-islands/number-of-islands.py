class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:


        q=deque()
        islands=0

        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c]=='1':
                    islands+=1
                    q.append([r,c])
                    grid[r][c]='0'

                    while q:

                        row,col=q.popleft()

                        # grid[row][col]='0'

                        for dr,dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                            nr=row+dr
                            nc=col+dc

                            if 0<=nr<len(grid) and 0<=nc<len(grid[0]) and grid[nr][nc]=='1':
                                grid[nr][nc]='0'
                                q.append([nr,nc])
        return islands




        