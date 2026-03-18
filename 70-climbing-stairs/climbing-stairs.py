class Solution:
    def climbStairs(self, n: int) -> int:
        #dfs i will have to do, it could b

        dp=defaultdict(int)


        def dfs(i)->int:
            if i==0:
                return 1
            if i<0:
                return 0
            if i in dp:
                return dp[i]
            dp[i]=dfs(i-1) + dfs(i-2)
            return dp[i]
        return dfs(n)
        
            

        