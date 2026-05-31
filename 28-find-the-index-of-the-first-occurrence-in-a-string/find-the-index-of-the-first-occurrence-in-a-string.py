class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        l=0
        n=len(haystack)
        for r in range(n):
            if r-l+1==len(needle):
                if haystack[l:r+1]==needle:
                    return l
                l+=1
        return -1
