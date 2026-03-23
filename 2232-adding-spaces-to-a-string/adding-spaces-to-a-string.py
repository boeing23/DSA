class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:

        index=0
        ans=""

        for i in range(len(s)):
            if index<len(spaces) and i==spaces[index]:
                ans+=" "
                index+=1
            ans+=s[i]
        return ans

        