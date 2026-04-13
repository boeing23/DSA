class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        #directions=[[1,0],[0,1]]

        


            # the goal state is basically if you reach the goal which is 

            # current m == len(grid)-1 and n=len(grid[0])-1:
            # return 1

            # now here you have two options
            # either go down or go left
            # the children will return the max of either location so 

            # will i have to maintain a visited thing idts as i cannot go back



            # return max(dfs(righ), down)

            #now dp can store the 
        dp=defaultdict(int)
        def dfs(row,col)->int:

            if row==m-1 and col==n-1:
                return 1
            if row> m-1 or col>n-1:
                return 0
            if (row,col) in dp:
                return dp[(row,col)]

            dp[(row,col)] = dfs(row+1,col)+ dfs(row,col+1)

            return dp[(row,col)]


        return dfs(0,0)
        