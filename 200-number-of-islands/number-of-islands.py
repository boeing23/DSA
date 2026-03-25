class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:


        # now in this we are supposed to mark the islands and get total
        # islands in this

        # one way to do it could be a dfs approach, where we start from an island
        # which is 1 and then from there we do a dfs and whichever are the connected ones
        # we mark them '0' so that the we don't recount that piece of land again


        # now what would be the tc and sc for this.

        # as we are doing a dfs the tc would be n*n as we are visiting each and every land
        # then space complexity be constant as we are not using an extra space here
        # as we just update the matrix in the place

        def depthfirstsearch(r: int,c: int)->None:
            # base cases will basically keep track of boundary so that we don
            # t go out of bounds and we also check if the new one which has come it is a land   
            if 0>r or r>=len(grid) or 0>c or c>=len(grid[0]) or grid[r][c]!='1':
                return
            grid[r][c]='0'

            for nr,nc in directions:
                newR=r+nr
                newC=c+nc

                if 0<=newR<len(grid) and 0<=newC<len(grid[0]) and grid[newR][newC]=='1':
                    depthfirstsearch(newR,newC)
            



        rows= len(grid)
        cols=len(grid[0])
        islands=0 # for counting number of islands
        directions=[[1,0],[-1,0],[0,1],[0,-1]]

        for r in range(rows):
            for c in range(cols):
                # you do a dfs only when you encounter a land

                if grid[r][c]=='1':
                    depthfirstsearch(r,c)
                    islands+=1     #whenever we come out of the call we have marked the connected lands and it forms a single island

        return islands

        