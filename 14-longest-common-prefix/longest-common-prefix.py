class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:


        # this questions is like this take first word and consider it is a prefix
        # traverse the list and see here prefix will be 

        # then get to that word and keep moving your i until the chars match


        prefix=strs[0]

        for i in range(1,len(strs)):

            current_word=strs[i]
            l=0

            while l<min(len(prefix),len(current_word)):
                if current_word[l]!=prefix[l]:
                    break
                l+=1
            prefix=prefix[:l]
        return prefix

        