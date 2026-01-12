class Solution:
    def numDecodings(self, s: str) -> int:

        dp={}

        def dfs(idx:int)->int:

            if idx==len(s):
                return 1
            if s[idx]=='0':
                return 0
            if idx in dp:
                return dp[idx]
            res=0

            res+=dfs(idx+1)

            if idx<len(s)-1:
                if s[idx]=='1' or  (s[idx]=='2' and s[idx+1]<'7'):
                    res+=dfs(idx+2)
            dp[idx]=res
            return dp[idx]
        return dfs(0)

        