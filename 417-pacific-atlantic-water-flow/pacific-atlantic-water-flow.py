class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows=len(heights)
        cols=len(heights[0])


        atl=[[False]*cols for _ in range(rows)]
        pac= [[False]*cols for _ in range(rows)]


        # now start from any cell and traverse and mark it true only if the neihboring
        # cell has height more than current one
        def dfs(row,col,ocean):
            ocean[row][col]=True

            for dr,dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                nr=row+dr
                nc=col+dc

                if 0<=nr<rows and 0<=nc<cols and not ocean[nr][nc] and heights[nr][nc]>=heights[row][col]:
                    dfs(nr,nc,ocean)

        for c in range(cols):

            dfs(0,c,pac)
            dfs(rows-1,c,atl)
        for r in range(rows):

            dfs(r,0,pac)
            dfs(r,cols-1,atl)
        res=[]
        for r in range(rows):
            for c in range(cols):
                if atl[r][c] and pac[r][c]:
                    res.append([r,c])

        return res

        