class Solution:
    def numDecodings(self, s: str) -> int:

        # so there could be multiple ways to decode a string
        # in one you can take a single digit or take a doublt digit
        # and the val of double should not be > 26

        # ways variable
        # traverse the string
        dp=defaultdict(int)
        def dfs(index:int):
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
        
        
        