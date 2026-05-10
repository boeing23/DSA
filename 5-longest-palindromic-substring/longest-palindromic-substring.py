class Solution:
    def longestPalindrome(self, s: str) -> str:

        maxL=0
        res=[-1,-1]
        
        for i in range(len(s)):

            l=i
            r=i


            while l>=0 and r<len(s) and (s[l]==s[r]):

                if r-l+1>maxL:
                    res=[l,r]
                    maxL=max(maxL,r-l+1)


                l-=1
                r+=1

            l=i
            r=i+1

            while l>=0 and r<len(s) and (s[l]==s[r]):
                if r-l+1>maxL:
                    res=[l,r]
                    maxL=max(maxL,r-l+1)
                l-=1
                r+=1
        l,r=res
        return s[l:r+1]

        