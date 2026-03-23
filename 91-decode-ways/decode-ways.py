class Solution:
    def numDecodings(self, s: str) -> int:


        # this is basically a typical take not take question for each step i have to store the possible outcome


        # base condn=

        # if i>=len(s):
        #     return 1      # it means if the goal state reached that means you have arrived to the soln

        # if s[i]=='0':
        #     return 0
        # take1=dfs(i+1)

        # if s[i]==2 and s[i]<7:
        #     take+=dfs(i+2)
        # return 

        dp=defaultdict(int)

        def dfs(index):
            if index==len(s):
                return 1
            if s[index]=='0':
                return 0
            if index in dp:
                return dp[index]
            dp[index]+=dfs(index+1)

            if index<len(s)-1:
                if s[index]=='1' or (s[index]=='2' and s[index+1]<'7'):
                    dp[index]+=dfs(index+2)
            return dp[index]
        return dfs(0)




        
        
        