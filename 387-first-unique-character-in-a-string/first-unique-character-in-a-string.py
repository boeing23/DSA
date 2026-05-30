class Solution:
    def firstUniqChar(self, s: str) -> int:
        frqList=[0]*26

        for c in s:
            frqList[ord(c)-ord('a')]+=1

        #now i have to return the first character which i
        sLen=len(s)
        for i in range(sLen):
            if frqList[ord(s[i])-ord('a')]==1:
                return i
        return -1